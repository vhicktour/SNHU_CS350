/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== gpiointerrupt.c ========
 */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>  // Fix for 'strlen' undeclared error
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/UART2.h>  // Fix for 'UART2_init' undeclared error
#include "ti_drivers_config.h"

// Global variables
volatile unsigned char TimerFlag = 0;
int16_t roomTemperature = 25;  // Example starting temperature
int16_t setPointTemperature = 22;  // Default set point
int32_t secondsSinceReset = 0;
I2C_Handle i2c;
UART2_Handle uart;
Timer_Handle timer0;
uint8_t txBuffer[1];
uint8_t rxBuffer[2];
I2C_Transaction i2cTransaction;

// Task scheduler intervals (in microseconds)
#define CHECK_BUTTON_INTERVAL 200000  // 200ms
#define CHECK_TEMP_INTERVAL 500000    // 500ms
#define UPDATE_LED_INTERVAL 1000000   // 1 second

// I2C sensor data
static const struct {
    uint8_t address;
    uint8_t resultReg;
    char *id;
} sensors[3] = {
    {0x48, 0x00, "11X"},
    {0x49, 0x00, "116"},
    {0x41, 0x01, "006"}
};

// Timer callback function
void timerCallback(Timer_Handle myHandle, int_fast16_t status) {
    TimerFlag = 1;
}

// Initialize the timer
void initTimer(void) {
    Timer_Params params;
    Timer_init();
    Timer_Params_init(&params);
    params.period = 1000000;  // 1 second period for the callback
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;

    timer0 = Timer_open(CONFIG_TIMER_0, &params);
    if (timer0 == NULL) {
        while (1) {}  // Error: failed to initialize timer
    }

    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        while (1) {}  // Error: failed to start timer
    }
}

// Initialize I2C
void initI2C(void) {
    I2C_Params i2cParams;
    I2C_init();
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;
    i2c = I2C_open(CONFIG_I2C_0, &i2cParams);
    if (i2c == NULL) {
        while (1);  // Failed to initialize I2C
    }
}

// Read temperature from sensor via I2C
int16_t readTemp(void) {
    int16_t temperature = 0;
    i2cTransaction.readCount = 2;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        temperature = (rxBuffer[0] << 8) | (rxBuffer[1]);
        temperature *= 0.0078125;  // Convert to Celsius
        if (rxBuffer[0] & 0x80) {
            temperature |= 0xF000;  // Handle negative temperature
        }
    }
    return temperature;
}

// I2C address scanning
void scanI2CAddresses() {
    printf("Scanning I2C addresses...\n");
    for (uint8_t i = 0x03; i <= 0x77; i++) {
        i2cTransaction.targetAddress = i;  // Fix for 'slaveAddress' error
        i2cTransaction.writeBuf = txBuffer;
        i2cTransaction.writeCount = 0;
        i2cTransaction.readBuf = rxBuffer;
        i2cTransaction.readCount = 0;

        if (I2C_transfer(i2c, &i2cTransaction)) {
            printf("I2C device found at address 0x%02X\n", i);
        }
    }
    printf("I2C scan complete.\n");
}

// Initialize UART2
void initUART2(void) {
    UART2_Params uartParams;
    //UART2_open();  // Fix for 'UART2_init' undeclared error
    UART2_Params_init(&uartParams);
    uartParams.baudRate = 115200;
    uart = UART2_open(CONFIG_UART2_0, &uartParams);
    if (uart == NULL) {
        while (1);  // Failed to initialize UART2
    }
}

// UART output function
void uartPrint(const char *format, ...) {
    char output[64];
    va_list args;
    va_start(args, format);
    vsnprintf(output, sizeof(output), format, args);
    va_end(args);

    // Append a newline + carriage return to ensure proper formatting
    strcat(output, "\r\n");

    UART2_write(uart, output, strlen(output), NULL);  // Fix for 'strlen' undeclared error
}

// Button 0 (increase temperature) interrupt handler
void gpioButtonFxn0(uint_least8_t index) {
    setPointTemperature++;
}

// Button 1 (decrease temperature) interrupt handler
void gpioButtonFxn1(uint_least8_t index) {
    setPointTemperature--;
}

// Main thread function
void *mainThread(void *arg0) {
    GPIO_init();
    initUART2();
    initI2C();
    initTimer();

    // GPIO configurations for LED and buttons
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_BUTTON_0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    GPIO_setConfig(CONFIG_GPIO_BUTTON_1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

    // Button callback setup
    GPIO_setCallback(CONFIG_GPIO_BUTTON_0, gpioButtonFxn0);
    GPIO_setCallback(CONFIG_GPIO_BUTTON_1, gpioButtonFxn1);

    // Enable interrupts for buttons
    GPIO_enableInt(CONFIG_GPIO_BUTTON_0);
    GPIO_enableInt(CONFIG_GPIO_BUTTON_1);

    // I2C device scanning
    scanI2CAddresses();

    // Main loop
    while (1) {
        if (TimerFlag) {
            TimerFlag = 0;
            roomTemperature = readTemp();

            // Update LED based on temperature vs set-point
            if (roomTemperature < setPointTemperature) {
                GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);  // Heat on
            } else {
                GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);  // Heat off
            }

            // Send data via UART2
            uartPrint("<%02d,%02d,%d,%04d>\n", roomTemperature, setPointTemperature,
                      (roomTemperature < setPointTemperature) ? 1 : 0, secondsSinceReset);

            // Increment time
            secondsSinceReset++;
        }
    }

    return NULL;
}

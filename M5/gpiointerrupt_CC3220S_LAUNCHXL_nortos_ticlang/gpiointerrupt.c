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

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>

/* Driver configuration */
#include "ti_drivers_config.h"

/* Morse code message states */
enum CURRENT_MESSAGES {SOS_MESSAGE, OK_MESSAGE} CURRENT_MESSAGE, BUTTON_STATE;

/* LED code states */
enum LED_STATES {LED_RED, LED_GREEN, LED_OFF} LED_STATE;

/* Morse messages */
enum LED_STATES sosMessage[] = {
    /* S */
    LED_RED, LED_OFF,                                               // DOT, break
    LED_RED, LED_OFF,                                               // DOT, break
    LED_RED, LED_OFF, LED_OFF, LED_OFF,                             // DOT, character break
    /* O */
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF,                       // DASH, break
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF,                       // DASH, break
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF, LED_OFF, LED_OFF,     // DASH, character break
    /* S */
    LED_RED, LED_OFF,                                               // DOT, break
    LED_RED, LED_OFF,                                               // DOT, break
    LED_RED,                                                        // DOT, character break
    LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF   // Word break
};

enum LED_STATES okMessage[] = {
    /* O */
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF,                       // DASH, break
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF,                       // DASH, break
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF, LED_OFF, LED_OFF,     // DASH, character break
    /* K */
    LED_GREEN, LED_GREEN, LED_GREEN, LED_OFF,                       // DASH, break
    LED_RED, LED_OFF,                                               // DOT, break
    LED_GREEN, LED_GREEN, LED_GREEN,                                // DASH
    LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF   // Word break
};

/* Message counter, initialized to zero. */
unsigned int messageCounter = 0;

/*
 *  ======== setMorseLEDs ========
 *  Function for the LEDs to represent a dot, dash, or break.
 */
void setMorseLEDs() {
    switch(LED_STATE) {
        case LED_RED:   // DOT
            GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
            GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);
            break;
        case LED_GREEN: // DASH
            GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
            GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);
            break;
        case LED_OFF:   // BREAK
            GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
            GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);
            break;
        default:
            break;
    }
}

/*
 *  ======== timerCallback ========
 *  Callback function for the timer interrupt.
 */
void timerCallback(Timer_Handle myHandle, int_fast16_t status)
{
    switch(CURRENT_MESSAGE) {
        case SOS_MESSAGE:
            LED_STATE = sosMessage[messageCounter];

            setMorseLEDs();
            messageCounter++;

            if(messageCounter == (sizeof(sosMessage)/sizeof(sosMessage[0]))) {
                CURRENT_MESSAGE = BUTTON_STATE;
                messageCounter = 0;
            }
            break;
        case OK_MESSAGE:
            LED_STATE = okMessage[messageCounter];

            setMorseLEDs();
            messageCounter++;

            if(messageCounter == (sizeof(okMessage)/sizeof(okMessage[0]))) {
                CURRENT_MESSAGE = BUTTON_STATE;
                messageCounter = 0;
            }
            break;
        default:
            break;
    }
}

/*
 *  ======== initTimer ========
 *  Initialization function for the timer interrupt on timer0.
 */
void initTimer(void)
{
    Timer_Handle timer0;
    Timer_Params params;

    Timer_init();
    Timer_Params_init(&params);
    params.period = 500000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;

    timer0 = Timer_open(CONFIG_TIMER_0, &params);

    if(timer0 == NULL) {
        /* Failed to initialize timer */
        while (1) {}
    }

    if(Timer_start(timer0) == Timer_STATUS_ERROR)
    {
        /* Failed to start timer */
        while (1) {}
    }
}

/*
 *  ======== gpioButtonCallback ========
 *  Callback function for the GPIO interrupt for either CONFIG_GPIO_BUTTON_0 or CONFIG_GPIO_BUTTON_1.
 */
void gpioButtonCallback(uint_least8_t index)
{
    switch(BUTTON_STATE) {
        case SOS_MESSAGE:
            BUTTON_STATE = OK_MESSAGE;
            break;
        case OK_MESSAGE:
            BUTTON_STATE = SOS_MESSAGE;
            break;
        default:
            break;
    }
}

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* Call driver init functions for GPIO and timer */
    GPIO_init();
    initTimer();

    /* Configure the LED and button pins */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_BUTTON_0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

    /* Start with LEDs off */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
    GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);

    /* Set initial states to SOS_MESSAGE */
    BUTTON_STATE = SOS_MESSAGE;
    CURRENT_MESSAGE = BUTTON_STATE;

    /* Install Button callback */
    GPIO_setCallback(CONFIG_GPIO_BUTTON_0, gpioButtonCallback);

    /* Enable interrupts */
    GPIO_enableInt(CONFIG_GPIO_BUTTON_0);

    /*
     *  If more than one input pin is available for your device, interrupts
     *  will be enabled on CONFIG_GPIO_BUTTON1.
     */
    if (CONFIG_GPIO_BUTTON_0 != CONFIG_GPIO_BUTTON_1) {
        /* Configure BUTTON1 pin */
        GPIO_setConfig(CONFIG_GPIO_BUTTON_1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

        /* Install Button callback */
        GPIO_setCallback(CONFIG_GPIO_BUTTON_1, gpioButtonCallback);
        GPIO_enableInt(CONFIG_GPIO_BUTTON_1);
    }

    return (NULL);
}

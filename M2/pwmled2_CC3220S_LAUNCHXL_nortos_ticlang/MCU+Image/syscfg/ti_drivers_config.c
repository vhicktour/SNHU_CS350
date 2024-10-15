/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC3220S_LAUNCHXL
 *  by the SysConfig tool.
 */

#include <stddef.h>
#include <stdint.h>

#ifndef DeviceFamily_CC3220
#define DeviceFamily_CC3220
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC32XX.h>

/* The range of pins available on this device */
const uint_least8_t GPIO_pinLowerBound = 0;
const uint_least8_t GPIO_pinUpperBound = 32;

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[33] = {
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIOCC32XX_DO_NOT_CONFIG, /* Pin not available */
    GPIOCC32XX_DO_NOT_CONFIG, /* Pin not available */
    GPIOCC32XX_DO_NOT_CONFIG, /* Pin not available */
    GPIOCC32XX_DO_NOT_CONFIG, /* Pin not available */
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
    GPIO_CFG_INPUT | GPIOCC32XX_DO_NOT_CONFIG,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *  Change at runtime with GPIO_setCallback()
 */
GPIO_CallbackFxn gpioCallbackFunctions[33];

/*
 *  ======== gpioUserArgs ========
 *  Array of user argument pointers
 *  Change at runtime with GPIO_setUserArg()
 *  Get values with GPIO_getUserArg()
 */
void* gpioUserArgs[33];



/*
 *  ======== GPIO_config ========
 */
const GPIO_Config GPIO_config = {
    .configs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .userArgs = gpioUserArgs,
    .intPriority = (~0)
};

/*
 *  =============================== PWM ===============================
 */

#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerCC32XX.h>

#define CONFIG_PWM_COUNT 2

/*
 *  ======== pwmTimerCC32XXObjects ========
 */
PWMTimerCC32XX_Object pwmTimerCC32XXObjects[CONFIG_PWM_COUNT];

/*
 *  ======== pwmTimerCC32XXHWAttrs ========
 */
const PWMTimerCC32XX_HWAttrsV2 pwmTimerCC32XXHWAttrs[CONFIG_PWM_COUNT] = {
    /* CONFIG_PWM_0 */
    /* LaunchPad LED D9 (Yellow) */
    {
        .pwmPin = PWMTimerCC32XX_PIN_01, /* 01 */
    },
    /* CONFIG_PWM_1 */
    /* LaunchPad LED D8 (Green) */
    {
        .pwmPin = PWMTimerCC32XX_PIN_02, /* 02 */
    },
};

/*
 *  ======== PWM_config ========
 */
const PWM_Config PWM_config[CONFIG_PWM_COUNT] = {
    /* CONFIG_PWM_0 */
    /* LaunchPad LED D9 (Yellow) */
    {
        .fxnTablePtr = &PWMTimerCC32XX_fxnTable,
        .object = &pwmTimerCC32XXObjects[CONFIG_PWM_0],
        .hwAttrs = &pwmTimerCC32XXHWAttrs[CONFIG_PWM_0]
    },
    /* CONFIG_PWM_1 */
    /* LaunchPad LED D8 (Green) */
    {
        .fxnTablePtr = &PWMTimerCC32XX_fxnTable,
        .object = &pwmTimerCC32XXObjects[CONFIG_PWM_1],
        .hwAttrs = &pwmTimerCC32XXHWAttrs[CONFIG_PWM_1]
    },
};

const uint_least8_t CONFIG_PWM_0_CONST = CONFIG_PWM_0;
const uint_least8_t CONFIG_PWM_1_CONST = CONFIG_PWM_1;
const uint_least8_t PWM_count = CONFIG_PWM_COUNT;

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC32XX.h>
#include <ti/devices/cc32xx/driverlib/prcm.h>

extern void PowerCC32XX_initPolicy(void);
extern void PowerCC32XX_sleepPolicy(void);
PowerCC32XX_ParkInfo parkInfo[];
/*
 *  This structure defines the configuration for the Power Manager.
 */
const PowerCC32XX_ConfigV1 PowerCC32XX_config = {
    .policyInitFxn             = PowerCC32XX_initPolicy,
    .policyFxn                 = PowerCC32XX_sleepPolicy,
    .enterLPDSHookFxn          = NULL,
    .resumeLPDSHookFxn         = NULL,
    .enablePolicy              = false,
    .enableGPIOWakeupLPDS      = true,
    .enableGPIOWakeupShutdown  = true,
    .enableNetworkWakeupLPDS   = true,
    .wakeupGPIOSourceLPDS      = PRCM_LPDS_GPIO13,
    .wakeupGPIOTypeLPDS        = PRCM_LPDS_FALL_EDGE,
    .wakeupGPIOFxnLPDS         = NULL,
    .wakeupGPIOFxnLPDSArg      = 0,
    .wakeupGPIOSourceShutdown  = PRCM_HIB_GPIO13,
    .wakeupGPIOTypeShutdown    = PRCM_HIB_RISE_EDGE,
    .ramRetentionMaskLPDS      = PRCM_SRAM_COL_1|PRCM_SRAM_COL_2|PRCM_SRAM_COL_3|PRCM_SRAM_COL_4,
    .latencyForLPDS            = 20000,
    .keepDebugActiveDuringLPDS = false,
    .ioRetentionShutdown       = PRCM_IO_RET_GRP_0|PRCM_IO_RET_GRP_1|PRCM_IO_RET_GRP_2|PRCM_IO_RET_GRP_3,
    .pinParkDefs               = parkInfo,
    .numPins                   = 31
};

#include <ti/drivers/power/PowerCC32XX.h>

/*
 * This table defines the parking state to be set for each parkable pin
 * during LPDS. (Device resources must be parked during LPDS to achieve maximum
 * power savings.)  If the pin should be left unparked, specify the state
 * PowerCC32XX_DONT_PARK.  For example, for a UART TX pin, the device
 * will automatically park the pin in a high state during transition to LPDS,
 * so the Power Manager does not need to explictly park the pin.  So the
 * corresponding entries in this table should indicate PowerCC32XX_DONT_PARK.
 */
PowerCC32XX_ParkInfo parkInfo[] = {
/*        PIN                    PARK STATE              Pin Alias
   -----------------  ------------------------------     ---------------*/

  {PowerCC32XX_PIN01, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP10 */
  {PowerCC32XX_PIN02, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP11 */
  {PowerCC32XX_PIN03, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP12 */
  {PowerCC32XX_PIN04, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP13 */
  {PowerCC32XX_PIN05, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP14 */
  {PowerCC32XX_PIN06, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP15 */
  {PowerCC32XX_PIN07, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP16 */
  {PowerCC32XX_PIN08, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP17 */
  {PowerCC32XX_PIN13, PowerCC32XX_WEAK_PULL_DOWN_STD},
  {PowerCC32XX_PIN15, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP22 */
  {PowerCC32XX_PIN16, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* TDI */
  {PowerCC32XX_PIN17, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* TDO */
  {PowerCC32XX_PIN18, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP28 */
  {PowerCC32XX_PIN19, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* TCK */
  {PowerCC32XX_PIN20, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* TMS */
  {PowerCC32XX_PIN21, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* SOP2 */
  {PowerCC32XX_PIN29, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP26 */
  {PowerCC32XX_PIN30, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP27 */
  {PowerCC32XX_PIN45, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP31 */
  {PowerCC32XX_PIN50, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP00 */
  {PowerCC32XX_PIN52, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP32 */
  {PowerCC32XX_PIN53, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP30 */
  {PowerCC32XX_PIN55, PowerCC32XX_WEAK_PULL_UP_STD},   /* GP01 */
  {PowerCC32XX_PIN57, PowerCC32XX_WEAK_PULL_UP_STD},   /* GP02 */
  {PowerCC32XX_PIN58, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP03 */
  {PowerCC32XX_PIN59, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP04 */
  {PowerCC32XX_PIN60, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP05 */
  {PowerCC32XX_PIN61, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP06 */
  {PowerCC32XX_PIN62, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP07 */
  {PowerCC32XX_PIN63, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP08 */
  {PowerCC32XX_PIN64, PowerCC32XX_WEAK_PULL_DOWN_STD},   /* GP09 */
};

#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    PRCMCC3200MCUInit();
    Power_init();

    /* ==== /ti/drivers/GPIO initialization ==== */
    /* Setup GPIO module and default-initialise pins */
    GPIO_init();

    Board_initHook();
}


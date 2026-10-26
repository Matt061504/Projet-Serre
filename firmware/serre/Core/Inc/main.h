/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "stm32g0xx_ll_adc.h"
#include "stm32g0xx_ll_dma.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_exti.h"
#include "stm32g0xx_ll_cortex.h"
#include "stm32g0xx_ll_utils.h"
#include "stm32g0xx_ll_pwr.h"
#include "stm32g0xx_ll_rtc.h"
#include "stm32g0xx_ll_tim.h"
#include "stm32g0xx_ll_usart.h"
#include "stm32g0xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_D5_Pin LL_GPIO_PIN_9
#define LCD_D5_GPIO_Port GPIOB
#define T_NRST_Pin LL_GPIO_PIN_2
#define T_NRST_GPIO_Port GPIOF
#define SOIL_Pin LL_GPIO_PIN_0
#define SOIL_GPIO_Port GPIOA
#define TEMP_Pin LL_GPIO_PIN_1
#define TEMP_GPIO_Port GPIOA
#define T_VCP_TX_Pin LL_GPIO_PIN_2
#define T_VCP_TX_GPIO_Port GPIOA
#define T_VCP_RX_Pin LL_GPIO_PIN_3
#define T_VCP_RX_GPIO_Port GPIOA
#define LUMI_Pin LL_GPIO_PIN_4
#define LUMI_GPIO_Port GPIOA
#define PUMP_IN1_Pin LL_GPIO_PIN_5
#define PUMP_IN1_GPIO_Port GPIOA
#define POT_LED_Pin LL_GPIO_PIN_6
#define POT_LED_GPIO_Port GPIOA
#define FAN_Pin LL_GPIO_PIN_7
#define FAN_GPIO_Port GPIOA
#define POT_SPECTRE_Pin LL_GPIO_PIN_0
#define POT_SPECTRE_GPIO_Port GPIOB
#define BTN_PLUS_Pin LL_GPIO_PIN_1
#define BTN_PLUS_GPIO_Port GPIOB
#define LCD_RS_Pin LL_GPIO_PIN_2
#define LCD_RS_GPIO_Port GPIOB
#define LCD_D4_Pin LL_GPIO_PIN_8
#define LCD_D4_GPIO_Port GPIOA
#define TIM1_CH2_Pin LL_GPIO_PIN_9
#define TIM1_CH2_GPIO_Port GPIOA
#define LED_USER_Pin LL_GPIO_PIN_6
#define LED_USER_GPIO_Port GPIOC
#define BTN_OK_Pin LL_GPIO_PIN_10
#define BTN_OK_GPIO_Port GPIOA
#define BTN_MINUS_Pin LL_GPIO_PIN_11
#define BTN_MINUS_GPIO_Port GPIOA
#define HEATER_Pin LL_GPIO_PIN_12
#define HEATER_GPIO_Port GPIOA
#define T_JTMS_Pin LL_GPIO_PIN_13
#define T_JTMS_GPIO_Port GPIOA
#define T_JTCK_Pin LL_GPIO_PIN_14
#define T_JTCK_GPIO_Port GPIOA
#define BTN_MODE_Pin LL_GPIO_PIN_15
#define BTN_MODE_GPIO_Port GPIOA
#define BTN_ECRAN_Pin LL_GPIO_PIN_3
#define BTN_ECRAN_GPIO_Port GPIOB
#define LCD_D7_Pin LL_GPIO_PIN_4
#define LCD_D7_GPIO_Port GPIOB
#define LCD_D6_Pin LL_GPIO_PIN_5
#define LCD_D6_GPIO_Port GPIOB
#define BTN_ARROSAGE_Pin LL_GPIO_PIN_6
#define BTN_ARROSAGE_GPIO_Port GPIOB
#define POT_TEMP_Pin LL_GPIO_PIN_7
#define POT_TEMP_GPIO_Port GPIOB
#define LCD_E_Pin LL_GPIO_PIN_8
#define LCD_E_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

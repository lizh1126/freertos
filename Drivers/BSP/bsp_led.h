/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* USER CODE BEGIN Private defines */
#define LED_Pin GPIO_PIN_3
#define LED_GPIO_Port GPIOE

/* USER CODE END Private defines */

/* bsp_led.h */
typedef enum {
    LED_OFF = 0,
    LED_ON  = 1,
} led_status_t;

typedef struct led_dev led_dev_t;

int led_init(const led_dev_t *led);
int led_ctl(const led_dev_t *led, led_status_t status);
int led_toggle(const led_dev_t *led);

extern const led_dev_t bsp_led1;

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */


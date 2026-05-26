/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "bsp_led.h"

/* USER CODE BEGIN 0 */
typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
  uint8_t active_high;
} led_hw_t;

struct led_dev {
  const char       *name;
  const led_hw_t   *hw;
};
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

static int led_init_impl(const led_dev_t *led)
{
  const led_hw_t *hw = led->hw;

  if (hw == NULL) {
    return -1;
  }

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_TypeDef *port = hw->port;
  uint16_t pin = hw->pin;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
  
  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(port, &GPIO_InitStruct);

    return 0;
}

static int led_ctl_impl(const led_dev_t *led, led_status_t status)
{
    const led_hw_t *hw = led->hw;

    if (hw == NULL) {
        return -1;
    }

    HAL_GPIO_WritePin(hw->port, hw->pin,
        status == LED_ON
            ? (hw->active_high ? GPIO_PIN_SET : GPIO_PIN_RESET)
            : (hw->active_high ? GPIO_PIN_RESET : GPIO_PIN_SET));

    return 0;
}

static int led_toggle_impl(const led_dev_t *led)
{
    const led_hw_t *hw = led->hw;

    if (hw == NULL) {
        return -1;
    }

    HAL_GPIO_TogglePin(hw->port, hw->pin);
    return 0;
}

int led_init(const led_dev_t *led)
{
    return led_init_impl(led);
}

int led_ctl(const led_dev_t *led, led_status_t status)
{
    return led_ctl_impl(led, status);
}

int led_toggle(const led_dev_t *led)
{
    return led_toggle_impl(led);
}

static const led_hw_t bsp_led1_hw = {
    .port = GPIOE,
    .pin = GPIO_PIN_3,
    .active_high = 1,
};

const led_dev_t bsp_led1 = {
    .name = "bsp_led1",
    .hw = &bsp_led1_hw,
};

/* USER CODE END 1 */

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

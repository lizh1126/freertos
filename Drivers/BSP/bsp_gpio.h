#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"

static inline void bsp_gpio_clk_enable(GPIO_TypeDef *port)
{
  switch ((uint32_t)port) {
    case GPIOA_BASE: __HAL_RCC_GPIOA_CLK_ENABLE(); break;
    case GPIOB_BASE: __HAL_RCC_GPIOB_CLK_ENABLE(); break;
    case GPIOC_BASE: __HAL_RCC_GPIOC_CLK_ENABLE(); break;
    case GPIOD_BASE: __HAL_RCC_GPIOD_CLK_ENABLE(); break;
    case GPIOE_BASE: __HAL_RCC_GPIOE_CLK_ENABLE(); break;
    case GPIOF_BASE: __HAL_RCC_GPIOF_CLK_ENABLE(); break;
    case GPIOG_BASE: __HAL_RCC_GPIOG_CLK_ENABLE(); break;
    case GPIOH_BASE: __HAL_RCC_GPIOH_CLK_ENABLE(); break;
    case GPIOI_BASE: __HAL_RCC_GPIOI_CLK_ENABLE(); break;
    case GPIOJ_BASE: __HAL_RCC_GPIOJ_CLK_ENABLE(); break;
    case GPIOK_BASE: __HAL_RCC_GPIOK_CLK_ENABLE(); break;
  }
}

#ifdef __cplusplus
}
#endif

#endif /* __BSP_GPIO_H */

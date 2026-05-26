#include "bsp_key.h"
#include "bsp_gpio.h"

typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
  uint8_t active_high;
} key_hw_t;

struct key_dev {
  const char       *name;
  const key_hw_t   *hw;
};

int Bsp_Key_Gpio_Config(const key_dev_t *key)
{
  if (key == NULL || key->hw == NULL) {
    return -1;
  }

  const key_hw_t* key_hw = key->hw;

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_TypeDef *port = key_hw->port;
  uint16_t pin = key_hw->pin;

  /* GPIO Ports Clock Enable */
  bsp_gpio_clk_enable(key_hw->port);

  /*Configure GPIO pin : KEY_Pin */
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(port, &GPIO_InitStruct);

  return 0;
}

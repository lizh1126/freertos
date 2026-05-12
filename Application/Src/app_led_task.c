#include "app_led_task.h"
#include "bsp_led.h"
#include "cmsis_os2.h"

void StartLedTask(void *argument)
{
    for (;;)
    {
        led_toggle(&bsp_led1);
        osDelay(2000);
    }
}

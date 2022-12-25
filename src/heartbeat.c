#include "heartbeat.h"
#include "gpio.h"

static int signal_cnt = 0;
static gpio_state_t previosu_state = GPIO_UNKNOW;
static int alarm = 0;

void heartbeat_init(void)
{
    signal_cnt = 0;
    alarm = 0;
}

void heartbeat_check(void)
{
    gpio_state_t current_state = heartbeat_pin_get();

    if (current_state != previosu_state)
    {
        if (signal_cnt < 9) alarm = 1;
        signal_cnt = 0;
        previosu_state = current_state;
    }

    if (signal_cnt < 11)
    {
        signal_cnt++;
    }
    else
    {
        alarm = 1;
    }
}

int heartbeat_check_alarm_state(void)
{
    return alarm;
}
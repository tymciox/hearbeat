typedef enum gpio_state_enum{
    GPIO_UNKNOW = -1,
    GPIO_LOW = 0,
    GPIO_HIGH = 1
}gpio_state_t;

gpio_state_t heartbeat_pin_get(void);
typedef enum gpio_state_t{
    GPIO_LOW,
    GPIO_HIGH
};

gpio_state_t heartbeat_pin_get(void);
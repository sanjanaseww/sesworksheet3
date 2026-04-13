#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

GPIO_InitTypeDef GPIO_InitStructure;

// Define FSM states
typedef enum {
    IDLE,
    PRESSED,
    RELEASED
} State;

int main(void)
{
    volatile uint32_t i;

    State state = IDLE;
    int led_state = 0;

    // Enable clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // Configure LED (PC7)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Configure Button (PA0)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    while(1)
    State state = IDLE;
int led_state = 0;

while(1)
{
    switch(state)
    {
        case IDLE:
            if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
            {
                state = PRESSED;
            }
            break;

        case PRESSED:
            led_state = !led_state;

            if(led_state)
                GPIOC->BSRR = 1 << 7;
            else
                GPIOC->BRR = 1 << 7;

            state = RELEASED;
            break;

        case RELEASED:
            if(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
            {
                state = IDLE;
            }
            break;
    }
}
    }
}


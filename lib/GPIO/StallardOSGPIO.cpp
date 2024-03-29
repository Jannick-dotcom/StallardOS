#include "StallardOSGPIO.hpp"

volatile void *functions[16];

void enableClockPort(ports port)
{
    switch(port)
    {
        case PORTA:
            __GPIOA_CLK_ENABLE();
            break;
        case PORTB:
            __GPIOB_CLK_ENABLE();
            break;
        case PORTC:
            __GPIOC_CLK_ENABLE();
            break;
        case PORTD:
            __GPIOD_CLK_ENABLE();
            break;
        case PORTE:
            __GPIOE_CLK_ENABLE();
            break;
        #ifdef STM32F4xxxx
        case PORTF:
            __GPIOF_CLK_ENABLE();
            break;
        case PORTG:
            __GPIOG_CLK_ENABLE();
            break;
        case PORTH:
            __GPIOH_CLK_ENABLE();
            break;
        case PORTI:
            //__GPIOI_CLK_ENABLE();
            break;
        #endif
    }
}

// StallardOSGPIO::StallardOSGPIO() {}

/**
 * Create a gpio pin.
 *
 * @param number which number on the Port to use
 * @param port   which port to use
 * @param dir    input or output
 * @param pull   internal pull-up or pull-down
 */
StallardOSGPIO::StallardOSGPIO(uint8_t number, ports port, pinDir dir, bool initialState, pullMode pull)
{

    this->sem.take();

    if (number > 31) //Error check
    {

        this->sem.give();

        StallardOSGeneralFaultHandler();
    }

    this->pin = number;
    this->port = port;
    this->dir = dir;
    this->pull = pull;

    enableClockPort(this->port);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = 1 << this->pin;
    GPIO_InitStruct.Mode = this->dir;
    #ifdef STM32F4xxxx
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    #elif defined(STM32F1xxxx)
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    #endif
    GPIO_InitStruct.Pull = this->pull;

    HAL_GPIO_WritePin((GPIO_TypeDef *)portsToGPIOBase[this->port], 1 << this->pin, GPIO_PinState(initialState));
    HAL_GPIO_Init((GPIO_TypeDef *)portsToGPIOBase[this->port], &GPIO_InitStruct);

    this->sem.give();

}

/**
 * Create a gpio pin.
 *
 * @param number which number on the Port to use
 * @param port   which port to use
 * @param dir    input or output
 * @param pull   internal pull-up or pull-down
 * @param alternate alternative to an normal gpio port
 */
StallardOSGPIO::StallardOSGPIO(uint8_t number, ports port, pinDir dir, pullMode pull, uint32_t alternate)
{

    this->sem.take();

    if (number > 31 || alternate == uint32_t(-1)) //Error check
    {

        this->sem.give();

        StallardOSGeneralFaultHandler();
    }

    this->pin = number;
    this->port = port;
    this->dir = dir;
    this->pull = pull;

    enableClockPort(this->port);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = 1 << this->pin;
    GPIO_InitStruct.Mode = this->dir;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = this->pull;
    #ifdef STM32F4xxxx
    GPIO_InitStruct.Alternate = alternate;
    #endif
    HAL_GPIO_Init((GPIO_TypeDef *)portsToGPIOBase[this->port], &GPIO_InitStruct);

    this->sem.give();
}

StallardOSGPIO::~StallardOSGPIO()
{
    HAL_GPIO_DeInit((GPIO_TypeDef *)portsToGPIOBase[this->port], 1 << this->pin);
}

interruptNumber pinToInterruptNumber(uint8_t pin)
{
    switch (pin)
    {
    case 0:
        return P0;
        break;
    case 1:
        return P1;
        break;
    case 2:
        return P2;
        break;
    case 3:
        return P3;
        break;
    case 4:
        return P4;
        break;
    case 5:
        return P5;
        break;
    case 6:
        return P6;
        break;
    case 7:
        return P7;
        break;
    case 8:
        return P8;
        break;
    case 9:
        return P9;
        break;
    case 10:
        return P10;
        break;
    case 11:
        return P11;
        break;
    case 12:
        return P12;
        break;
    case 13:
        return P13;
        break;
    case 14:
        return P14;
        break;
    case 15:
        return P15;
        break;
    default:
        return P15;
        break;
    }
}

void StallardOSGPIO::setISR(void (*function)())
{
    interruptNumber temp = pinToInterruptNumber(pin);
    CALL_PRIVILEGED();
    HAL_NVIC_SetPriority(IRQn_Type(temp), 0, 0);
    HAL_NVIC_EnableIRQ(IRQn_Type(temp));
    CALL_UNPRIVILEGED();
    functions[this->pin] = (volatile void *)function;
}

extern "C"
{
    void EXTI0_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
    }
    void EXTI1_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
    }
    void EXTI2_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
    }
    void EXTI3_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
    }
    void EXTI4_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
    }
    void EXTI9_5_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
    }
    void EXTI15_10_IRQHandler()
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
    }
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint8_t tempval = log2(GPIO_Pin);
    void (*temp)() = (void (*)())functions[tempval];
    temp();
}

/**
 * Change the pin state.
 *
 * @param state new state, high or low
 * @return new state
 */
bool StallardOSGPIO::operator=(bool state)
{
    return this->write(state);
}

bool StallardOSGPIO::read()
{
    bool returnVal = false;

    this->sem.take();

    // returnVal = HAL_GPIO_ReadPin((GPIO_TypeDef *)portsToGPIOBase[this->port], 1 << this->pin);
    if(this->dir == pinDir::Input || dir == InputITChange || dir == InputITFalling || dir == InputITRising)
    {
        returnVal = ((GPIO_TypeDef *)portsToGPIOBase[this->port])->IDR & (1 << this->pin); //Read the input data register
    }
    else if(this->dir == pinDir::Output || dir == OutputOD || dir == AFOD || dir == AFPP)
    {
        returnVal = ((GPIO_TypeDef *)portsToGPIOBase[this->port])->ODR & (1 << this->pin); //Read the output data register
    }
    else
    {
        StallardOSGeneralFaultHandler();
    }

    this->sem.give();

    return returnVal;
}

bool StallardOSGPIO::write(bool state)
{

    this->sem.take();

    if (this->dir == Output || this->dir == OutputOD)
    {
        HAL_GPIO_WritePin((GPIO_TypeDef *)portsToGPIOBase[this->port], 1 << this->pin, GPIO_PinState(state));

        this->sem.give();

        return state;
    }
    else if (this->dir == Input)
    {
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pin = 1 << this->pin;
        GPIO_InitStruct.Mode = this->dir;
        GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
        GPIO_InitStruct.Pull = pullMode(int(state) + 1);

        HAL_GPIO_Init((GPIO_TypeDef *)portsToGPIOBase[this->port], &GPIO_InitStruct);

        this->sem.give();

        return state;
    }
    this->sem.give();
    return 0;
}

bool StallardOSGPIO::operator!()
{
    return !this->read();
}

bool StallardOSGPIO::operator&&(StallardOSGPIO &ref)
{
    return this->read() && ref.read();
}

bool StallardOSGPIO::operator||(StallardOSGPIO &ref)
{
    return this->read() || ref.read();
}

bool StallardOSGPIO::operator!=(StallardOSGPIO &ref)
{
    return this->write(!ref.read());
}
// bool StallardOSGPIO::operator<(StallardOSGPIO &ref)
// {
//     return this->read() < ref.read();
// }
// bool StallardOSGPIO::operator>(StallardOSGPIO &ref)
// {
//     return this->read() > ref.read();
// }
// bool StallardOSGPIO::operator<=(StallardOSGPIO &ref)
// {
//     return this->read() <= ref.read();
// }
// bool StallardOSGPIO::operator>=(StallardOSGPIO &ref)
// {
//     return this->read() >= ref.read();
// }
bool StallardOSGPIO::operator==(StallardOSGPIO &ref)
{
    return this->read() == ref.read();
}

bool StallardOSGPIO::operator&&(bool ref){ //Logical operator
    return this->read() && ref;
}
bool StallardOSGPIO::operator||(bool ref){ //Logical operator
    return this->read() || ref;
}
bool StallardOSGPIO::operator!=(bool ref){ //Comparison
    return this->read() != ref;
}
// bool StallardOSGPIO::operator<(bool ref){
//     return this->read() < ref;
// }
// bool StallardOSGPIO::operator>(bool ref){

// }
// bool StallardOSGPIO::operator<=(bool ref){

// }
// bool StallardOSGPIO::operator>=(bool ref){

// }
bool StallardOSGPIO::operator==(bool ref){
    return this->read() == ref;
}
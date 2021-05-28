#include "StallardOSSPI.hpp"

StallardOSSPI::StallardOSSPI(SPI_TypeDef *inst, uint32_t baud, ports port, uint8_t number)
{
    #ifdef contextSwitch
    this->sem.take();
    #endif

    this->miso = StallardOSGPIO(SPI_GPIO_PIN_MISO, SPI_GPIO_PORT, Input, nopull, GPIO_AF5_SPI2);
    this->mosi = StallardOSGPIO(SPI_GPIO_PIN_MISO, SPI_GPIO_PORT, Input, nopull, GPIO_AF5_SPI2);
    this->sclk = StallardOSGPIO(SPI_GPIO_PIN_SCK, SPI_GPIO_PORT, Input, nopull, GPIO_AF5_SPI2);
    handle.Instance = inst;
    handle.Init.Mode = SPI_MODE_MASTER; //SPI_MODE_SLAVE
    handle.Init.Direction = SPI_DIRECTION_2LINES; //SPI_DIRECTION_1LINE, SPI_DIRECTION_2LINES_RXONLY
    handle.Init.DataSize = SPI_DATASIZE_8BIT; //SPI_DATASIZE_16BIT
    handle.Init.CLKPolarity = SPI_POLARITY_LOW; //SPI_POLARITY_HIGH
    handle.Init.CLKPhase = SPI_PHASE_1EDGE; //SPI_PHASE_2EDGE
    handle.Init.NSS = SPI_NSS_HARD_OUTPUT; //SPI_NSS_
    handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2; //SPI_BAUDRATEPRESCALER
    handle.Init.FirstBit = SPI_FIRSTBIT_MSB; //SPI_FIRSTBIT_LSB
    handle.Init.TIMode = SPI_TIMODE_DISABLE; //SPI_TIMODE_ENABLE
    handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE; //SPI_CRCCALCULATION_ENABLE
    handle.Init.CRCPolynomial = 10;
    if (HAL_SPI_Init(&handle) != HAL_OK)
    {
        #ifdef contextSwitch
        this->sem.give();
        #endif
        StallardOSGeneralFaultHandler();
    }
    #ifdef contextSwitch
    this->sem.give();
    #endif
}

void StallardOSSPI::send(uint8_t *data, uint16_t size)
{
    #ifdef contextSwitch
    sem.take();
    #endif
    HAL_SPI_Transmit(&handle, data, size, 0);
    #ifdef contextSwitch
    sem.give();
    #endif
}

void StallardOSSPI::receive(uint8_t *data, uint16_t size, uint16_t timeout)
{
    #ifdef contextSwitch
    sem.take();
    #endif
    HAL_SPI_Receive(&handle, data, size, timeout);
    #ifdef contextSwitch
    sem.give();
    #endif
}
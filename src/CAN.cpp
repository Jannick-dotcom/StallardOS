#include "can.h"

JannixCAN::JannixCAN(CANports port, CANBauds baud)
{
    if (port == JannixCAN1)
    {
        CANR = new JannixGPIO(CAN1_r_pin, PORTB, Output);
        CANT = new JannixGPIO(CAN1_t_pin, PORTB, Output);
        canhandle.Instance = CAN1;
    }
    else if (port == JannixCAN2)
    {
        CANR = new JannixGPIO(CAN2_r_pin, PORTB, Output);
        CANT = new JannixGPIO(CAN2_t_pin, PORTB, Output);
        canhandle.Instance = CAN2;
    }

    canhandle.Init.Prescaler = 5; //////////////////////////////////
    canhandle.Init.Mode = CAN_MODE_NORMAL;
    canhandle.Init.SyncJumpWidth = CAN_SJW_1TQ;
    canhandle.Init.TimeSeg1 = CAN_BS1_1TQ;
    canhandle.Init.TimeSeg2 = CAN_BS2_1TQ;
    canhandle.Init.TimeTriggeredMode = DISABLE;
    canhandle.Init.AutoBusOff = DISABLE;
    canhandle.Init.AutoWakeUp = DISABLE;
    canhandle.Init.AutoRetransmission = DISABLE;
    canhandle.Init.ReceiveFifoLocked = DISABLE;
    canhandle.Init.TransmitFifoPriority = DISABLE;

    if (HAL_CAN_Init(&canhandle) != HAL_OK)
    {
        while (1)
            ; //ERROR
    }
    if (HAL_CAN_Start(&canhandle) != HAL_OK)
    {
        /* Start Error */
        while (1)
            ;
    }

    TxHeader.StdId = 0x321;
    TxHeader.ExtId = 0x01;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.DLC = 4;
    TxHeader.TransmitGlobalTime = DISABLE;

    if (HAL_CAN_ActivateNotification(&canhandle, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
    {
        /* Notification Error */
        while (1)
            ;
    }
}

bool JannixCAN::getMessage(JannixCanMessage *msg)
{
    /* Get RX message */
    if (HAL_CAN_GetRxMessage(&canhandle, CAN_RX_FIFO0, &RxHeader, &(msg->Val)) != HAL_OK)
    {
        return false;
    }
    else
    {
        msg->ID = RxHeader.IDE;
        return true;
    }
}

void JannixCAN::sendMessage(JannixCanMessage *msg)
{
    HAL_CAN_AddTxMessage(&canhandle, &TxHeader, &(msg->Val), (uint32_t*)CAN_TX_MAILBOX0);
    return;
}
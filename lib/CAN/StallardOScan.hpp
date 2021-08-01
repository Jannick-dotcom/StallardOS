#ifndef StallardOSCAN_h
#define StallardOSCAN_h

#include "StallardOSconfig.h"
#include "StallardOSGPIO.hpp"
#include "StallardOSsem.hpp"

#include "StallardOScanIDs.h"
#include "StallardOScanTypes.hpp"
#include "StallardOScanStructs.hpp"
#include "StallardOSCANFilter.hpp"


extern "C" inline void StallardOSGeneralFaultHandler();

class StallardOSCAN
{
private:
    CAN_HandleTypeDef canhandle;
    CANports interface;
    CAN_TxHeaderTypeDef TxHeader;
    
    StallardOSGPIO CANT;
    StallardOSGPIO CANR;
    StallardOSSemaphore sem;
    volatile static StallardOSCanMessage StallardOSCanFifo1[CAN_FIFO_size];
    volatile static StallardOSCanMessage StallardOSCanFifo2[CAN_FIFO_size];

    static bool can1used;
    static bool can2used;

    // friend void CAN1_RX0_IRQHandler();
    // friend void CAN1_RX1_IRQHandler();
    // friend void CAN2_RX0_IRQHandler();
    // friend void CAN2_RX1_IRQHandler();

public:
    static CAN_HandleTypeDef can1handle;
    static CAN_HandleTypeDef can2handle;
    static void receiveMessage_FIFO(CAN_HandleTypeDef *canhandle);

    /**
    * create a CAN interface.
    *
    * @param[in] port which CAN port to use
    * @param[in] baud Baud rate of the CAN. Has to be same on all devices
    * @return true if a message is received, false otherwise
    */
    StallardOSCAN(CANports port, CANBauds baud);

    /**
     *  Destroy a CAN interface
     */
    ~StallardOSCAN();

    /**
    * check the usage of the Software FiFo
    *
    * @return amount of Messages in the FiFo
    */
    uint16_t getSWFiFoFillLevel();

    /**
    * receive a can message.
    *
    * @param[out] msg the message container to be filled
    * @param[in] id the id of the message to receive
    * @return true if a message is received, false otherwise
    */
    bool receiveMessage(StallardOSCanMessage *msg, uint16_t id);
    
    /**
    * receive a can message.
    *
    * @param[in,out] msg the message container to be filled
    * @return true if a message is received, false otherwise
    */
    bool receiveMessage(StallardOSCanMessage *msg)
    {
        if (receiveMessage(msg, msg->ID))
        {
            return true;
        }
        return false;
    }

    /**
    * send a can message.
    *
    * @param msg message to send
    * @param size amount of Data Bytes. Maximum is 8
    */
    int sendMessage(StallardOSCanMessage *msg, uint8_t size);

    /**
    * send a can message.
    *
    * @param msg message to send, should be a struct from StallardOScanStructs.h !
    */
    int sendMessage(StallardOSCanMessage *msg);

};


#endif
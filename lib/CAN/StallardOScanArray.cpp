#include "StallardOScanStructs.hpp"

#ifdef useOneMsgBuf
struct STOS_CAN_PDU_Aero_Status_Message Aero_Status_Message;
struct STOS_CAN_PDU_ARH_Offset ARH_Offset;
struct STOS_CAN_PDU_Bat_Hybrid_Status Bat_Hybrid_Status;
struct STOS_CAN_PDU_Bat_Aero_Status Bat_Aero_Status;
struct STOS_CAN_PDU_Debug_Msg Debug_Msg;
struct STOS_CAN_PDU_MS4_Relay MS4_Relay;
struct STOS_CAN_PDU_PDU_Status PDU_Status;
struct STOS_CAN_PDU_Current_Sensors Current_Sensors;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_Shift CanOPEN_RxPDO1_Shift;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_Clutch CanOPEN_RxPDO1_Clutch;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_HAL_1 CanOPEN_RxPDO1_HAL_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_HAL_2 CanOPEN_RxPDO1_HAL_2;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_Airbox CanOPEN_RxPDO1_Airbox;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_ARH_1 CanOPEN_RxPDO1_ARH_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO1_ARH_2 CanOPEN_RxPDO1_ARH_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_Shift CanOPEN_TxPDO1_Shift;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_Clutch CanOPEN_TxPDO1_Clutch;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_HAL_1 CanOPEN_TxPDO1_HAL_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_HAL_2 CanOPEN_TxPDO1_HAL_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_Airbox CanOPEN_TxPDO1_Airbox;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_ARH_1 CanOPEN_TxPDO1_ARH_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO1_ARH_2 CanOPEN_TxPDO1_ARH_2;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_Shift CanOPEN_RxPDO2_Shift;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_Clutch CanOPEN_RxPDO2_Clutch;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_HAL_1 CanOPEN_RxPDO2_HAL_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_HAL_2 CanOPEN_RxPDO2_HAL_2;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_Airbox CanOPEN_RxPDO2_Airbox;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_ARH_1 CanOPEN_RxPDO2_ARH_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO2_ARH_2 CanOPEN_RxPDO2_ARH_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_Shift CanOPEN_TxPDO2_Shift;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_Clutch CanOPEN_TxPDO2_Clutch;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_HAL_1 CanOPEN_TxPDO2_HAL_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_HAL_2 CanOPEN_TxPDO2_HAL_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_Airbox CanOPEN_TxPDO2_Airbox;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_ARH_1 CanOPEN_TxPDO2_ARH_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO2_ARH_2 CanOPEN_TxPDO2_ARH_2;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_Shift CanOPEN_RxPDO3_Shift;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_Clutch CanOPEN_RxPDO3_Clutch;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_HAL_1 CanOPEN_RxPDO3_HAL_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_HAL_2 CanOPEN_RxPDO3_HAL_2;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_Airbox CanOPEN_RxPDO3_Airbox;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_ARH_1 CanOPEN_RxPDO3_ARH_1;
struct STOS_CAN_PDU_CanOPEN_RxPDO3_ARH_2 CanOPEN_RxPDO3_ARH_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_Shift CanOPEN_TxPDO3_Shift;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_Clutch CanOPEN_TxPDO3_Clutch;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_HAL_1 CanOPEN_TxPDO3_HAL_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_HAL_2 CanOPEN_TxPDO3_HAL_2;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_Airbox CanOPEN_TxPDO3_Airbox;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_ARH_1 CanOPEN_TxPDO3_ARH_1;
struct STOS_CAN_PDU_CanOPEN_TxPDO3_ARH_2 CanOPEN_TxPDO3_ARH_2;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_Shift CanOPEN_SDO_Upload_Shift;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_Clutch CanOPEN_SDO_Upload_Clutch;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_HAL_1 CanOPEN_SDO_Upload_HAL_1;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_HAL_2 CanOPEN_SDO_Upload_HAL_2;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_Airbox CanOPEN_SDO_Upload_Airbox;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_ARH_1 CanOPEN_SDO_Upload_ARH_1;
struct STOS_CAN_PDU_CanOPEN_SDO_Upload_ARH_2 CanOPEN_SDO_Upload_ARH_2;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_Shift CanOPEN_SDO_Download_Shift;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_Clutch CanOPEN_SDO_Download_Clutch;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_HAL_1 CanOPEN_SDO_Download_HAL_1;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_HAL_2 CanOPEN_SDO_Download_HAL_2;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_Airbox CanOPEN_SDO_Download_Airbox;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_ARH_1 CanOPEN_SDO_Download_ARH_1;
struct STOS_CAN_PDU_CanOPEN_SDO_Download_ARH_2 CanOPEN_SDO_Download_ARH_2;
struct STOS_CAN_PDU_CanOPEN_SYNC CanOPEN_SYNC;
struct STOS_CAN_PDU_CanOPEN_NMT CanOPEN_NMT;
struct STOS_CAN_PDU_CanOPEN_BootUp_Shift CanOPEN_BootUp_Shift;
struct STOS_CAN_PDU_CanOPEN_BootUp_Clutch CanOPEN_BootUp_Clutch;
struct STOS_CAN_PDU_CanOPEN_BootUp_HAL_1 CanOPEN_BootUp_HAL_1;
struct STOS_CAN_PDU_CanOPEN_BootUp_HAL_2 CanOPEN_BootUp_HAL_2;
struct STOS_CAN_PDU_CanOPEN_BootUp_Airbox CanOPEN_BootUp_Airbox;
struct STOS_CAN_PDU_CanOPEN_BootUp_ARH_1 CanOPEN_BootUp_ARH_1;
struct STOS_CAN_PDU_CanOPEN_BootUp_ARH_2 CanOPEN_BootUp_ARH_2;
struct STOS_CAN_PDU_CanOPEN_Error_Shift CanOPEN_Error_Shift;
struct STOS_CAN_PDU_CanOPEN_Error_Clutch CanOPEN_Error_Clutch;
struct STOS_CAN_PDU_CanOPEN_Error_HAL_1 CanOPEN_Error_HAL_1;
struct STOS_CAN_PDU_CanOPEN_Error_HAL_2 CanOPEN_Error_HAL_2;
struct STOS_CAN_PDU_CanOPEN_Error_Airbox CanOPEN_Error_Airbox;
struct STOS_CAN_PDU_CanOPEN_Error_ARH_1 CanOPEN_Error_ARH_1;
struct STOS_CAN_PDU_CanOPEN_Error_ARH_2 CanOPEN_Error_ARH_2;
struct STOS_CAN_PDU_ARH_Status ARH_Status;
struct STOS_CAN_PDU_Gear_Sensor Gear_Sensor;
struct STOS_CAN_PDU_Flash_Over_Can_Discovery Flash_Over_Can_Discovery;
struct STOS_CAN_PDU_Flash_Over_Can_FCU_Host Flash_Over_Can_FCU_Host;
struct STOS_CAN_PDU_Flash_Over_Can_FCU_Client Flash_Over_Can_FCU_Client;
struct STOS_CAN_PDU_Flash_Over_Can_RCU_Host Flash_Over_Can_RCU_Host;
struct STOS_CAN_PDU_Flash_Over_Can_RCU_Client Flash_Over_Can_RCU_Client;
struct STOS_CAN_PDU_Flash_Over_Can_PCU_Host Flash_Over_Can_PCU_Host;
struct STOS_CAN_PDU_Flash_Over_Can_PCU_Client Flash_Over_Can_PCU_Client;
struct STOS_CAN_PDU_Flash_Over_Can_SWCU_Host Flash_Over_Can_SWCU_Host;
struct STOS_CAN_PDU_Flash_Over_Can_SWCU_Client Flash_Over_Can_SWCU_Client;
struct STOS_CAN_PDU_Flash_Over_Can_BMS_HOMO_Host Flash_Over_Can_BMS_HOMO_Host;
struct STOS_CAN_PDU_Flash_Over_Can_BMS_HOMO_Client Flash_Over_Can_BMS_HOMO_Client;
struct STOS_CAN_PDU_Flash_Over_Can_BMS_HYB_Host Flash_Over_Can_BMS_HYB_Host;
struct STOS_CAN_PDU_Flash_Over_Can_BMS_HYB_Client Flash_Over_Can_BMS_HYB_Client;
struct STOS_CAN_PDU_FCU_Health FCU_Health;
struct STOS_CAN_PDU_RCU_Health RCU_Health;
struct STOS_CAN_PDU_PDU_Health PDU_Health;
struct STOS_CAN_PDU_SWCU_Health SWCU_Health;
struct STOS_CAN_PDU_BMS_HOMO_Health BMS_HOMO_Health;
struct STOS_CAN_PDU_BMS_HYB_Health BMS_HYB_Health;
struct STOS_CAN_PDU_Airbox_Position Airbox_Position;
struct STOS_CAN_PDU_Brake_Disc_R Brake_Disc_R;
struct STOS_CAN_PDU_Brake_Disc_F Brake_Disc_F;
struct STOS_CAN_PDU_Brake_Pressure Brake_Pressure;
struct STOS_CAN_PDU_FDS_Wheel_Signals FDS_Wheel_Signals;
struct STOS_CAN_PDU_FDS_Parameters FDS_Parameters;
struct STOS_CAN_PDU_HAL_Status HAL_Status;
struct STOS_CAN_PDU_Rocker_R Rocker_R;
struct STOS_CAN_PDU_Rocker_F Rocker_F;
struct STOS_CAN_PDU_Steering_Whl_Angle Steering_Whl_Angle;
struct STOS_CAN_PDU_Whl_Speed_R Whl_Speed_R;
struct STOS_CAN_PDU_Whl_Speed_F Whl_Speed_F;
struct STOS_CAN_PDU_Pitot Pitot;
struct STOS_CAN_PDU_Water_Oil_Status Water_Oil_Status;
struct STOS_CAN_PDU_FCU_Status FCU_Status;
struct STOS_CAN_PDU_RCU_Status RCU_Status;
struct STOS_CAN_PDU_Bat_Hybrid_Electr_2 Bat_Hybrid_Electr_2;
struct STOS_CAN_PDU_Bat_Hybrid_Electr_1 Bat_Hybrid_Electr_1;
struct STOS_CAN_PDU_Bat_Hybrid_Temp_1 Bat_Hybrid_Temp_1;
struct STOS_CAN_PDU_Bat_Hybrid_Temp_2 Bat_Hybrid_Temp_2;
struct STOS_CAN_PDU_Bat_Aero_Electr_2 Bat_Aero_Electr_2;
struct STOS_CAN_PDU_Bat_Aero_Electr_1 Bat_Aero_Electr_1;
struct STOS_CAN_PDU_Bat_Aero_Temp_1 Bat_Aero_Temp_1;
struct STOS_CAN_PDU_Bat_Aero_Temp_2 Bat_Aero_Temp_2;
struct STOS_CAN_PDU_IMU_Gyro IMU_Gyro;
struct STOS_CAN_PDU_IMU_Accel IMU_Accel;
struct STOS_CAN_PDU_Aero_Fan Aero_Fan;
struct STOS_CAN_PDU_SWCU_Switches SWCU_Switches;
struct STOS_CAN_PDU_Aero_ADC_1 Aero_ADC_1;
struct STOS_CAN_PDU_Aero_ADC_2 Aero_ADC_2;
struct STOS_CAN_PDU_Aero_ADC_3 Aero_ADC_3;
struct STOS_CAN_PDU_Aero_ADC_4 Aero_ADC_4;
struct STOS_CAN_PDU_Aero_ADC_5 Aero_ADC_5;
struct STOS_CAN_PDU_Aero_ADC_6 Aero_ADC_6;
struct STOS_CAN_PDU_Aero_ADC_7 Aero_ADC_7;
struct STOS_CAN_PDU_Aero_ADC_8 Aero_ADC_8;
struct STOS_CAN_PDU_Aero_ADC_9 Aero_ADC_9;
struct STOS_CAN_PDU_AGS1_gearbox_control_unit AGS1_gearbox_control_unit;
struct STOS_CAN_PDU_ABS_switch_state_slip_and_speed ABS_switch_state_slip_and_speed;
struct STOS_CAN_PDU_ABS_wheelspeeds ABS_wheelspeeds;
struct STOS_CAN_PDU_Boost_Pressures_Wastegate Boost_Pressures_Wastegate;
struct STOS_CAN_PDU_States_Temp_Press States_Temp_Press;
struct STOS_CAN_PDU_Electronic_Throttle_Control Electronic_Throttle_Control;
struct STOS_CAN_PDU_Traction_Control Traction_Control;
struct STOS_CAN_PDU_Gear_Dashboard_Acceleration Gear_Dashboard_Acceleration;
struct STOS_CAN_PDU_Lapfunc Lapfunc;
struct STOS_CAN_PDU_Speed Speed;
struct STOS_CAN_PDU_Lambda Lambda;
struct STOS_CAN_PDU_Ignition_Rev_Ath Ignition_Rev_Ath;
struct STOS_CAN_PDU_Ignition Ignition;
struct STOS_CAN_PDU_Injection_2 Injection_2;
struct STOS_CAN_PDU_Injection_1 Injection_1;
#endif

#ifdef useOneMsgBuf
struct StallardOSCanMessage *canarray[] = {
	&Aero_Status_Message,
	&ARH_Offset,
	&Bat_Hybrid_Status,
	&Bat_Aero_Status,
	&Debug_Msg,
	&MS4_Relay,
	&PDU_Status,
	&Current_Sensors,
	&CanOPEN_RxPDO1_Shift,
	&CanOPEN_RxPDO1_Clutch,
	&CanOPEN_RxPDO1_HAL_1,
	&CanOPEN_RxPDO1_HAL_2,
	&CanOPEN_RxPDO1_Airbox,
	&CanOPEN_RxPDO1_ARH_1,
	&CanOPEN_RxPDO1_ARH_2,
	&CanOPEN_TxPDO1_Shift,
	&CanOPEN_TxPDO1_Clutch,
	&CanOPEN_TxPDO1_HAL_1,
	&CanOPEN_TxPDO1_HAL_2,
	&CanOPEN_TxPDO1_Airbox,
	&CanOPEN_TxPDO1_ARH_1,
	&CanOPEN_TxPDO1_ARH_2,
	&CanOPEN_RxPDO2_Shift,
	&CanOPEN_RxPDO2_Clutch,
	&CanOPEN_RxPDO2_HAL_1,
	&CanOPEN_RxPDO2_HAL_2,
	&CanOPEN_RxPDO2_Airbox,
	&CanOPEN_RxPDO2_ARH_1,
	&CanOPEN_RxPDO2_ARH_2,
	&CanOPEN_TxPDO2_Shift,
	&CanOPEN_TxPDO2_Clutch,
	&CanOPEN_TxPDO2_HAL_1,
	&CanOPEN_TxPDO2_HAL_2,
	&CanOPEN_TxPDO2_Airbox,
	&CanOPEN_TxPDO2_ARH_1,
	&CanOPEN_TxPDO2_ARH_2,
	&CanOPEN_RxPDO3_Shift,
	&CanOPEN_RxPDO3_Clutch,
	&CanOPEN_RxPDO3_HAL_1,
	&CanOPEN_RxPDO3_HAL_2,
	&CanOPEN_RxPDO3_Airbox,
	&CanOPEN_RxPDO3_ARH_1,
	&CanOPEN_RxPDO3_ARH_2,
	&CanOPEN_TxPDO3_Shift,
	&CanOPEN_TxPDO3_Clutch,
	&CanOPEN_TxPDO3_HAL_1,
	&CanOPEN_TxPDO3_HAL_2,
	&CanOPEN_TxPDO3_Airbox,
	&CanOPEN_TxPDO3_ARH_1,
	&CanOPEN_TxPDO3_ARH_2,
	&CanOPEN_SDO_Upload_Shift,
	&CanOPEN_SDO_Upload_Clutch,
	&CanOPEN_SDO_Upload_HAL_1,
	&CanOPEN_SDO_Upload_HAL_2,
	&CanOPEN_SDO_Upload_Airbox,
	&CanOPEN_SDO_Upload_ARH_1,
	&CanOPEN_SDO_Upload_ARH_2,
	&CanOPEN_SDO_Download_Shift,
	&CanOPEN_SDO_Download_Clutch,
	&CanOPEN_SDO_Download_HAL_1,
	&CanOPEN_SDO_Download_HAL_2,
	&CanOPEN_SDO_Download_Airbox,
	&CanOPEN_SDO_Download_ARH_1,
	&CanOPEN_SDO_Download_ARH_2,
	&CanOPEN_SYNC,
	&CanOPEN_NMT,
	&CanOPEN_BootUp_Shift,
	&CanOPEN_BootUp_Clutch,
	&CanOPEN_BootUp_HAL_1,
	&CanOPEN_BootUp_HAL_2,
	&CanOPEN_BootUp_Airbox,
	&CanOPEN_BootUp_ARH_1,
	&CanOPEN_BootUp_ARH_2,
	&CanOPEN_Error_Shift,
	&CanOPEN_Error_Clutch,
	&CanOPEN_Error_HAL_1,
	&CanOPEN_Error_HAL_2,
	&CanOPEN_Error_Airbox,
	&CanOPEN_Error_ARH_1,
	&CanOPEN_Error_ARH_2,
	&ARH_Status,
	&Gear_Sensor,
	&Flash_Over_Can_Discovery,
	&Flash_Over_Can_FCU_Host,
	&Flash_Over_Can_FCU_Client,
	&Flash_Over_Can_RCU_Host,
	&Flash_Over_Can_RCU_Client,
	&Flash_Over_Can_PCU_Host,
	&Flash_Over_Can_PCU_Client,
	&Flash_Over_Can_SWCU_Host,
	&Flash_Over_Can_SWCU_Client,
	&Flash_Over_Can_BMS_HOMO_Host,
	&Flash_Over_Can_BMS_HOMO_Client,
	&Flash_Over_Can_BMS_HYB_Host,
	&Flash_Over_Can_BMS_HYB_Client,
	&FCU_Health,
	&RCU_Health,
	&PDU_Health,
	&SWCU_Health,
	&BMS_HOMO_Health,
	&BMS_HYB_Health,
	&Airbox_Position,
	&Brake_Disc_R,
	&Brake_Disc_F,
	&Brake_Pressure,
	&FDS_Wheel_Signals,
	&FDS_Parameters,
	&HAL_Status,
	&Rocker_R,
	&Rocker_F,
	&Steering_Whl_Angle,
	&Whl_Speed_R,
	&Whl_Speed_F,
	&Pitot,
	&Water_Oil_Status,
	&FCU_Status,
	&RCU_Status,
	&Bat_Hybrid_Electr_2,
	&Bat_Hybrid_Electr_1,
	&Bat_Hybrid_Temp_1,
	&Bat_Hybrid_Temp_2,
	&Bat_Aero_Electr_2,
	&Bat_Aero_Electr_1,
	&Bat_Aero_Temp_1,
	&Bat_Aero_Temp_2,
	&IMU_Gyro,
	&IMU_Accel,
	&Aero_Fan,
	&SWCU_Switches,
	&Aero_ADC_1,
	&Aero_ADC_2,
	&Aero_ADC_3,
	&Aero_ADC_4,
	&Aero_ADC_5,
	&Aero_ADC_6,
	&Aero_ADC_7,
	&Aero_ADC_8,
	&Aero_ADC_9,
	&AGS1_gearbox_control_unit,
	&ABS_switch_state_slip_and_speed,
	&ABS_wheelspeeds,
	&Boost_Pressures_Wastegate,
	&States_Temp_Press,
	&Electronic_Throttle_Control,
	&Traction_Control,
	&Gear_Dashboard_Acceleration,
	&Lapfunc,
	&Speed,
	&Lambda,
	&Ignition_Rev_Ath,
	&Ignition,
	&Injection_2,
	&Injection_1,
};
#endif

#ifdef useOneMsgBuf
uint16_t idarray[] = {
	Aero_Status_Message.ID,
	ARH_Offset.ID,
	Bat_Hybrid_Status.ID,
	Bat_Aero_Status.ID,
	Debug_Msg.ID,
	MS4_Relay.ID,
	PDU_Status.ID,
	Current_Sensors.ID,
	CanOPEN_RxPDO1_Shift.ID,
	CanOPEN_RxPDO1_Clutch.ID,
	CanOPEN_RxPDO1_HAL_1.ID,
	CanOPEN_RxPDO1_HAL_2.ID,
	CanOPEN_RxPDO1_Airbox.ID,
	CanOPEN_RxPDO1_ARH_1.ID,
	CanOPEN_RxPDO1_ARH_2.ID,
	CanOPEN_TxPDO1_Shift.ID,
	CanOPEN_TxPDO1_Clutch.ID,
	CanOPEN_TxPDO1_HAL_1.ID,
	CanOPEN_TxPDO1_HAL_2.ID,
	CanOPEN_TxPDO1_Airbox.ID,
	CanOPEN_TxPDO1_ARH_1.ID,
	CanOPEN_TxPDO1_ARH_2.ID,
	CanOPEN_RxPDO2_Shift.ID,
	CanOPEN_RxPDO2_Clutch.ID,
	CanOPEN_RxPDO2_HAL_1.ID,
	CanOPEN_RxPDO2_HAL_2.ID,
	CanOPEN_RxPDO2_Airbox.ID,
	CanOPEN_RxPDO2_ARH_1.ID,
	CanOPEN_RxPDO2_ARH_2.ID,
	CanOPEN_TxPDO2_Shift.ID,
	CanOPEN_TxPDO2_Clutch.ID,
	CanOPEN_TxPDO2_HAL_1.ID,
	CanOPEN_TxPDO2_HAL_2.ID,
	CanOPEN_TxPDO2_Airbox.ID,
	CanOPEN_TxPDO2_ARH_1.ID,
	CanOPEN_TxPDO2_ARH_2.ID,
	CanOPEN_RxPDO3_Shift.ID,
	CanOPEN_RxPDO3_Clutch.ID,
	CanOPEN_RxPDO3_HAL_1.ID,
	CanOPEN_RxPDO3_HAL_2.ID,
	CanOPEN_RxPDO3_Airbox.ID,
	CanOPEN_RxPDO3_ARH_1.ID,
	CanOPEN_RxPDO3_ARH_2.ID,
	CanOPEN_TxPDO3_Shift.ID,
	CanOPEN_TxPDO3_Clutch.ID,
	CanOPEN_TxPDO3_HAL_1.ID,
	CanOPEN_TxPDO3_HAL_2.ID,
	CanOPEN_TxPDO3_Airbox.ID,
	CanOPEN_TxPDO3_ARH_1.ID,
	CanOPEN_TxPDO3_ARH_2.ID,
	CanOPEN_SDO_Upload_Shift.ID,
	CanOPEN_SDO_Upload_Clutch.ID,
	CanOPEN_SDO_Upload_HAL_1.ID,
	CanOPEN_SDO_Upload_HAL_2.ID,
	CanOPEN_SDO_Upload_Airbox.ID,
	CanOPEN_SDO_Upload_ARH_1.ID,
	CanOPEN_SDO_Upload_ARH_2.ID,
	CanOPEN_SDO_Download_Shift.ID,
	CanOPEN_SDO_Download_Clutch.ID,
	CanOPEN_SDO_Download_HAL_1.ID,
	CanOPEN_SDO_Download_HAL_2.ID,
	CanOPEN_SDO_Download_Airbox.ID,
	CanOPEN_SDO_Download_ARH_1.ID,
	CanOPEN_SDO_Download_ARH_2.ID,
	CanOPEN_SYNC.ID,
	CanOPEN_NMT.ID,
	CanOPEN_BootUp_Shift.ID,
	CanOPEN_BootUp_Clutch.ID,
	CanOPEN_BootUp_HAL_1.ID,
	CanOPEN_BootUp_HAL_2.ID,
	CanOPEN_BootUp_Airbox.ID,
	CanOPEN_BootUp_ARH_1.ID,
	CanOPEN_BootUp_ARH_2.ID,
	CanOPEN_Error_Shift.ID,
	CanOPEN_Error_Clutch.ID,
	CanOPEN_Error_HAL_1.ID,
	CanOPEN_Error_HAL_2.ID,
	CanOPEN_Error_Airbox.ID,
	CanOPEN_Error_ARH_1.ID,
	CanOPEN_Error_ARH_2.ID,
	ARH_Status.ID,
	Gear_Sensor.ID,
	Flash_Over_Can_Discovery.ID,
	Flash_Over_Can_FCU_Host.ID,
	Flash_Over_Can_FCU_Client.ID,
	Flash_Over_Can_RCU_Host.ID,
	Flash_Over_Can_RCU_Client.ID,
	Flash_Over_Can_PCU_Host.ID,
	Flash_Over_Can_PCU_Client.ID,
	Flash_Over_Can_SWCU_Host.ID,
	Flash_Over_Can_SWCU_Client.ID,
	Flash_Over_Can_BMS_HOMO_Host.ID,
	Flash_Over_Can_BMS_HOMO_Client.ID,
	Flash_Over_Can_BMS_HYB_Host.ID,
	Flash_Over_Can_BMS_HYB_Client.ID,
	FCU_Health.ID,
	RCU_Health.ID,
	PDU_Health.ID,
	SWCU_Health.ID,
	BMS_HOMO_Health.ID,
	BMS_HYB_Health.ID,
	Airbox_Position.ID,
	Brake_Disc_R.ID,
	Brake_Disc_F.ID,
	Brake_Pressure.ID,
	FDS_Wheel_Signals.ID,
	FDS_Parameters.ID,
	HAL_Status.ID,
	Rocker_R.ID,
	Rocker_F.ID,
	Steering_Whl_Angle.ID,
	Whl_Speed_R.ID,
	Whl_Speed_F.ID,
	Pitot.ID,
	Water_Oil_Status.ID,
	FCU_Status.ID,
	RCU_Status.ID,
	Bat_Hybrid_Electr_2.ID,
	Bat_Hybrid_Electr_1.ID,
	Bat_Hybrid_Temp_1.ID,
	Bat_Hybrid_Temp_2.ID,
	Bat_Aero_Electr_2.ID,
	Bat_Aero_Electr_1.ID,
	Bat_Aero_Temp_1.ID,
	Bat_Aero_Temp_2.ID,
	IMU_Gyro.ID,
	IMU_Accel.ID,
	Aero_Fan.ID,
	SWCU_Switches.ID,
	Aero_ADC_1.ID,
	Aero_ADC_2.ID,
	Aero_ADC_3.ID,
	Aero_ADC_4.ID,
	Aero_ADC_5.ID,
	Aero_ADC_6.ID,
	Aero_ADC_7.ID,
	Aero_ADC_8.ID,
	Aero_ADC_9.ID,
	AGS1_gearbox_control_unit.ID,
	ABS_switch_state_slip_and_speed.ID,
	ABS_wheelspeeds.ID,
	Boost_Pressures_Wastegate.ID,
	States_Temp_Press.ID,
	Electronic_Throttle_Control.ID,
	Traction_Control.ID,
	Gear_Dashboard_Acceleration.ID,
	Lapfunc.ID,
	Speed.ID,
	Lambda.ID,
	Ignition_Rev_Ath.ID,
	Ignition.ID,
	Injection_2.ID,
	Injection_1.ID,
};
#endif

#ifdef useOneMsgBuf
uint16_t idToOffset(uint16_t id) {
	for(uint16_t i = 0; i < sizeof(idarray) / sizeof(uint16_t); i++) {
		if(idarray[i] == id) return i;
	}
	return -1;
}
#endif

#ifdef useOneMsgBuf
void copyToBuffer(const StallardOSCanMessage *msg){
	if(msg == nullptr) return;
	uint16_t offset = idToOffset(msg->ID);
	if(offset < sizeof(canarray) / sizeof(StallardOSCanMessage*)) {
		*(canarray[offset]) = *(msg);
	}
}
#endif
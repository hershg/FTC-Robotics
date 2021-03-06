#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom)
#pragma config(Sensor, S3,     HTTMUX,         sensorAnalogInactive)
#pragma config(Motor,  mtr_S1_C1_1,     LeftFront,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     LeftBack,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     RightBack,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     SlideLift,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     ArticArm,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rdpartyrobotcdr-3.0/drivers/hitechnic-sensormux.h"
#include "rdpartyrobotcdr-3.0/drivers/hitechnic-irseeker-v2.h"
#include "ServoLibrary.c"
#include "Move_Library.c"

// Give the sensor a nice easy to use name
const tMUXSensor DirectionIR = msensor_S2_3;
const tMUXSensor DistanceIR = msensor_S2_2;

int RdirAC = 0;

#include "PID2Beacon.c"

#define currentDistanceIR_acDirectionValue //zsdfasdf
#define currentDirectionIR_acDirectionValue //zsdfasdf
#define LargeTurn //sdfsdf
#define SmallTurn //sdfsdf

void SpinTill4()
{
	//find current reading
			//if current reading < 4, spin till 3
			//else if current reading > 4, spin till 5
			//else do nothing

	//spin till 4 continuing previous spin
}


task main()
{

	ServoRotateSmooth(servo1, 128); //set servo properly

	//execute spinTill4

	distance_IR_AC_direction_value = HTIRS2readACDir(DistanceIR);

	while(distance_IR_AC_direction_value != 3)
  {
  	PID2Beacon();

  	distance_IR_AC_direction_value = HTIRS2readACDir(LeftIR);
	}

	RaiseSlideLift(90, 3500);

	while(LdirAC != 0)
  {
  	motor[];
	}
}

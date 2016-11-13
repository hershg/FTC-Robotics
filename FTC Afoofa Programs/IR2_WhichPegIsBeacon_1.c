#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2,         sensorI2CCustom)
#pragma config(Motor,  motorB,          MotorB,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          MotorC,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     Left,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Right,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Arm,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rdpartyrobotcdr-3.0\drivers\hitechnic-irseeker-v2.h"

task main ()
{
  int dirAC = 0;
	int val = 0;       // the translated directional value.

	// Set DSP mode to 1200 Hz.
  tHTIRS2DSPMode _mode = DSP_1200;
	eraseDisplay();


	//**********move the robot to the position directly infront of the middle peg************//


	while(true)
	{
    //read the current modulated signal direction
		dirAC = HTIRS2readACDir(HTIRS2);

		//calculate which peg IR Beacon is on (if val = 0, then middle peg; -1 is left peg; 1 is right peg)
		if(dirAC == 5)
		{
			val = 0;
		}
		else if(dirAC > 5)
		{
			val = 1;
		}
		else if(dirAC < 5)
		{
			val = -1;
		}
		else

		// display info

		nxtDisplayCenteredBigTextLine(4, "Val=%d", val);

		//if val is 0,	move to middle	peg and place ring
		//if val is -1,	move to left		peg and place ring
		//if val is 1,	move to right		peg and place ring

		wait10Msec(2);
  }
}
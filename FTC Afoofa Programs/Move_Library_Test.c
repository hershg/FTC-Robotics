#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Move_Library.c";

task main()
{
	Move(50,50,50,50,50,50,50,50);
		wait10Msec(1000);
	MoveForward(50,50);
		wait10Msec(1000);
	MoveBackward(50,50);
		wait10Msec(1000);
	SpinRight(50,50);
		wait10Msec(1000);
	SpinLeft(50,50);
		wait10Msec(1000);
	PivotRight(50,50);
		wait10Msec(1000);
	PivotLeft(50,50);
		wait10Msec(1000);
}

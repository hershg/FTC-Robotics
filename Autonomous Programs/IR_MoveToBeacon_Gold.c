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

#include "rdpartyrobotcdr-3.0\drivers\hitechnic-sensormux.h"
#include "rdpartyrobotcdr-3.0\drivers\hitechnic-irseeker-v2.h"

const tMUXSensor DirIR = msensor_S2_3;
const tMUXSensor DistIR = msensor_S2_2;

#define DISPLAY_FUNCTION 1
#define DISPLAY_SENSOR_CUR 2
#define DISPLAY_SENSOR_STATE 3
#define DISPLAY_TIME 4
#define DISPLAY_ERROR 5


#include "Move_Library.c"
#include "ServoLibrary.c"

#define goBack(power, mSecs) moveForTime(-power, -power, mSecs)
#define goForward(power, mSecs) moveForTime(power, power, mSecs)
#define _spinRight(power, mSecs) moveForTime(power,  -power, mSecs)
#define _spinLeft(power, mSecs) moveForTime( -power, power, mSecs)
#define steer(powerLeft, powerRight, mSecs) moveForTime( powerLeft, powerRight, mSecs)

int distAC = 0;
int dirAC = 0;

int approachingFromLeft = 0;
int approachingFromRight=0;

// int distS1, distS2, distS3, distS4, distS5 = 0;
int startPosition=1;

task ReadIR ()
{
	eraseDisplay();

  while(true)
  {
    dirAC = HTIRS2readACDir(DirIR);
    distAC = HTIRS2readACDir(DistIR);
    //wait10Msec(1);
    wait1Msec(7);
  }
}


void turnToDir4() {
	while(dirAC != 4)
	{
		if (dirAC == 0) {
			nxtDisplayTextLine(DISPLAY_ERROR, "2FAR: Dir=%d Dist=%d", dirAC, distAC);
			//stopMotors();
			wait10Msec(1);
		} else
		if(dirAC > 4)
		{
			approachingFromLeft++;
			motor[RightFront] = -50;
	 		motor[RightBack] = -50;
			motor[LeftFront] = 50;
			motor[LeftBack] = 50;
		} else
		if(dirAC < 4)
		{
			approachingFromRight++;
			motor[RightFront] = 50;
	 		motor[RightBack] = 50;
			motor[LeftFront] = -50;
			motor[LeftBack] = -50;
		}
		wait1Msec(1);
	}
}

void moveToDistance3(){

	while(distAC >= 4)  // Follow the Distance till 3
	{
		if ( dirAC==0) {
			nxtDisplayTextLine(DISPLAY_ERROR, "ZERO Dir=%d Dist=%d", dirAC, distAC);
			motor[RightFront] = 30;
	 		motor[RightBack] = 30;
			motor[LeftFront] = 30;
			motor[LeftBack] = 30;
		} else
		if(dirAC == 4)
		{
			motor[RightFront] = 100;
	 		motor[RightBack] = 100;
			motor[LeftFront] = 100;
			motor[LeftBack] = 100;
		} else
		if(dirAC > 5)
		{
			motor[RightFront] = -50;
	 		motor[RightBack] = -50;
			motor[LeftFront] = 50;
			motor[LeftBack] = 50;
		} else
		if(dirAC < 3)
		{
			motor[RightFront] = 50;
	 		motor[RightBack] = 50;
			motor[LeftFront] = -50;
			motor[LeftBack] = -50;
		} else
		if(dirAC == 5)
		{
			motor[RightFront] = 0;
	 		motor[RightBack] = 0;
			motor[LeftFront] = 60;
			motor[LeftBack] = 60;
		} else
		if(dirAC == 3)
		{
			motor[RightFront] = 60;
	 		motor[RightBack] = 60;
			motor[LeftFront] = 0;
			motor[LeftBack] = 0;
		}

		wait1Msec(1);
	}
}

void alignAgainToDir4() {
	while(dirAC != 4)  // Again Align to Dir 4
	{
		if(dirAC > 4)
		{
			motor[RightFront] = -50;
	 		motor[RightBack] = -50;
			motor[LeftFront] = 50;
			motor[LeftBack] = 50;
		}
		if(dirAC < 4)
		{
			motor[RightFront] = 50;
	 		motor[RightBack] = 50;
			motor[LeftFront] = -50;
			motor[LeftBack] = -50;
		}
		wait1Msec(1);
	}
}



void waitToSeeTheMessages() {
	stopMotors();
	int currentTime = time1[T1];
  nxtDisplayTextLine(DISPLAY_TIME, "timeElapsed=%d", currentTime);

	while(1)
	{
		 nxtDisplayTextLine(DISPLAY_SENSOR_CUR, "Cur Dir=%d Dist=%d", dirAC, distAC);

		 wait10Msec(10);
	}
}

void moveTillDir7() {
  while(dirAC < 7)
	{
		motor[RightFront] = 80;
	 	motor[RightBack] = 80;
		motor[LeftFront] = 80;
		motor[LeftBack] = 80;

		wait1Msec(1);
	}
}

void putTheRing(){
	RaiseSlideLift(90, 3100);
	stopMotors();
	wait10Msec(10);
	goForward(50, 650);
	stopMotors();
	RaiseSlideLift(-90, 3100);
	stopMotors();
	wait10Msec(10);
	goBack(100, 800);
}

void startFromPositions() {

	  approachinFromLeft = 0;
	  approachingFromRight = 0;

	  switch (startPosition) {   // Global var
  	case 1:
  				moveTillDir7();
  				turnToDir4();
  				 //goBack(100,600);
  				break;
  	case 2:
  			  break;
  	default:
  				break;
  }
}

void fineTune() {
  alignAgainToDir4();
	goForward(70, 200);
	stopMotors();
  alignAgainToDir4();
  stopMotors();
}

void correctionForApproachBias() {
	int total = approachingFromLeft + approachingFromRight;
	if (diff < 0) {
		diff = -diff;
	}
	if (approachingFromLeft > a
}

task main ()
{

  tHTIRS2DSPMode _mode = DSP_1200;

  StartTask(ReadIR);
	ClearTimer(T1);

  ServoRotateSmooth(servo1, 128);

  startFromPositions();

  turnToDir4();
  stopMotors();
	wait10Msec(10);

  moveToDistance3();
	stopMotors();
	wait10Msec(10);

  fineTune();


  putTheRing();

  stopMotors();

  waitToSeeTheMessages();

}

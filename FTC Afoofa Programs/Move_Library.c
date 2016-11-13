#define SPIN_360 9000	//for ring it up tank drive bot
#define SPIN(x) ((SPIN_360/360)* x)

void Move(int MtrPwr_Left, int MtrPwr_Right, int waitInMSec)
{
 /*nMotorPIDSpeedCtrl[LeftFront] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[LeftBack] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[RightFront] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[RightBack] = mtrSpeedReg;*/

 motor[LeftFront] = MtrPwr_Left;
 motor[LeftBack] = MtrPwr_Left;
 motor[RightFront] = MtrPwr_Right;
 motor[RightBack] = MtrPwr_Right;

 wait1Msec(waitInMSec);

 motor[LeftFront] = 0;
 motor[LeftBack] = 0;
 motor[RightFront] = 0;
 motor[RightBack] = 0;

 nMotorPIDSpeedCtrl[LeftFront] = mtrNoReg;
 nMotorPIDSpeedCtrl[LeftBack] = mtrNoReg;
 nMotorPIDSpeedCtrl[RightFront] = mtrNoReg;
 nMotorPIDSpeedCtrl[RightBack] = mtrNoReg;
}

void RaiseSlideLift(int MtrPwr, int MtrDur)
{
 nMotorPIDSpeedCtrl[SlideLift] = mtrSpeedReg;
 nMotorEncoder[SlideLift] = 0;
 nMotorEncoderTarget[SlideLift] = MtrDur;
 motor[SlideLift] = MtrPwr;

 while (nMotorRunState[SlideLift] != runStateIdle)
 {
   //wait
 }

 motor[SlideLift] = 0;
 nMotorPIDSpeedCtrl[SlideLift] = mtrNoReg;
}

void RaiseArticArm(int MtrPwr, int MtrDur)
{
 nMotorPIDSpeedCtrl[ArticArm] = mtrSpeedReg;
 nMotorEncoder[ArticArm] = 0;
 nMotorEncoderTarget[ArticArm] = MtrDur;
 motor[ArticArm] = MtrPwr;

 while (nMotorRunState[ArticArm] != runStateIdle)
 {
   //wait
 }

 motor[ArticArm] = 0;
 nMotorPIDSpeedCtrl[ArticArm] = mtrNoReg;
}

void Move(int MtrPwr_Left, int MtrPwr_Right, int MtrDur_Left, int MtrDur_Right)
{
 nMotorPIDSpeedCtrl[LeftFront] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[LeftBack] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[RightFront] = mtrSpeedReg;
 nMotorPIDSpeedCtrl[RightBack] = mtrSpeedReg;

 nMotorEncoder[LeftFront] = 0;
 nMotorEncoder[LeftBack] = 0;
 nMotorEncoder[RightFront] = 0;
 nMotorEncoder[RightBack] = 0;

 nMotorEncoderTarget[LeftFront] = MtrDur_Left;
 nMotorEncoderTarget[LeftBack] = MtrDur_Left;
 nMotorEncoderTarget[RightFront] = MtrDur_Right;
 nMotorEncoderTarget[RightBack] = MtrDur_Right;

 motor[LeftFront] = MtrPwr_Left;
 motor[LeftBack] = MtrPwr_Left;
 motor[RightFront] = MtrPwr_Right;
 motor[RightBack] = MtrPwr_Right;

 while ( (nMotorRunState[RightFront] != runStateIdle) &&
   			(nMotorRunState[RightBack] != runStateIdle)  &&
   	    (nMotorRunState[LeftBack] != runStateIdle) &&
   	    (nMotorRunState[LeftFront] != runStateIdle) )
 {
   //wait
 }

 motor[LeftFront] = 0;
 motor[LeftBack] = 0;
 motor[RightFront] = 0;
 motor[RightBack] = 0;

 nMotorPIDSpeedCtrl[LeftFront] = mtrNoReg;
 nMotorPIDSpeedCtrl[LeftBack] = mtrNoReg;
 nMotorPIDSpeedCtrl[RightFront] = mtrNoReg;
 nMotorPIDSpeedCtrl[RightBack] = mtrNoReg;
}

void NonstopMove(int MtrPwr_Left, int MtrPwr_Right, int MtrDur_Left, int MtrDur_Right)
{
 nMotorEncoder[LeftFront] = 0;
 nMotorEncoder[LeftBack] = 0;
 nMotorEncoder[RightFront] = 0;
 nMotorEncoder[RightBack] = 0;

 nMotorEncoderTarget[LeftFront] = MtrDur_Left;
 nMotorEncoderTarget[LeftBack] = MtrDur_Left;
 nMotorEncoderTarget[RightFront] = MtrDur_Right;
 nMotorEncoderTarget[RightBack] = MtrDur_Right;

 motor[LeftFront] = MtrPwr_Left;
 motor[LeftBack] = MtrPwr_Left;
 motor[RightFront] = MtrPwr_Right;
 motor[RightBack] = MtrPwr_Right;

 while ( (nMotorRunState[RightFront] != runStateIdle) &&
   			(nMotorRunState[RightBack] != runStateIdle)  &&
   	    (nMotorRunState[LeftBack] != runStateIdle) &&
   	    (nMotorRunState[LeftFront] != runStateIdle) )
 {
   //wait
 }
}

void stopMotors()
{
 	motor[LeftFront] = 0;
 	motor[LeftBack] = 0;
 	motor[RightFront] = 0;
 	motor[RightBack] = 0;
}

void moveForTime (int powerLeft, int powerRight, int mSecs)
{
	motor[LeftFront] = powerLeft;
 	motor[LeftBack] = powerLeft;
 	motor[RightFront] = powerRight;
 	motor[RightBack] = powerRight;

 	wait1Msec(mSecs);
}

void MoveForward(int MtrPwr, int MtrDur)
{
 if(MtrPwr < 0)
     MtrPwr = MtrPwr * -1;
 if(MtrDur < 0)
     MtrDur = MtrDur * -1;

 Move(MtrPwr, MtrPwr, MtrDur, MtrDur);
}

void MoveBackward(int MtrPwr, int MtrDur)
{
 if(MtrPwr < 0)
     MtrPwr = MtrPwr * -1;
 if(MtrDur < 0)
     MtrDur = MtrDur * -1;

  Move(-MtrPwr, -MtrPwr, -MtrDur, -MtrDur);
}

void SpinRight(int MtrPwr, int MtrDur)
{
 if(MtrPwr < 0)
     MtrPwr = MtrPwr * -1;
 if(MtrDur < 0)
     MtrDur = MtrDur * -1;

  Move(-MtrPwr, MtrPwr, -MtrDur, MtrDur);
}

void SpinLeft(int MtrPwr, int MtrDur)
{
 if(MtrPwr < 0)
     MtrPwr = MtrPwr * -1;
 if(MtrDur < 0)
     MtrDur = MtrDur * -1;

  Move(MtrPwr, -MtrPwr, MtrDur, -MtrDur);
}

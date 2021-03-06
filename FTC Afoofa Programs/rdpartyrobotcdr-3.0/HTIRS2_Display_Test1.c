#pragma config(Sensor, S1,     HTIRS2,         sensorI2CCustom)
#pragma config(Motor,  motorB,          MotorB,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          MotorC,        tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivers/hitechnic-irseeker-v2.h"

task main()
{

  int _dirDC = 0;
  tHTIRS2DSPMode _mode = DSP_1200;

  while(1)
  	{
  		_dirDC = HTIRS2readDCDir(HTIRS2);
  		nxtDisplayTextLine(1, "%d", _dirDC);

  	}

}

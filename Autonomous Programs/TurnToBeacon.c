bool isTimeOut=false;

task myTimer() {
	int timeOutMsec = 2000;
	isTimeOut = false;
	wait1Msec(timeOutMsec);
	isTimeOut = true;
}

void TurnToBeaconTest()
{
	int dirAC = HTIRS2readACDir(DirIR);
  isTimeOut = false;
	StartTask(myTimer);

	while((dirAC != 4) && (!isTimeOut))
  {
  	motor[RightFront] = -50;
	  motor[RightBack] = -50;
		motor[LeftFront] = 50;
		motor[LeftBack] = 50;

		wait1Msec(1);
		dirAC = HTIRS2readACDir(DirIR);
	}

	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;
}

bool turnToBeacon() {

	int irDir = HTIRS2readACDir(DirIR);
	int irDist = HTIRS2readACDir(DistIR);
    nxtDisplayTextLine(0, "    Dir   Dist");
   	nxtDisplayTextLine(1, "D:  %d     %d   ", irDir,irDist );

	if(irDir == 0)
	{
		wait1Msec(5);
		irDir = HTIRS2readACDir(DirIR);
		if(irDir == 0)
			TurnToBeaconTest();
		//_spinRight(100, 1000);
		//wait1Msec(10);
	}
	else if(irDir > 5)
	{
		_spinRight(50, 1); //if left, spin right
	}
	else if(irDir == 5)
	{
		_spinRight(50, 1); //if slightly left, small spin right
	}
	else if(irDir == 4)
  {
  	stopMotors();

  	// wait1Msec(5000);
  	return true;
	}
	else if(irDir == 3)
	{
		_spinLeft(50, 1); //if slightly right, small spin left
	}
	else if(irDir < 3)
	{
		_spinLeft(50, 1); //if right, spin left
	}

	return false;
}

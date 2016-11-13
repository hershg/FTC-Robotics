void proceedInLargeSteps()
{
	int irDir = 0;
	//stopMotors();
  //wait10Msec(1);
	irDir = HTIRS2readACDir(DirIR);

	if(irDir > 5)
	{
		_spinRight(80, 25);//_spinRight(50, 200); //if left, spin right
	}
	else if(irDir == 5)
	{
		steer(100, 0, 50); //if slightly left, steer right//steer(70, 30, 100);
	}
	else if(irDir == 4)
  {
  	goForward(80, 50); //if aligned, move forward
	}
	else if(irDir == 3)
	{
		steer(0, 100, 50); //if slightly left, steer right//steer(30, 70, 100);
	}
	else if(irDir < 3)
	{
		_spinLeft(80, 25);//_spinLeft(50, 200); //if right, spin left

	}
	// stopMotors();
	//wait1Msec(5);
}

void proceedInSmallSteps()
{
	int irDir = 0;
  //stopMotors();
  //wait10Msec(1);
	irDir = HTIRS2readACDir(DirIR);
	if(irDir > 5)
	{
		_spinRight(80,25); // 50, 20); //if left, spin right
	}
	else if(irDir == 5)
	{
		steer(100, 0, 50);//steer(50, 45, 20); //if slightly left, steer right
	}
	else if(irDir == 4)
  {
  	goForward(80, 50);//goForward(50, 20); //if aligned, move forward
	}
	else if(irDir == 3)
	{
		goForward(80, 50);//steer(45, 50, 20); //if slightly right, steer left
	}
	else if(irDir < 3)
	{
		_spinLeft(80, 25);//_spinLeft(50, 20); //if right, spin left
	}
	// stopMotors();
	// wait1Msec(10);
}

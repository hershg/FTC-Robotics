void proceedInLargeSteps()
{
	int irDir = 0;

	irDir = HTIRS2readACDir(DirIR);
	if(irDir > 5)
	{
		spinLeft(100, 100); //if left, spin right
	}
	else if(irDir == 5)
	{
		steer(60, 100, 100); //if slightly left, steer right
	}
	elseif(irDir == 4)
  {
  	goForward(100, 100); //if aligned, move forward
	}
	else if(irDir == 3)
	{
		steer(100, 60, 100); //if slightly right, steer left
	}
	else if(irDir < 3)
	{
		spinRight(100, 100); //if right, spin left
	}

	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;
}

void proceedInSmallSteps()
{
	int irDir = 0;

	irDir = HTIRS2readACDir(DirIR);
	if(irDir > 5)
	{
		spinLeft(70, 20); //if left, spin right
	}
	else if(irDir == 5)
	{
		steer(45, 60, 20); //if slightly left, steer right
	}
	elseif(irDir == 4)
  {
  	goForward(60, 20); //if aligned, move forward
	}
	else if(irDir == 3)
	{
		steer(60, 45, 20); //if slightly right, steer left
	}
	else if(irDir < 3)
	{
		spinRight(70, 20); //if right, spin left
	}

	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;
}

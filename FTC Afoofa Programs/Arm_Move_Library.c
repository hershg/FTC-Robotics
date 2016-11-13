task ResetArticArm ()
{
	while(SensorValue[ArticArm_Touch] == 0)
  {
		motor[ArticArm] = -60;
		wait10Msec(1);
	}
	motor[ArticArm] = 0;
  nMotorEncoder[ArticArm] = 0;
}

task ResetSlideLift ()
{
	while(SensorValue[SlideLift_Touch] == 0 || nMotorEncoder[SlideLift] > 2000)
	{
		motor[SlideLift] = -100;
		wait10Msec(1);
  }
  motor[SlideLift] = 0;
  nMotorEncoder[SlideLift] = 0;
}

task RaiseArmToDisp ()
{

}

task RaiseArmTo1 ()
{

}

task RaiseArmTo2 ()
{

}

task RaiseArmTo3 ()
{

}

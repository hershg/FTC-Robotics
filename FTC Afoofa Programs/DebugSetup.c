task DebugSetup ()
{
  eraseDisplay();

  int  dirAC = 0;
	int distAC = 0;
	int  dirS1,  dirS2,  dirS3,  dirS4,  dirS5 = 0;
	int distS1, distS2, distS3, distS4, distS5 = 0;

	int FL;
	int FR;
	int BL;
	int BR;
	int SL;
	int AA;
  while(true)
  {
    // Read the current non modulated signal direction
     dirAC = HTIRS2readACDir(DirIR);
    if (dirAC < 0)
      break; // I2C read error occurred

    // read the current modulated signal direction
    distAC = HTIRS2readACDir(DistIR);
    if (distAC < 0)
      break; // I2C read error occurred

    // Read the individual signal strengths of the internal sensors
    // Do this for both Sensors
    if (!HTIRS2readAllACStrength( DirIR,  dirS1,  dirS2,  dirS3,  dirS4,  dirS5))
      break; // I2C read error occurred
    if (!HTIRS2readAllACStrength(DistIR, distS1, distS2, distS3, distS4, distS5))
      break; // I2C read error occurred

    //nxtDisplayTextLine(0, "    Dir   Dist");
   	nxtDisplayTextLine(3, "D:  %d     %d", dirAC, distAC);
   	/*
    nxtDisplayTextLine(2, "1:  %d    %d", dirS1, distS1);
    nxtDisplayTextLine(3, "2:  %d    %d", dirS2, distS2);
    nxtDisplayTextLine(4, "3:  %d    %d", dirS3, distS3);
    nxtDisplayTextLine(5, "4:  %d    %d", dirS4, distS4);
    nxtDisplayTextLine(6, "5:  %d    %d", dirS5, distS5);
    */

    /*if(nNxtButtonPressed == 1){
    	FL = motor[LeftFront];
    	BL = motor[LeftBack];
    	FR = motor[RightFront];
    	BR = motor[RightBack];
    	SL = motor[SlideLift];
    	AA = motor[ArticArm];

    	motor[LeftFront] = 0;
    	motor[LeftBack] = 0;
    	motor[RightFront] = 0;
    	motor[RightBack] = 0;
    	motor[SlideLift] = 0;
    	motor[ArticArm] = 0;

    	while(nNxtButtonPressed != 3){
    		wait10Msec(1);
    	}

    	motor[LeftFront] = FL;
    	motor[LeftBack] = BL;
    	motor[RightFront] = FR;
    	motor[RightBack] = BR;
    	motor[SlideLift] = SL;
    	motor[ArticArm] = AA;
    }*/

    wait10Msec(5);
  }
}

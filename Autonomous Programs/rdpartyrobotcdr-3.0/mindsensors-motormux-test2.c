#pragma config(Sensor, S1,     MSMMUX,              sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-motormux-test2.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * mindsensors-motormux.h provides an API for the Mindsensors Motor MUX. This program
 * demonstrates how to use that API to control the motors attached to the MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 30 May 2011
 * version 0.1
 */

#include "drivers/mindsensors-motormux.h"
#include "drivers/mindsensors-irdist.h"

// configure MSDIST to also be connected to S1 as well, through the MMUX
#define MSDIST S1

task main () {
  long encA  = 0;
  long encB  = 0;

  long distance = 0;
  long mindist = 0;
  long maxdist = 0;

  int motorSpeed = 0;

  eraseDisplay();
  MSMMUXinit();

  MSMotorStop(mmotor_S1_1);
  MSMotorStop(mmotor_S1_2);

  wait1Msec(500);

  // Reset the encoders.  This can be done individually or all at once.
  // You should do this at the start of your program.
  MSMMotorEncoderResetAll(MSMMUX);

  // Read the minimum distance the sensor can "see"
  mindist = MSDISTreadMinDist(MSDIST);

  // Read the maximum distance the sensor can "see"
  maxdist = MSDISTreadMaxDist(MSDIST);

  while (true) {
    distance = MSDISTreadDist(MSDIST);

    // Retrieve the motor-MUX's encoder counts
    encA = MSMMotorEncoder(mmotor_S1_1);
    encB = MSMMotorEncoder(mmotor_S1_2);

    // calculate the motor speed
    motorSpeed = ((distance - mindist) * 100) / (maxdist - mindist);

	  // Tell the motors to start moving.
	  MSMMotor(mmotor_S1_1, motorSpeed);
	  MSMMotor(mmotor_S1_2, motorSpeed);

		// Display the info.
		nxtDisplayTextLine(4, "D: %5d", distance);
		nxtDisplayTextLine(5, "A: %5d (%3d)", encA, motorSpeed);
		nxtDisplayTextLine(6, "B: %5d (%3d)", encB, motorSpeed);
    wait1Msec(20);
  }
}

/*
 * $Id: mindsensors-motormux-test2.c 112 2012-10-04 17:44:38Z xander $
 */

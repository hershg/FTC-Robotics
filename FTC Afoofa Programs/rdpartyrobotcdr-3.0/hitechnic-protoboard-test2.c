#pragma config(Sensor, S1,     HTPB,                sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-protoboard-test2.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * hitechnic-protoboard.h provides an API for the HiTechnic Protoboard.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "drivers/hitechnic-protoboard.h"

task main() {
  byte inputs = 0;

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "Proto");
  nxtDisplayCenteredTextLine(3, "Test 2");
  nxtDisplayCenteredTextLine(5, "Connect HTPB");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

  while(true) {
    eraseDisplay();
    // Fetch the state of the digital IO pins.  When not explicitly
    // configured as input or output, they will default to input.
    inputs = HTPBreadIO(HTPB, 0x3F);
    nxtDisplayTextLine(4, "D: 0x%x", (int)inputs);
    wait1Msec(100);
  }
}

/*
 * $Id: hitechnic-protoboard-test2.c 112 2012-10-04 17:44:38Z xander $
 */

#pragma config(Sensor, S1,     DFLEX,               sensorAnalogInactive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: dexterind-flex-test2.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * dexterind-flex.h provides an API for the Dexter Industries dFlex Sensor.  This program
 * demonstrates how to use that API to calibrate the sensor.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 23 June 2010
 * version 0.1
 */

#include "drivers/dexterind-flex.h"

task main () {
  int raw = 0;
  int nrm = 0;
  // Get control over the buttons
  nNxtButtonTask  = -2;

  eraseDisplay();
  nxtDisplayTextLine(0, "Dexter Industries");
  nxtDisplayCenteredBigTextLine(1, "dFlex");
  nxtDisplayCenteredTextLine(3, "Test 2");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

  eraseDisplay();
  nxtDisplayTextLine(0, "dFlex Calibration");
  nxtDisplayTextLine(2, "Left:  set min");
  nxtDisplayTextLine(3, "Right: set max");
  nxtDisplayTextLine(7, "Grey:  exit");

  while (true) {
    switch(nNxtButtonPressed) {
      // if the left button is pressed calibrate the black value for the sensor
      case kLeftButton:
                        DFLEXcalLow(DFLEX);
                        PlaySound(soundBeepBeep);
                        while(bSoundActive) EndTimeSlice();
                        break;

      // if the left button is pressed calibrate the white value for the sensor
      case kRightButton:
                        DFLEXcalHigh(DFLEX);
                        PlaySound(soundBeepBeep);
                        while(bSoundActive) EndTimeSlice();
                        break;
    }

    nxtDisplayClearTextLine(5);
    nxtDisplayClearTextLine(6);

    // Read the raw value of the sensor
    raw = DFLEXvalRaw(DFLEX);

    // Read the normalised value of the sensor
    nrm = DFLEXvalNorm(DFLEX);

    // Display the raw and normalised values
    nxtDisplayTextLine(5, "R: %4d N: %4d", raw, nrm);

    // Display the values for black and white
    nxtDisplayTextLine(6, "B: %4d W: %4d", dflexlow, dflexhigh);
    wait1Msec(50);
  }
}

/*
 * $Id: dexterind-flex-test2.c 112 2012-10-04 17:44:38Z xander $
 */

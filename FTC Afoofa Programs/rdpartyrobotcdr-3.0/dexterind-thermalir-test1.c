#pragma config(Sensor, S1,     TIR,                 sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: dexterind-thermalir-test1.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * dexterind-thermalir.h provides an API for the Dexter Industries Thermal Infrared Sensor.  This program
 * demonstrates how to use that API.
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
 * 10 June 2011
 * version 0.1
 */

#include "drivers/dexterind-thermalir.h"

task main () {
  float ambient = 0;
  float object = 0;

  nxtDisplayCenteredTextLine(0, "Dexter Industries");
  nxtDisplayCenteredTextLine(1, "Thermal Infrared");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

	eraseDisplay();

  // set emissivity for light skin
  TIRsetEmissivity(TIR, TIR_EM_SKIN_LIGHT);
  wait1Msec(200);

  //emissivity = TIRreadEmissivity(TIR);
  //nxtDisplayTextLine(5, "0x%04X", emissivity);
  while (true) {

    // Read the currently detected ambient and object temp from the sensor
    ambient = TIRreadAmbientTemp(TIR);
    object = TIRreadObjectTemp(TIR);

    nxtDisplayTextLine(1, "A: %3.2f", ambient);
    nxtDisplayTextLine(3, "O: %3.2f", object);
    wait1Msec(100);
  }
}

/*
 * $Id: dexterind-thermalir-test1.c 112 2012-10-04 17:44:38Z xander $
 */

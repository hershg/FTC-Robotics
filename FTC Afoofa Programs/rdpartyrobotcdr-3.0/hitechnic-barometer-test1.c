#pragma config(Sensor, S1,     HTBM,                sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-barometer-test1.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * hitechnic-barometer.h provides an API for the HiTechnic Barometric Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h from includes
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 30 October 2010
 * version 0.1
 */

#include "drivers/hitechnic-barometer.h"

task main () {

  int pressmInHg = 0;
  float presshPa = 0.0;
  float pressPsi = 0.0;
  float tempC = 0.0;
  float tempF = 0.0;

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "BaroTemp");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

  //PlaySound(soundBeepBeep);
  //while(bSoundActive);

  while (true) {
    eraseDisplay();

    // Read the sensor's data
		pressmInHg = HTBMreadMInHg(HTBM);   // Pressure in 1/1000th of an inch Hg
		presshPa = HTBMreadhPa(HTBM);       // Pressure in hecto Pascal
		pressPsi = HTBMreadPsi(HTBM);       // Pressure in Pounds per square inch
		tempC = HTBMreadTemp(HTBM);         // Temp in Celcius
		tempF = HTBMreadTempF(HTBM);        // Temp in Fahrenheit

    nxtDisplayCenteredTextLine(0, "HTBM Test 1");
    nxtDisplayTextLine(2, "%5d mInHg", pressmInHg);
    nxtDisplayTextLine(3, "%5.1f hPa", presshPa);
    nxtDisplayTextLine(4, "%5.1f PSI", pressPsi);
    nxtDisplayTextLine(6, "%3.1f C / %3.1f F", tempC, tempF);
    nxtDrawLine(0, 52, 99, 52);
    nxtDrawLine(0, 20, 99, 20);
    wait1Msec(100);
  }
}

/*
 * $Id: hitechnic-barometer-test1.c 112 2012-10-04 17:44:38Z xander $
 */

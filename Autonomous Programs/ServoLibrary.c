

void ServoReset0 (TServoIndex Servo1,
                  unsigned int ServoPos = 0,
                  unsigned int changeRate = 15)

{
     servoChangeRate[Servo1] = changeRate;
     servoTarget[Servo1] = ServoPos;
     wait1Msec(1000);


     while (servoTarget[Servo1] > ServoPos)
     {
        nxtDisplayTextLine(3, "Servo Value: %d", ServoValue[Servo1]);
        wait1Msec(50);
    }

    nxtDisplayTextLine(3, "Servo: 0",);
    wait1Msec(100);
}

void ServoReset255 (TServoIndex Servo1,
                    unsigned int ServoPos = 255,
                    unsigned int changeRate = 10,)
{

     servoChangeRate[Servo1] = changeRate;
    servoTarget[Servo1] = ServoPos;
    wait1Msec(1000);

   while (servoTarget[Servo1] > ServoPos)
      {
          nxtDisplayTextLine(3, "Servo Value: %d", ServoValue[Servo1]);
          wait1Msec(50);
      }
    nxtDisplayTextLine(3, "Servo: 255",);
    wait1Msec(100);
}
void ServoRotate(TServoIndex Servo1,
                  unsigned int DesirePos, //Servo ticks
                  unsigned int changerate = 10,)
{
     servoChangeRate[Servo1] = changerate;
     servoTarget[Servo1] = DesirePos;
     wait1Msec(1500);

      while (servoTarget[Servo1] != DesirePos)
     {
        nxtDisplayTextLine(3, "Servo Value: %d", ServoValue[Servo1]);
        wait1Msec(100);
    }

    nxtDisplayTextLine(3, "Servo: %d", Servo1);
    wait1Msec(100);

}


void ServoRotateSmooth(TServoIndex Servo1,
                       unsigned int DesirePos, //Servo ticks
                       unsigned int changerate = 2,)
{
     servoChangeRate[Servo1] = changerate;
     servoTarget[Servo1] = DesirePos;
     wait1Msec(1500);

      while (servoTarget[Servo1] != DesirePos)
     {
        nxtDisplayTextLine(3, "Servo Value: %d", ServoValue[Servo1]);
        wait1Msec(100);
    }

    nxtDisplayTextLine(3, "Servo: %d", Servo1);
    wait1Msec(100);

}


void ServoRotateIncremental255 (TServoIndex Servo1,
                             int ServoPos,
                             unsigned int changerate = 5,)
{
int a = ServoValue[Servo1];

	   servoChangeRate[Servo1] = changerate;
	   servoTarget[Servo1] = a + abs(ServoPos) * (255/180);
	   wait1Msec(1000);

	   nxtDisplayTextLine(3, "Servo: ServoPos degrees to 255", Servo1);

}


void ServoRotateIncremental0 (TServoIndex Servo1,
                              int ServoPos,
                              unsigned int changerate = 5,)
{
	int a = ServoValue[Servo1];

	    servoChangeRate[Servo1] = changerate;
	    servoTarget[Servo1] = a - abs(ServoPos) * (255/180);
	    wait1Msec(1000);

	    nxtDisplayTextLine(3, "Servo: ServoPos degrees to 0", Servo1);

}

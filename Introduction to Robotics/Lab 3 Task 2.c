#pragma config(Sensor, S1, soundSensor, sensorSoundDB)
task main()
{
		while (true)
		{
		eraseDisplay();
		displayTextLine (1, "%d", SensorValue[S1]);
		wait1Msec(1000);
		if (SensorValue[S1] > 35)
		{
			motor[motorA]= 30; // Turn motor A on 50%
			motor[motorC]= 30; // Turn Motor C on 50%
			wait1Msec (5000); // Delay
			bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
			motor[motorA]= 0; // Turn Motor A off
			motor[motorC]= 0; // Turn Motor C off
			//for it to turn around exactly 180 degrees, sync motors
			motor[motorA]= 30; // Turn motor A on 50% (Turn around)
			motor[motorC]= -30; // Turn Motor C off
			wait1Msec (1600); // Delay
			motor[motorA]= 0; // Turn Motor A off
			wait1Msec (500); // Delay
			motor[motorA]= 30; // Turn motor A on 50%
			motor[motorC]= 30; // Turn Motor C on 50%
			wait1Msec (5000); // Delay
			//for it to turn around exactly 180 degrees, sync motors
			motor[motorA]= 30; // Turn motor A on 50% (Turn around)
			motor[motorC]= -30; // Turn Motor C off
			wait1Msec (1600); // Delay
			motor[motorA]= 0; // Turn Motor A off
			wait1Msec (500); // Delay
			break;
		}	// end if
		} //end while
}

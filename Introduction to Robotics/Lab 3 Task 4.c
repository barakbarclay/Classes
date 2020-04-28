#pragma config(Sensor, S1, soundSensor, sensorSoundDB)
#pragma config(Sensor, S2, touchSensor, sensorTouch)
task main()
{
	// In order to fix the sound sensor, and maybe the touch sensor, from reading wrong values at first
	//Set a int temp =0;
	//wait time then set int temp = SensorValue[S1];
	//wait time
	// also set if paramenters to react to temp instead of SensorValue
	int degrees = 0;
	int crash_count = 0;
	degrees = rand() % (2800-800) + 800;
		while (true)
		{
		eraseDisplay();
		displayTextLine (1, "%d", SensorValue[S1]);
		wait1Msec(1000);
		if (SensorValue[S1] > 35)
		{
		while (true)
		{
			nSyncedMotors = synchAC;
			nSyncedTurnRatio = 100;
			motor[motorA]= 30; // Turn motor A on 50%
			bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
				if (SensorValue[S2] == 1)
				{
					crash_count++;
					displayTextLine (2, "%d", crash_count);
					playSound(soundUpwardTones);  //Plays the sound "Upward Tones"
					motor[motorA]= 0; // Turn Motor A off
					wait1Msec (1600); // Delay
					motor[motorA]= -50; // Turn motor A on 50% (Turn around)
					wait1Msec (1000); // Delay
					nSyncedTurnRatio = -100;
					motor[motorA]= 30; // Turn motor A on 50% (Turn around)
					wait1Msec (degrees); // Delay
					motor[motorA]= 0; // Turn Motor A off
					wait1Msec (500); // Delay
			} //end 2nd if
		} //end 2nd while
		}	// end 1st if
		} //end 1st while
}

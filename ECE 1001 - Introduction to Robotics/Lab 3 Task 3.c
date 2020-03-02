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
			nSyncedMotors = synchAC;
			nSyncedTurnRatio = 100;
			motor[motorA]= 30; // Turn motor A on 50%
			wait1Msec (5000); // Delay
			bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
			motor[motorA]= 0; // Turn Motor A off
			nSyncedTurnRatio = -100;
			motor[motorA]= 30; // Turn motor A on 50% (Turn around)
			wait1Msec (1600); // Delay
			motor[motorA]= 0; // Turn Motor A off
			wait1Msec (500); // Delay
			nSyncedTurnRatio = 100;
			motor[motorA]= 30; // Turn motor A on 50%
			wait1Msec (5000); // Delay
			nSyncedMotors = synchAC;
			nSyncedTurnRatio = -100;
			motor[motorA]= 30; // Turn motor A on 50% (Turn around)
			wait1Msec (1600); // Delay
			motor[motorA]= 0; // Turn Motor A off
			wait1Msec (500); // Delay
			playSound(soundUpwardTones);  //Plays the sound "Upward Tones"
			wait1Msec (2300); // Delay
		}	// end if
		} //end while
}

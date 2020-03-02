#pragma config(Sensor, S1, soundSensor, sensorSoundDB)
task main()
{
while(true)
	{
		eraseDisplay();
		displayTextLine (1, "Sound Level:", SensorValue(S1));
		if (SensorValue(S1) <= 33)
		{
			displayTextLine (2, "Quiet", SensorValue[S1]);
		}

		if ((SensorValue(S1) <= 66)&&(SensorValue(S1) > 33))
		{
			displayTextLine (2, "Noisy", SensorValue[S1]);
		}

		if ((SensorValue(S1) <= 100)&&(SensorValue(S1) > 66))
		{
			displayTextLine (2, "Loud", SensorValue[S1]);
		}
 		wait1Msec (100); // Delay
	}//while

}

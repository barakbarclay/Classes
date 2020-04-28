#pragma config(Sensor, S1, USSensor, sensorSONAR)

task main()
{
	while (true)
	{
		float distance_in = 0.0;
		distance_in = SensorValue[S1]/2.54;
		eraseDisplay();
		displayTextLine (1, "%d", SensorValue[S1]);
		displayTextLine (2, "%d", distance_in);
		if (SensorValue[S1] < 10)
		{
			playSoundFile("danger_x.rso");
		}
		wait1Msec(1000);
	}

}

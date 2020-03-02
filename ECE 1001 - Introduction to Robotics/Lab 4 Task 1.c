#pragma config(Sensor, S1, USSensor, sensorSONAR)

task main()
{
	while (true)
	{
		eraseDisplay();
		displayTextLine (1, "%d", SensorValue[S1]);
		displayTextLine (2, "%d", distance_in);
		wait1Msec(1000);
	}
}

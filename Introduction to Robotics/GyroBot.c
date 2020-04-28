const tSensors GyroSensor				= (tSensors) S1; //gyro sensor//

#define offset 600			//offset value may vary depending on sensor & temerature

task main()
{
long Gyro_value;		//a large interger number

	while(true)
	{
		Gyro_value = SensorValue(GyroSensor) - offset; //read the gyro sensor

		displayBigTextLine(4, "%d", Gyro_value);
	}

}

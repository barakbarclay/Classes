const tSensors GyroSensor				= (tSensors) S1; //gyro sensor//

#define offset 0			//offset value may vary depending on sensor & temerature

task main()
{
long Gyro_value;		//a large interger number
int lowFreq = 2000;
int highFreq = 4000;
int playFreq = 0;

	while(true)
	{
		playFreq = lowFreq + Gyro_value * 100;

		Gyro_value = SensorValue(GyroSensor) - offset; //read the gyro sensor

		displayBigTextLine(4, "%d", Gyro_value);

		playTone(playFreq, 20);
	}

}

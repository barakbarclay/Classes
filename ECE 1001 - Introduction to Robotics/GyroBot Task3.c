const tSensors GyroSensor				= (tSensors) S1; //gyro sensor//

#define offset 0			//offset value may vary depending on sensor & temerature

task main()
{
long Gyro_value;		//a large interger number
int lowFreq = 2000;
//int highFreq = 4000;
int playFreq = 0;
long maxValue = 0;
	while(true)
	{

		motor[motorA] = -100;
		if (SensorValue[motorC] <=50)
			{
				motor[motorC] = rand()%50 + 50;
			}
		if (SensorValue[motorC] > 50)
			{
				motor[motorC] = rand()%50;
			}

		//playFreq = lowFreq + ( (highFreq-lowFreq)/40) * Gyro_value;
		playFreq = lowFreq + Gyro_value * 100;

		Gyro_value = SensorValue(GyroSensor) - offset; //read the gyro sensor

		//if(Gyro_value > maxValue)
		//{
		//	maxValue = Gyro_value;
		//}

		displayBigTextLine(4, "%d", Gyro_value);
		displayBigTextLine(6, "%d", maxValue);

		playTone(playFreq, 20);

	}

}

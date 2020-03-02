const tSensors Gyro_Sensor				= (tSensors) S1; //gyro sensor//

task main()
{
		int First_Gyro_Value = SensorValue[Gyro_Sensor];
		int Current_Gyro_Value = 0;
		int Degrees = 90;
		float Current_Degree = 0;
		int PlayFreq = 0;
		int LowFreq = 2000;
		displayTextLine(1, "%d", First_Gyro_Value);

		motor[motorA] = 55;
		motor[motorB] = -55;

    while (abs(Current_Degree) < abs(Degrees))
    {
      wait1Msec(10);
      Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      displayTextLine(2, "%d", Current_Gyro_Value);
      displayTextLine(3, "%d", Degrees);
      displayTextLine(4, "%d", Current_Degree);
      Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	PlayFreq = LowFreq + Current_Gyro_Value * 100;
			playTone(PlayFreq, 20);
    }

   motor[motorA] = 0;
   motor[motorB] = 0;
   Current_Gyro_Value = 0;
   Current_Degree = 0;
   Degrees = 720;
   PlayFreq = 0;
   wait1Msec(2000);

   motor[motorA] = -100;
   motor[motorB] = 100;

   while (abs(Current_Degree) < abs(Degrees))
   {
      wait1Msec(10);
      Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      displayTextLine(2, "%d", Current_Gyro_Value);
      displayTextLine(3, "%d", Degrees);
      displayTextLine(4, "%d", Current_Degree);
      Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	PlayFreq = LowFreq + Current_Gyro_Value * 100;
			playTone(PlayFreq, 20);
   }

   motor[motorA] = 0;
   motor[motorB] = 0;
   wait1Msec(1000);

   Current_Gyro_Value = 0;
   Current_Degree = 0;
   Degrees = 90;
   PlayFreq = 0;
   wait1Msec(1000);

   motor[motorA] = 55;
   motor[motorB] = -55;

   while (abs(Current_Degree) < abs(Degrees))
   {
      wait1Msec(10);
      Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      displayTextLine(2, "%d", Current_Gyro_Value);
      displayTextLine(3, "%d", Degrees);
      displayTextLine(4, "%d", Current_Degree);
      Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	PlayFreq = LowFreq + Current_Gyro_Value * 100;
			playTone(PlayFreq, 20);
   }

   motor[motorA] = 0;
   motor[motorB] = 0;
   wait1Msec(2000);

}

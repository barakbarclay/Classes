const tSensors Gyro_Sensor				= (tSensors) S1; //gyro sensor//

task main()
{
		int Threshold = 0;
		int Delta = 80;
		int UpperThreshold =0;
		int LowerThreshold =0;

		//int Degrees = 90;
		//float Current_Degree = 0;
		//int PlayFreq = 0;
		//int LowFreq = 2000;


		//motor[motorA] = 55;
		//motor[motorB] = -55;

    //while (abs(Current_Degree) < abs(Degrees))
    //{
      //wait1Msec(10);
      //Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      //displayTextLine(2, "%d", Current_Gyro_Value);
      //displayTextLine(3, "%d", Degrees);
      //displayTextLine(4, "%d", Current_Degree);
      //Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	//PlayFreq = LowFreq + Current_Gyro_Value * 100;
			//playTone(PlayFreq, 20);
    //}

   //motor[motorA] = 0;
   //motor[motorB] = 0;
   //Current_Gyro_Value = 0;
   //Current_Degree = 0;
   //Degrees = 720;
   //PlayFreq = 0;
   //wait1Msec(2000);

   //motor[motorA] = -100;
   //motor[motorB] = 100;

   //while (abs(Current_Degree) < abs(Degrees))
   //{
      //wait1Msec(10);
      //Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      //displayTextLine(2, "%d", Current_Gyro_Value);
      //displayTextLine(3, "%d", Degrees);
      //displayTextLine(4, "%d", Current_Degree);
      //Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	//PlayFreq = LowFreq + Current_Gyro_Value * 100;
			//playTone(PlayFreq, 20);
   //}

   //motor[motorA] = 0;
   //motor[motorB] = 0;
   //wait1Msec(1000);

   //Current_Gyro_Value = 0;
   //Current_Degree = 0;
   //Degrees = 90;
   //PlayFreq = 0;
   //wait1Msec(1000);

   //motor[motorA] = 55;
   //motor[motorB] = -55;

   //while (abs(Current_Degree) < abs(Degrees))
   //{
      //wait1Msec(10);
      //Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
      //displayTextLine(2, "%d", Current_Gyro_Value);
      //displayTextLine(3, "%d", Degrees);
      //displayTextLine(4, "%d", Current_Degree);
      //Current_Degree = Current_Degree + Current_Gyro_Value*.01;
     	//PlayFreq = LowFreq + Current_Gyro_Value * 100;
			//playTone(PlayFreq, 20);
   //}

   motor[motorA] = 0;
   motor[motorB] = 0;
   wait1Msec(500);

   	motor[motorA] = 20;
		motor[motorB] = -20;
		wait1Msec(1500);
		int First_Gyro_Value = SensorValue[Gyro_Sensor];
		displayBigTextLine(2, "%d", First_Gyro_Value);
		int Current_Gyro_Value = 0;
		int x = time100[T1];
   	int Motor_Speed = 0;
   	int Motor_Speed_2 = 0;
		int Current_Motor_SpeedA = 20;
		int Current_Motor_SpeedB = -20;
		Threshold = First_Gyro_Value;
		UpperThreshold = Threshold + Delta;
		LowerThreshold = Threshold - Delta;
		while(x < 18000)
		{
			if (Current_Gyro_Value <= LowerThreshold || Current_Gyro_Value >= Threshold)
			{
				Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
				displayBigTextLine(4, "%d", Current_Gyro_Value);
				Motor_Speed++;
				Current_Motor_SpeedA = Current_Motor_SpeedA + Motor_Speed;
				Current_Motor_SpeedB = Current_Motor_SpeedB - Motor_Speed;
				motor[motorA] = Current_Motor_SpeedA;
				motor[motorB] = Current_Motor_SpeedB;
				wait1Msec(500);
			}

			if (Current_Gyro_Value >= UpperThreshold || Current_Gyro_Value < Threshold)
			{
				Current_Gyro_Value = SensorValue[Gyro_Sensor] - First_Gyro_Value;
				displayBigTextLine(4, "%d", Current_Gyro_Value);
				Motor_Speed++;
				Current_Motor_SpeedA = Current_Motor_SpeedA - Motor_Speed_2;
				Current_Motor_SpeedB = Current_Motor_SpeedB + Motor_Speed_2;
				motor[motorA] = Current_Motor_SpeedA;
				motor[motorB] = Current_Motor_SpeedB;
				wait1Msec(500);
			}
		}

}

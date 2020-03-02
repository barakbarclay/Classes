#pragma config(Sensor, S1, USSensor, sensorSONAR)
#pragma config(Sensor, S4, touchSensor, sensorTouch)

task main()
{
	while (SensorValue[S1] < 120)
	{
		motor[motorC]= -30;
		motor[motorA]= 30; // Turn motor A on 50%
		bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
		if (SensorValue[S4] == 1)
			{
				playSoundFile("danger_x.rso");
				motor[motorA]= 0; // Turn Motor A off
				motor[motorC]= 0;
				wait1Msec (1000); // Delay
			}
	}
	motor[motorC]= -30;
	motor[motorA]= 30; // Turn motor A on 50%
	wait1Msec (300); // Delay
	motor[motorA]= 0; // Turn Motor A off
	motor[motorC]= 0;
	wait1Msec (1600); // Delay
	motor[motorC]= 30;
	motor[motorA]= 30; // Turn motor A on 50% (Turn around)
	wait1Msec (5000); // Delay
	motor[motorA]= 0; // Turn Motor A off
}


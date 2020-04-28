task main()
{
motor[motorA]= 50; // Turn motor A on 50%
motor[motorC]= 50; // Turn Motor C on 50%
wait1Msec (3250); // Delay
bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
motor[motorA]= 0; // Turn Motor A off
motor[motorC]= 0; // Turn Motor C off
nMotorEncoder [motorA] = 0;
while (nMotorEncoder [motorA] < 900)
{
	motor[motorA]= 50;
	displayTextLine (1, "%d", nMotorEncoder[motorA]);
	displayTextLine (2, "%d", nMotorEncoder[motorC]);
}
motor[motorA]= 0; // Turn Motor A off
wait1Msec (800); // Delay
wait1Msec (500); // Delay
motor[motorA]= 50; // Turn motor A on 50%
motor[motorC]= 50; // Turn Motor C on 50%
wait1Msec (3250); // Delay
motor[motorA]= 0; // Turn Motor A off
motor[motorC]= 0; // Turn Motor C off
}

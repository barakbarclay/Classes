task main()
{
motor[motorA]= 50; // Turn motor A on 50%
motor[motorC]= 50; // Turn Motor C on 50%
wait1Msec (3500); // Delay
bFloatDuringInactiveMotorPWM = false; //motors will brake when power is set to "0"
motor[motorA]= 0; // Turn Motor A off
motor[motorC]= 0; // Turn Motor C off
motor[motorA]= 50; // Turn motor A on 50% (Turn around)
wait1Msec (1800); // Delay
motor[motorA]= 0; // Turn Motor A off
wait1Msec (500); // Delay
motor[motorA]= 50; // Turn motor A on 50%
motor[motorC]= 50; // Turn Motor C on 50%
wait1Msec (3500); // Delay
motor[motorA]= 0; // Turn Motor A off
motor[motorC]= 0; // Turn Motor C off
}

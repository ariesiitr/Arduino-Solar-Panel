#include <Servo.h>  //include servo library

 // initializing the angles of servo motors
Servo SMTB;
int SMTB_Angle = 0;  
Servo SMLR;
int SMLR_Angle = 0;

// set the pins with LDR sensors
int LDR1 = 1; //top right LDR
int LDR2 = 2; //top left LDR
int LDR3 = 3; // bottom left LDR
int LDR4 = 4; // bottom right LDR
int Threshold_low = 20;    //setting the threshold 
void setup ()
{
SMTB.attach(5);
SMTB.write(0);
SMLR.attach(6);
SMLR.write(0);
delay(500);
}
void loop()
{
SMTB_Angle = SMTB.read();    // reading the initial angles
SMLR_Angle = SMLR.read();

//taking the input from the sun as analog input 
int ANA_LDR1 = analogRead(1);       
int ANA_LDR2 = analogRead(2);
int ANA_LDR3 = analogRead(3);
int ANA_LDR4 = analogRead(4);
int AVG_TOP = (ANA_LDR2 + ANA_LDR1)/2;
int AVG_BOT = (ANA_LDR3 + ANA_LDR4)/2;
int AVG_LEFT = (ANA_LDR2 + ANA_LDR3)/2;
int AVG_RIGHT = (ANA_LDR1 + ANA_LDR4)/2;
int DIFF_TB = (AVG_TOP - AVG_BOT);
int DIFF_LR = (AVG_LEFT - AVG_RIGHT);

 // checking the conditions
if(abs(DIFF_TB)> Threshold_low){     
if(DIFF_TB > 0 ){
SMTB.write(SMTB_Angle + 1);       //we are giving the command to move the servo if the above conditon is satisfied.
}
else {
SMTB.write(SMTB_Angle - 1);
}
}else {
SMTB.write(SMTB_Angle);
}
if(abs(DIFF_LR)> Threshold_low){
if(DIFF_LR > 0 ){
SMLR.write(SMLR_Angle + 1) ;
}
else {
SMLR.write(SMLR_Angle - 1) ;
}
}else {
SMLR.write(SMLR_Angle);
}
}

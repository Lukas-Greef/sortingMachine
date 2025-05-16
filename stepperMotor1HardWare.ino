
//pin definition stepperMotor1

const int stepPin1 = 6; 
const int dirPin1 = 5;
const int enPin1 = 7;

void stepperMotor1HardWareSetup()
{
  // Sets the two pins as Outputs
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW);
}

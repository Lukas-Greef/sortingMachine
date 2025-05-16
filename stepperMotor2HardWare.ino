//ook hier de pinbezetting en definition wegschrijven
//ook een set-up functie schrijven die aangeroepen kan worden in de main
const int stepPin2 = 3;  //was 6
const int dirPin2 = 2;   //was 5
const int enPin2 = 7;    //was 7

void stepperMotor2HardWareSetup()
{
  // Sets the two pins as Outputs
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enPin2,OUTPUT);
  digitalWrite(enPin2,LOW);
}
void stepperMotor2ToContainer()//steppermotor 2 transport skittle to container for destinated colour
{
  for (int x = 0; x < numberOffSteps; x++)
  {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare 
  }
}

void stepperMotor2ReturnToBase()
{
  if (directionStepperMotor2 == 1)
  {
    Serial.println("directionStepperMotor2ReturnToBase = CW");
    digitalWrite(dirPin2, LOW);
  }
  if (directionStepperMotor2 == 2)
  {
    Serial.println("directionStepperMotor2ReturnToBase = CCW");
    digitalWrite(dirPin2, HIGH);
  }
  for (int x = 0; x < numberOffSteps; x++)
  {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare 
  }
  numberOffSteps = 0;
}
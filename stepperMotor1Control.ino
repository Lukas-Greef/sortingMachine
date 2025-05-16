const int rateStepperMotor1 = 170000; 

void stepperMotor1Fase1()//steppermotor 1 transport skittle from inputbuffer to colorsensor
{
  digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction. LOW:CW HIGH:CCW
  
  for (int x = 0; x < 51; x++) //voor x geldt: 0_200 komt overeen met 0_360 graden
  {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare 
  }
}

void stepperMotor1Fase2()//steppermotor 1 transport skittle to outputbuffer
{
    digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction. Low:CW HIGH:CCW
    for (int x = 0; x < 49; x++) //voor x geldt: 0_200 komt overeen met 0_360 graden
  {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare 
  }
}

void stepperMotor1Fase3()//steppermotor 1 return to inputbuffer
{
      digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction. Low:CW HIGH:CCW
    for (int x = 0; x < 100; x++) //voor x geldt: 0_200 komt overeen met 0_360 graden
  {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(rateStepperMotor1);//parameter is de snelheid. Uit experiment is 500 het hoogst haalbare 
  }
}

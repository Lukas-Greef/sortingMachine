int frequency = 0; //Variable to save the data coming from the sensorOut

void colourSensorHardWareSetup()
{
  pinMode (s0, OUTPUT); //The pins S0 & S1 works for the frequency scaling
  pinMode (s1, OUTPUT);
  pinMode (s2, OUTPUT);
  pinMode (s3, OUTPUT);
  pinMode (sensorOut, INPUT); //Using at 100%
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}


int getTheColor() 
{
  delay(200); //waiting for the skittle for a static moment / not moving
  //---Read RED values... S2 LOW - S3 LOW---
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  frequency = pulseIn(sensorOut, LOW);

  int redValue = frequency;
  int detectRedValue = redValue;

  Serial.print("R=");
  Serial.print(redValue);
  Serial.print("  ");

  delayMicroseconds(5);

  //---Read Green values ... S2 LOW - S3 HIGH---
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  frequency = pulseIn(sensorOut, LOW);

  int greenValue = frequency;
  int detectGreenValue = greenValue;

  Serial.print("G=");
  Serial.print(greenValue);
  Serial.print("  ");

  delayMicroseconds(5);

  //---Read Blue values ... S2 HIGH - S3 LOW---
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  frequency = pulseIn(sensorOut, LOW);

  int blueValue = frequency;
  int detectBlueValue = blueValue;

  Serial.print("B=");
  Serial.print(blueValue);
  Serial.print("  ");

  delayMicroseconds(5);

    //---Read Clear values ... S2 HIGH - S3 HIGH---
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  
  frequency = pulseIn(sensorOut, LOW);

  int clearValue = frequency ;
  int detectClearValue = clearValue;

  Serial.print("C=");
  Serial.print(clearValue);
  Serial.println("  ");
  delayMicroseconds(5);
}
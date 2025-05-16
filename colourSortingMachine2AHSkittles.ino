//stepperMotor1
/*
const int stepPin1 = 6;  //was 3
const int dirPin1 = 5;   //was 2
const int enPin1 = 7;    //was 4
*/
extern const int stepPin1;
extern const int dirPin1;
extern const int enPin1;
//stepperMotor2
/*
const int stepPin2 = 3;  //was 6
const int dirPin2 = 2;   //was 5
const int enPin2 = 7;    //was 7
*/
extern const int stepPin2;
extern const int dirPin2;
extern const int enPin2;

//Define the pins of the color sensor
#define s0 8
#define s1 9
#define s2 10 
#define s3 11
#define sensorOut 12

int numberOffSteps = 0;
int directionStepperMotor2 =0;
byte identifiedColor = 0; // Variable to save the color
int detectBlueValue = 0;
int detectGreenValue = 0;
int detectClearValue = 0;
int timeBetweenActions = 500;
bool isRunning = false;



void setup() 
{ 

  Serial.begin(9600); 
  Serial.println("Wil je het programma starten? Typ 'ja' en druk op enter.");

  while (true) {
    if (Serial.available() > 0) {
      String input = Serial.readStringUntil('\n'); // Lees de input
      input.trim(); // Verwijder spaties en enters

      if (input == "ja") {
        isRunning = true;
        Serial.println("Programma start...");
        break; // Verlaat de while-loop en ga verder met de code
      } else {
        Serial.println("Typ 'ja' om te starten.");
      }
    }
  }
  stepperMotor1HardWareSetup();
  //stepperMotor1
  /*
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW); 
  */
  stepperMotor2HardWareSetup();
  //stepperMotor2
  /*
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enPin2,OUTPUT);
  digitalWrite(enPin2,LOW);
  */
  //Set the pins of the Color Sensor
  colourSensorHardWareSetup();
  /*
  pinMode (s0, OUTPUT); //The pins S0 & S1 works for the frequency scaling
  pinMode (s1, OUTPUT);
  pinMode (s2, OUTPUT);
  pinMode (s3, OUTPUT);
  pinMode (sensorOut, INPUT); //Using at 100%
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  */
  
}

void loop() 
{  
  if(isRunning){
  delay (2000);
  stepperMotor1Fase1(); //stepperMotor 1 transport skittle from inputbuffer to coloursensor fase 1
  delay(timeBetweenActions);
  //colormeasurement start
  identifiedColor = getTheColor();
  delay(timeBetweenActions);
  identifiedColor = 0;
  
  //Blue bValue 14; Yellow cValue 42; Green cValue 61; Red gValue 79; Brown cValue 98  

  //steppermotor 2 for setting correct container
  if (detectBlueValue < 23)//measuring b value
  {
    Serial.println("detected colour = blue");
    numberOffSteps = 34;//experimental number off steps for container blue
    digitalWrite(dirPin2,HIGH); //CCW
    stepperMotor2ToContainer();
    directionStepperMotor2 = 1;
    Serial.println("direction CCW");
  } 

  if ((detectClearValue > 33) && (detectClearValue< 47))
  {
    Serial.println("detected colour = yellow");
    numberOffSteps = 29;//experimental number off steps for container yellow
    digitalWrite(dirPin2,HIGH);
    stepperMotor2ToContainer();
    directionStepperMotor2 = 1;
    Serial.println("direction CCW");
  }

  if ((detectClearValue > 51) && (detectClearValue < 68))
  {
    Serial.println("detected colour = green");
  }

  if ((detectGreenValue > 72) && (detectGreenValue < 87))
  {
    Serial.println("detected colour = red");
    numberOffSteps = 29;//experimental number off steps for container red
    digitalWrite(dirPin2,LOW);
    stepperMotor2ToContainer();
    directionStepperMotor2 = 2;
    Serial.println("direction CW");
  }

  if ((detectClearValue > 91) && (detectGreenValue < 88))
  {
    Serial.println("detected colour = brown");
    numberOffSteps = 29;//experimental number off steps for container brown
    digitalWrite(dirPin2,LOW);
    stepperMotor2ToContainer();
    directionStepperMotor2 = 2;
    Serial.println("direction CW");
  }
  
  delay(100); 

  stepperMotor1Fase2();//transport skittle to outputbuffer
  delay(timeBetweenActions);

  stepperMotor2ReturnToBase();

  stepperMotor1Fase3();//return to inputbuffer
  Serial.println("start new loop===========================================================");

  Serial.println("Wil je het programma stoppen? Typ 'stop' en druk op enter.");
  while (true) {
  if (Serial.available() > 0) {
      String input = Serial.readStringUntil('\n'); // Lees de input
      input.trim(); // Verwijder spaties en enters

      if (input == "stop") {
        isRunning = false;
        Serial.println("Programma stopt...");
        break; // Verlaat de while-loop en ga verder met de code
      } else {
        Serial.println("Typ 'stop' om te starten.");
      }
    }
   }
  delay(500);
  
}
}



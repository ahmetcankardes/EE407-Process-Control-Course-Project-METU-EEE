// note: for my beam to be horizontal, Servo Motor angle should be 127 degrees.
#include<Servo.h>
#include<PID_v1.h>

const int trigPin = 11;    // Trig pin of the ultrasonic sensor (Yellow)
const int echoPin = 10;   // Echo pin of the ultrasonic sensor (Orange)
const int servoPin = 8;  // Servo Pin

/*
float Kp = 2.5;
float Ki = 0.0;  //P Only Controller
float Kd = 0.0;
*/

/*
float Kp = 1.5;
float Ki = 0.0;  //PD Controller
float Kd = 0.5;
*/

/*
float Kp = 2.5243;
float Ki = 0.12096;  //PID PreController
float Kd = 0.1823;
*/


float Kp = 2;
float Ki = 3;
float Kd = 0.5;


double Setpoint, Input, Output, ServoOutput;                                       

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);           //Initialize PID object, which is in the class PID.                                                                   
Servo myServo;                                                       //Initialize Servo.

void setup() {

  Serial.begin(9600);                                                //Begin Serial 
  myServo.attach(servoPin);                                          //Attach Servo
  resetServo();                                               // Reset servo to initial angle

  Input = readPosition();                                            //Calls function readPosition() and sets the balls
                                                                     //  position as the input to the PID algorithm

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);                                       
  myPID.SetMode(AUTOMATIC);                                          //Set PID object myPID to AUTOMATIC 

  myPID.SetOutputLimits(-60,80);                             // Set output limits to match servo range
}

void loop(){
  delay(100);
  Setpoint = 20.0;
  Input = readPosition();
  //Serial.print("Average Position case 1(in cm): ");
  Serial.print(Input, 3); //
  Serial.println();                                           
 
  myPID.Compute();                                                   //computes Output in range of -80 to 80 degrees
  
  ServoOutput=127-Output;                                            // 102 degrees is my horizontal 
  myServo.write(ServoOutput);                                        //Writes value of Output to servo
  //Serial.print("angle: ");
  //Serial.println(ServoOutput);
  
}

void resetServo() {
  myServo.write(127);  // Set servo to 102 degrees for horizontal positioning
  delay(500);          // Delay to allow the servo to reach the desired position
}

float readPosition() {
  delay(40);                                                            //Don't set too low or echos will run into eachother.      
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // Calculate distance in cm

  if (distance > 38 || distance <= 0) {
    distance = 38; // Set maximum distance as 30 cm for the ball
  }
  //Serial.print("distance: ");
  //Serial.println(distance);
  return distance;
}
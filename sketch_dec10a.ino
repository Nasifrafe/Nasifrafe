#include <Servo.h>

// HC-SR04 Echo Pin & Trigger Pin connect to the Arduino Nano Digital Pins
#define echo_pin 10
#define trigger_pin 9
// Servo PWM
#define servo_pin 6
#define buzzer 3
const int trigPin = 4; // Trigger pin
const int echoPin = 5; // Echo pin
long duration2;
int distance2;
Servo servo_motor;

void setup() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer, OUTPUT); // Added LED pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  servo_motor.attach(servo_pin);
}

void loop() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  double distance = duration * 0.034 / 2;

  Serial.print(distance);

  // If the distance read by the sensor is less than 10 cm and more than the minimum 3 cm,
  // then it is assumed that there is a hand under the sanitizer
  if ((distance > 3) && (distance < 10)) {
    servo_motor.write(150);
    delay(1000);
  } 
  

  servo_motor.write(0);

    // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse from the echoPin
  duration2 = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance2 = duration2 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Wait for a short time before taking the next measurement
  delay(500);
  if (distance2 > 4) {
    digitalWrite(buzzer, HIGH);
    
  } 
  else{
    digitalWrite(buzzer,LOW);
  }

}

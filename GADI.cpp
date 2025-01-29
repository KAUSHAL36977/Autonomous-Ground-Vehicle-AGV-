#include <Wire.h>  
#include <Adafruit_MotorShield.h>  

// Create the motor shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Motors connected to shield
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);

// Ultrasonic sensor pins
#define TRIG_PIN 4
#define ECHO_PIN 5

#define OBSTACLE_DISTANCE 20  // Distance threshold (cm)

void setup() {
  Serial.begin(9600);
  AFMS.begin();  // Initialize motor shield

  // Set motor speed (0-255)
  motor1->setSpeed(200);
  motor2->setSpeed(200);
  motor3->setSpeed(200);
  motor4->setSpeed(200);

  // Ultrasonic sensor setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < OBSTACLE_DISTANCE) {
    stopMotors();
    delay(500);
    turnRight();
    delay(800);
  } else {
    moveForward();
  }
}

// Move Forward
void moveForward() {
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

// Turn Right
void turnRight() {
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
}

// Stop Motors
void stopMotors() {
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}

// Get distance from Ultrasonic Sensor
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

// Motor driver pin connections
#define MOTOR1_IN1 6
#define MOTOR1_IN2 7
#define MOTOR2_IN1 8
#define MOTOR2_IN2 9
#define MOTOR3_IN1 10
#define MOTOR3_IN2 11
#define MOTOR4_IN1 12
#define MOTOR4_IN2 13

// Ultrasonic sensor pin connections
#define TRIG_PIN 4
#define ECHO_PIN 5

// Minimum distance to detect an obstacle (in cm)
#define OBSTACLE_DISTANCE 20

// Function prototypes
void moveForward();
void turnLeft();
void turnRight();
void stopMotors();
long getDistance();

void setup() {
  // Motor pins as output
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  pinMode(MOTOR3_IN1, OUTPUT);
  pinMode(MOTOR3_IN2, OUTPUT);
  pinMode(MOTOR4_IN1, OUTPUT);
  pinMode(MOTOR4_IN2, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < OBSTACLE_DISTANCE) {
    stopMotors();
    delay(500);
    turnRight();  // Change direction
    delay(800);   // Adjust turning duration
  } else {
    moveForward();
  }
}

// Function to move all motors forward
void moveForward() {
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, HIGH);
  digitalWrite(MOTOR2_IN2, LOW);
  digitalWrite(MOTOR3_IN1, HIGH);
  digitalWrite(MOTOR3_IN2, LOW);
  digitalWrite(MOTOR4_IN1, HIGH);
  digitalWrite(MOTOR4_IN2, LOW);
}

// Function to turn left
void turnLeft() {
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, HIGH);
  digitalWrite(MOTOR2_IN1, HIGH);
  digitalWrite(MOTOR2_IN2, LOW);
  digitalWrite(MOTOR3_IN1, LOW);
  digitalWrite(MOTOR3_IN2, HIGH);
  digitalWrite(MOTOR4_IN1, HIGH);
  digitalWrite(MOTOR4_IN2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, HIGH);
  digitalWrite(MOTOR3_IN1, HIGH);
  digitalWrite(MOTOR3_IN2, LOW);
  digitalWrite(MOTOR4_IN1, LOW);
  digitalWrite(MOTOR4_IN2, HIGH);
}

// Function to stop all motors
void stopMotors() {
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  digitalWrite(MOTOR3_IN1, LOW);
  digitalWrite(MOTOR3_IN2, LOW);
  digitalWrite(MOTOR4_IN1, LOW);
  digitalWrite(MOTOR4_IN2, LOW);
}

// Function to get the distance from the ultrasonic sensor
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

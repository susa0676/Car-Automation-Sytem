// Pin Definitions
#define trigPin 8
#define echoPin 9

// Motor Pins
#define motor1Pin1 2  // Left motor forward
#define motor1Pin2 3  // Left motor backward
#define motor2Pin1 4  // Right motor forward
#define motor2Pin2 5  // Right motor backward

// Constants
const int obstacleThreshold = 20;  // Distance in cm to detect obstacles

void setup() {
  Serial.begin(9600);

  // Sensor Pin Modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Motor Pin Modes
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
  long distance = measureDistance();

  if (distance < obstacleThreshold) {
    Serial.println("Obstacle detected! Stopping.");
    stopCar();
    delay(500);  // Wait a bit before deciding direction

    // Re-check obstacle direction and act accordingly
    if (checkObstacleOnRight()) {
      goBackward();
      delay(1000);  // Move backward for 1 second
      turnLeft();   // Turn left if obstacle is on the right
    } else {
      turnRight();  // Turn right if obstacle is not on the right
    }
  } else {
    moveForward();
  }

  delay(100);
}

// Function to measure distance with ultrasonic sensor
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

// Function to check for obstacle on the right by turning slightly and measuring
bool checkObstacleOnRight() {
  // Turn slightly right to check
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(500);  // Small turn to the right

  long rightDistance = measureDistance();

  // Return to original direction
  stopCar();

  Serial.print("Right Distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  // Check if there's an obstacle on the right within threshold
  return rightDistance < obstacleThreshold;
}

// Function to move car forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Moving forward");
}

// Function to stop the car
void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Car stopped");
}

// Function to turn the car left
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(500);  // Turn for half a second
  Serial.println("Turning left");
  stopCar();
}

// Function to turn the car right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(500);  // Turn for half a second
  Serial.println("Turning right");
  stopCar();
}

// Function to go backward
void goBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  Serial.println("Going backward");
}

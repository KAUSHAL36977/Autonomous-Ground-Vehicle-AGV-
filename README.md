# Arduino 4WD Obstacle-Avoiding Robot

![Robot Image](path_to_your_image.jpg)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
- [Installation and Setup](#installation-and-setup)
- [Code Explanation](#code-explanation)
- [Demonstration Video](#demonstration-video)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project involves building a 4-wheel drive (4WD) robot that autonomously navigates its environment by detecting and avoiding obstacles using an ultrasonic sensor. The robot moves forward until it encounters an obstacle within a specified distance, at which point it stops, changes direction, and continues moving.

## Features

- **Autonomous Navigation:** The robot moves without manual control, adjusting its path upon detecting obstacles.
- **Obstacle Detection:** Utilizes an ultrasonic sensor to measure the distance to objects ahead.
- **Direction Control:** Changes direction when an obstacle is detected to avoid collisions.

## Components Required

- **Arduino Uno or Nano**
- **L298N Motor Driver Module**
- **4 DC Motors**
- **Ultrasonic Sensor (HC-SR04)**
- **Power Supply (appropriate for your motors)**
- **Chassis for mounting components**
- **Connecting Wires**
- **Breadboard (optional)**
- **Switch (for power control)**

## Circuit Diagram

![Circuit Diagram](path_to_your_circuit_diagram.png)

*Note: Ensure all connections are secure and double-check the wiring before powering the circuit.*

## Installation and Setup

1. **Assemble the Hardware:**
   - Mount the motors onto the chassis.
   - Connect the motors to the L298N motor driver.
   - Attach the ultrasonic sensor to the front of the chassis.
   - Connect the motor driver and ultrasonic sensor to the Arduino as per the circuit diagram.

2. **Arduino IDE Setup:**
   - Install the [Arduino IDE](https://www.arduino.cc/en/software) if not already installed.
   - Connect your Arduino board to your computer using a USB cable.

3. **Upload the Code:**
   - Open the Arduino IDE.
   - Copy and paste the provided code into the IDE.
   - Select the correct board and port from the 'Tools' menu.
   - Click on the upload button to program the Arduino.

## Code Explanation

The code is structured to control the robot's movement and handle obstacle detection:

- **Pin Definitions:** Assigns Arduino pins to motor driver inputs and the ultrasonic sensor.
- **Setup Function:** Initializes motor pins as outputs and sensor pins appropriately.
- **Loop Function:** Continuously checks the distance to obstacles:
  - If an obstacle is closer than the defined threshold, the robot stops, waits briefly, turns right, and then resumes forward movement.
  - If no obstacle is detected within the threshold, the robot continues moving forward.

**Key Functions:**

- `moveForward()`: Sets the motors to move the robot forward.
- `turnRight()`: Adjusts motor directions to turn the robot right.
- `stopMotors()`: Stops all motor movement.
- `getDistance()`: Measures the distance to the nearest object using the ultrasonic sensor.

*For a detailed walkthrough of the code, please refer to the comments within the code file.*

## Demonstration Video

For a visual demonstration of a similar obstacle-avoiding robot, you can watch the following video:

[![Arduino Obstacle Avoiding Robot](https://img.youtube.com/vi/0X_S7BlKe-M/0.jpg)](https://www.youtube.com/watch?v=0X_S7BlKe-M)

*Note: This video provides a general idea of how the robot operates. Your specific implementation may vary.*

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

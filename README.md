# Motor Control with Encoder Feedback

This code demonstrates motor control using an encoder for position feedback. It uses pulse width modulation (PWM) to control the motor speed and implements a PID (Proportional-Integral-Derivative) controller for precise position control.

## Hardware Setup

The following pins are used for connecting the components:

- Encoder Pin A: Connect to digital pin 2 (`ENCA`)
- Encoder Pin B: Connect to digital pin 3 (`ENCB`)
- Motor Input 1: Connect to digital pin 4 (`IN1`)
- Motor Input 2: Connect to digital pin 5 (`IN2`)
- PWM Pin: Connect to digital pin 6 (`pwmPin`)

Make sure to connect the motor and power supply according to the motor specifications.

## Software Setup

The code requires the Arduino IDE to upload it to the Arduino board. Follow these steps to set up the software:

1. Install the Arduino IDE ([Download Link](https://www.arduino.cc/en/software))
2. Open the Arduino IDE and create a new sketch.
3. Copy and paste the provided code into the sketch.
4. Connect your Arduino board to your computer using a USB cable.
5. Select the appropriate board and port from the Tools menu in the Arduino IDE.
6. Click the "Upload" button to upload the code to the Arduino board.

## Usage

Once the code is uploaded to the Arduino board, the motor control with encoder feedback will begin. The code implements a PID controller to maintain a desired position (`goalpos`). The PID constants (`kp`, `kd`, `ki`) can be adjusted to achieve the desired control performance.

The motor speed and direction are controlled based on the calculated control signal (`u`) using the `setMotor()` function. The motor direction is determined by the sign of the control signal, and the motor speed is determined by the magnitude of the control signal. The maximum motor speed is limited to 255 (`pwr > 255`) to prevent exceeding the motor's capabilities.

The current motor speed and position are displayed in the serial monitor with a baud rate of 9600. Adjust the baud rate in the `Serial.begin()` function if needed.

## Acknowledgements

This code is provided as a starting point for motor control with encoder feedback. It can be customized and extended according to specific project requirements.

## License

This code is released under the MIT License. Please refer to the LICENSE file for more details.


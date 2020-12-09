// ME3580 Course Project
// Baetz, Broski, Carow, Fritz
// Code author: Carow

const int FORWARD = 5;    // forward pwm output
const int REVERSE = 6;    // reverse pwm output
const int buttonPin = 2;  // pin for motor control

int buttonState = 0;      // current state of the button
int lastButtonState = 0;  // previous state of the button

int mechanismState = 0;  // keeps track of open vs. closed

void setup() {
  pinMode(FORWARD, OUTPUT);
  pinMode(REVERSE, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void loop() {
  // get current button state
  buttonState = digitalRead(buttonPin);

  if ((lastButtonState == LOW) && (buttonState == HIGH)) {
    // if button went from unpressed to pressed
    if (mechanismState == 0) {
      // run motor forward
      analogWrite(FORWARD, 200);  // PWM  200 out of 255
      delay(220);                 // 0.220 seconds
      analogWrite(FORWARD, LOW);
      mechanismState = 1;
    }
    else if (mechanismState == 1) {
      // run motor in reverse
      analogWrite(REVERSE, 200);  // PWM  200 out of 255
      delay(220);                 // 0.220 seconds
      analogWrite(REVERSE, LOW);
      mechanismState = 0;
    }
  }
  lastButtonState = buttonState;  // record state of button for next iteration
}

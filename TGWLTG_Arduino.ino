#include <Servo.h>
#define BUTTON_MIDDLE_BLUE 2
#define BUTTON_BOTTOMLEFT_GRAY 3
#define BUTTON_BOTTOMRIGHT_GRAY 4
#define BUTTON_TOPLEFT_YELLOW 5
#define BUTTON_TOPRIGHT_YELLOW 6

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int pos = 0;
bool up = false;
bool set_up = false;

// Button State values
int lastButtonStateMiddle;
int middleBlueState;
int lastButtonStateBottomLeft;
int bottomLeftGrayState;
int lastButtonStateBottomRight;
int bottomRightGrayState;
int lastButtonStateTopLeft;
int topLeftYellowState;
int lastButtonStateTopRight;
int topRightYellowState;

void setup() {
  Serial.begin(9600);
  Serial.println("Hit Checkpoint alpha. We setup began");

  servo1.attach(12);

  //pinMode(BUTTON_MIDDLE_BLUE, INPUT);  // enable the internal pull-up resistor
  //lastButtonStateMiddle = digitalRead(BUTTON_MIDDLE_BLUE);
  pinMode(BUTTON_BOTTOMLEFT_GRAY, INPUT);  // enable the internal pull-up resistor
  lastButtonStateBottomLeft = digitalRead(BUTTON_BOTTOMLEFT_GRAY);
  //pinMode(BUTTON_BOTTOMRIGHT_GRAY, INPUT);  // enable the internal pull-up resistor
  //lastButtonStateBottomRight = digitalRead(BUTTON_BOTTOMRIGHT_GRAY);
  //pinMode(BUTTON_TOPLEFT_YELLOW, INPUT);  // enable the internal pull-up resistor
  //lastButtonStateTopLeft = digitalRead(BUTTON_TOPLEFT_YELLOW);
  //pinMode(BUTTON_TOPRIGHT_YELLOW, INPUT);  // enable the internal pull-up resistor
  //lastButtonStateTopRight = digitalRead(BUTTON_TOPRIGHT_YELLOW);

  if (!set_up) {
    for (pos = 0; pos >= -90; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      Serial.println(pos);
    }
    set_up = true;
  }
}

void loop() {
  //Serial.println("Hit Checkpoint 0. We have entered the loop");

  // read the value of the button
  //middleBlueState = digitalRead(BUTTON_MIDDLE_BLUE);
  bottomLeftGrayState = digitalRead(BUTTON_BOTTOMLEFT_GRAY);
  //bottomRightGrayState = digitalRead(BUTTON_BOTTOMRIGHT_GRAY);
  //topLeftYellowState = digitalRead(BUTTON_TOPLEFT_YELLOW);
  //topRightYellowState = digitalRead(BUTTON_TOPRIGHT_YELLOW);
  //Serial.println("Hit Checkpoint 0.1. Initial Button Read button7 is done");
  
  //Serial.print("Middle Blue: ");
  //Serial.println(middleBlueState);

  //Serial.print("Bottom Left Gray: ");
  //Serial.println(bottomLeftGrayState);
  /*
  Serial.print("Bottom Right Gray: ");
  Serial.println(bottomRightGrayState);
  Serial.print("Top Left Yellow: ");
  Serial.println(topLeftYellowState);
  Serial.print("Top Right Yellow: ");
  Serial.println(topRightYellowState);
  delay(1000);
  */
  
  if (bottomLeftGrayState == 1) { // state changed
    //Serial.println("Hit Checkpoint 1.4 We are inside the LastButtonState4 switch");
    //delay(50); // debounce time

    for (pos = -90; pos >= 0; pos += 1) {
      servo1.write(pos);
      delay(15);
      Serial.println(pos);
    }

    set_up = false;
  }

  /*
  if (lastButtonState7 != buttonState7) { // state changed
    Serial.println("Hit Checkpoint 1.7 We are inside the LastButtonState7 switch");
    delay(50); // debounce time

    if (buttonState7 == LOW)
      Serial.println("Button 7 pressed event");
    else
      Serial.println("Button 7 released event");

    lastButtonState7 = buttonState7;
  }
  */
}
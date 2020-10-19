#include <Keyboard.h>

// constants that won't change. used to set pin numbers:
const int buttonPin1 = 2; // left key
const int buttonPin2 = 3; // right key
const int led1 = 11;      // left led
const int led2 = 6;       // right led

// defining which key to press:
const char button1press = 's';
const char button2press = 'd';

// variables that will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

int led1_brightness = 0;
int led2_brightness = 0;

int led1_dir = 1;
int led2_dir = 1;

int led1_increment = 0;
int led2_increment = 0;

void setup() {
  // initialize the button pins as inputs:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  // leds as output and write high/on:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  //digitalWrite(led1, HIGH); //PWM COMPAT
  //digitalWrite(led2, HIGH); //PWM COMPAT

  //small light show to show function
  for (int i = 0; i <= 255; i++) {
    analogWrite(led1, i);
    analogWrite(led2, i);
    //delay(1);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(led1, 255-i);
    analogWrite(led2, 255-i);
    delay(1);
  }
  
  //start keyboard
  Keyboard.begin();
}

void loop(){
  // Button 1:
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) {
      Keyboard.press(button1press);
      led1_increment = 1;
  } 
  else {
    Keyboard.release(button1press);
  }

  if(led1_increment == 1){
    if(led1_brightness == 255) led1_dir = -1;
    if(led1_brightness == 0) led1_dir = 1;
    led1_brightness += led1_dir;
    analogWrite(led1, led1_brightness);
    led1_increment = 0;
  }

  // Button 2:
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == LOW) {   
      Keyboard.press(button2press);
      led2_increment = 1;
  } 
  else {
    Keyboard.release(button2press);
  }

  if(led2_increment == 1){
    if(led2_brightness == 255) led2_dir = -1;
    if(led2_brightness == 0) led2_dir = 1;
    led2_brightness += led2_dir;
    analogWrite(led2, led2_brightness);
    led2_increment = 0;
  }
}
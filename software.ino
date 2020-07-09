#include <Keyboard.h>


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin1 = 3;     // the number of the pushbutton pin
const int buttonPin2 = 2; 
const int led1 = 11;
const int led2 = 6;
const char button1press = 's';
const char button2press = 'd';

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  Keyboard.begin();
}

void loop(){
  // Button 1:
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) {
      Keyboard.press(button1press);
  } 
  else {
    Keyboard.release(button1press);
  }

  // Button 2:
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == LOW) {   
      Keyboard.press(button2press);
  } 
  else {
    Keyboard.release(button2press);
  }
  //delay();
  
  // Button 2:
  //buttonState2 = digitalRead(buttonPin2);
  //if (buttonState2 == LOW) {   
    //while(buttonState2 == LOW){
      //buttonState2 = digitalRead(buttonPin2);
      //Keyboard.press(button2press);
      //delay(30);
    //}
  //} 
  //else {Keyboard.release(button2press);}
  //delay();
}

Ka
/*
This code is an adaptation from the KeyboardAndMouse example*
 WARNING:  When you use the Mouse.move() command, the Arduino takes
 over your mouse!  Make sure you have control before you use the mouse commands.

If any major problems are found in taking over the keyboard, load this code on the board to complety reset:
int main () { }

 created 15 Mar 2012
 modified 27 Mar 2012
 by Tom Igoe
*This Example is in the public domain
 */

#include "Keyboard.h"
#include "Mouse.h"

// set pin numbers for the five buttons:
const int upButton = A3;
const int downButton = A4;
const int leftButton = A5;
const int rightButton = A0;
//const int mouseButton = A2;

void setup() { // initialize the buttons' inputs:
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
 // pinMode(mouseButton, INPUT);

  Serial.begin(9600);
  // initialize mouse control:
//  Mouse.begin();

  // initialize keyboard control:
  Keyboard.begin();
}

void loop() {
  // use serial input to control the mouse:
//  if (Serial.available() > 0) {
//    char inChar = Serial.read();
//
//    switch (inChar) {
//      case 'u':
//        // move mouse up
//        Mouse.move(0, -40);
//        break;
//      case 'd':
//        // move mouse down
//        Mouse.move(0, 40);
//        break;
//      case 'l':
//        // move mouse left
//        Mouse.move(-40, 0);
//        break;
//      case 'r':
//        // move mouse right
//        Mouse.move(40, 0);
//        break;
//      case 'm':
//        // perform mouse left click
//        Mouse.click(MOUSE_LEFT);
//        break;
//    }
//  }

  // use the pushbuttons to control the keyboard:
  if (digitalRead(upButton) == HIGH) {
    Keyboard.write('u');
  }
  if (digitalRead(downButton) == HIGH) {
    Keyboard.write('d');
  }
  if (digitalRead(leftButton) == HIGH) {
    Keyboard.write('l');
  }
  if (digitalRead(rightButton) == HIGH) {
    Keyboard.write('r');
  }
  if (digitalRead(mouseButton) == HIGH) {
    Keyboard.write('m');
  }

}


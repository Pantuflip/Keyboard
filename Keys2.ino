/*
  KeyboardAndMouseControl

  

  The mouse movement is always relative. This sketch reads four pushbuttons, and
  uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

 Programa modificado por Rafael Zapata
  Comandos
  Mouse.begin()
Mouse.click()
Mouse.end()
Mouse.move()
Mouse.press()
Mouse.release()
Mouse.isPressed()

Keyboard.begin()
Keyboard.end()
Keyboard.press()
Keyboard.print()
Keyboard.println()
Keyboard.release()
Keyboard.releaseAll()
Keyboard.write()

 
*/

#include "Keyboard.h"
#include "Mouse.h"

// set pin numbers for the five buttons:
const int Boton2 = 2;
const int Boton3 = 3;
const int Boton12 = 12;


void setup() { // initialize the buttons' inputs:
  pinMode(Boton2, INPUT_PULLUP);
  pinMode(Boton3, INPUT_PULLUP);
  pinMode(Boton12, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  //Serial.begin(9600);  //No necesito el puerto serial por ahora
  // initialize mouse control:
  delay(1000);
  Mouse.begin();
  delay(250);
  Keyboard.begin();
  delay(250);
}
                                                                                                                                                                          
void loop() {
      // use serial input to control the mouse:
      
      // use the pushbuttons to control the keyboard:
      if (digitalRead(Boton2) == LOW) 
      {
            for (int i = 0; i<=3; i++)
            { 
                Keyboard.press('c');
                delay(25);
                //Keyboard.release();
                Keyboard.releaseAll();
                Mouse.press(MOUSE_LEFT);
                
                Mouse.move(500, 0);
                delay(100);
                Mouse.release();
                Mouse.move(-500, 0);
            }
        
      }
      if (digitalRead(Boton3) == LOW) 
      {
          for (int i = 0; i<=3; i++)
            { 
                Keyboard.press('v');
                delay(25);
                //Keyboard.release();
                Keyboard.releaseAll();
                Mouse.press(MOUSE_LEFT);
                
                Mouse.move(500, 0);
                delay(500);
                Mouse.release();
                Mouse.move(-500, 0);
            }
      }

      if (digitalRead(Boton12) == LOW) 
      {
          Mouse.end();
          Keyboard.end();
          while(1){
          digitalWrite(13, LOW);
          }
      }
      
      //delay(250);
      digitalWrite(13, HIGH);
  
}




/* // programar para verificar que se está enviando al computador
  if (Serial.available() > 0) {
    char inChar = Serial.read();

    switch (inChar) {
      case 'u':
        // move mouse up
        Mouse.move(0, -40);
        break;
      case 'd':
        // move mouse down
        Mouse.move(0, 40);
        break;
      case 'l':
        // move mouse left
        Mouse.move(-40, 0);
        break;
      case 'r':
        // move mouse right
        Mouse.move(40, 0);
        break;
      case 'm':
        // perform mouse left click
        Mouse.click(MOUSE_LEFT);
        break;
    }
  } 
  */

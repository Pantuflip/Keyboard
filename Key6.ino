/*

  El movimiento del mouse siempre es relativo, no olviden eso, ademas los pasos depende de la resolución a la que
  tengan configurado su mouse en el sistema perativo.

  Cuando es programa esté completado si quieren usar la configuración de teclaod en español se debe usar la libreria
  "Keyboard_ES"

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

 Programa para usar un teclado de 2 filas por 3 columnas, en total 6 teclas,
 Con este programa se recrea el funcionamiento de un teclaod normal, pero bajando mucho la complejidad.
 
 Programa realizado por : Rafael Zapata Grau
 e-mail: razapata@gmail.com

 
  Comandos del mouse:
  Mouse.begin()
  Mouse.click()
  Mouse.end()
  Mouse.move()
  Mouse.press()
  Mouse.release()
  Mouse.isPressed()

  Comandos del teclado:
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
const int Rows[] = {2 , 3};
const int Cols[] = {4, 5, 6};
const int RowsCounter = 2;
const int ColsCounter = 3;

/*  Información para hacer tarea periodica */
unsigned long startMillis;  //Variable Global
unsigned long currentMillis;
const unsigned long periodo = 150;  //Peridodo de ejecución en milisegundos

int thisPin;
int i;
int j;

void setup() { // Inicializando los Digital Input y las digital Output

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  for (thisPin = 0; thisPin < RowsCounter; thisPin++) 
  {
    pinMode(Rows[thisPin], OUTPUT);
  }

  for (thisPin = 0; thisPin < ColsCounter; thisPin++) 
  {
    pinMode(Cols[thisPin], INPUT);
  }
  
   //Serial.begin(9600);  //No necesito el puerto serial por ahora
  // initialize mouse control:
  delay(10000); // Espero 10 segundos para que el driver del Teclado haga efecto.
  Mouse.begin();
  delay(250);
  Keyboard.begin();
  delay(250);

  startMillis = millis();  //inicializa el tiempo, millis() devuelve el valor del tiempo de ejecución del programa en milisengundos.
  digitalWrite(13, HIGH);
}


                                                                                                                                                                          
void loop() {
      currentMillis = millis(); 
      for(i = 0; i < RowsCounter; i++)
      {
          digitalWrite(Rows[i],LOW);
          delay(10);
      } 
      if ( (currentMillis - startMillis >= periodo) || (currentMillis - startMillis < 0) )
      {
          // codigo a ejecutar
          for(i = 0; i < RowsCounter; i++)
          {
              digitalWrite(Rows[i],HIGH);
              delay(20);
              for(j = 0; j < ColsCounter; j++ )
              {
                  if( digitalRead(Cols[j])== HIGH )
                  {
                     if(i == 0)
                     {
                        switch (j){
                          case 0:
                              boton1();
                              break;
                          case 1:
                              boton2();
                              break;
                          case 2:
                              boton3();
                              break;   
                        }
                        
                     }
                     if(i == 1)
                     {
                        switch (j){
                          case 0:
                              boton4();
                              break;
                          case 1:
                              boton5();
                              break;
                          case 2:
                              boton6();
                              break;   
                        }
                     } 
                     
                  }
                  delay(20); // delay por seguridad
              }
                
          }

          
          
          startMillis = currentMillis;  // condición para evaluar el siguiente vez
          //Se enciende Led para verificar que se ejecutó por lo menos una vez el código
          //digitalWrite(13, HIGH);
          delay(1);
      }
     
      
  
}


void boton1()
{
    Keyboard.begin();
    delay(500);
    Mouse.begin();
    delay(500);
    delay(100);
    digitalWrite(13, HIGH);
}


void boton2()
{
    Keyboard.releaseAll();
    delay(50);
    Keyboard.end();
    delay(50);
    Mouse.release();
    delay(50);
    Mouse.end();
    delay(100);
    digitalWrite(13, LOW);
}

void boton3()
{
      Keyboard.press('x');
      delay(50);
      Mouse.press();
      delay(50);
      //Keyboard.release();
      Keyboard.release('x');
      delay(50);
      Keyboard.press('z');
      delay(50);
      //Mouse.press();
      delay(50);
      Keyboard.release('z');
      delay(50);
      Keyboard.press('c');
      delay(50);
      //Mouse.press();
      delay(50);
      Keyboard.release('c');
      delay(50);
      Mouse.release();
      delay(50);
      Keyboard.press('x');
      delay(50);
      Keyboard.release('x');
      delay(50);
}


void boton4()
{
    Keyboard.print("Test Boton 4. No presiono Enter. ññ");
    delay(50);
}


void boton5()
{
    Keyboard.println("Test Boton 5. Sí presiono Enter. ññ");
    delay(50);
        
    Keyboard.println("Test Boton 5. á, é, í, ó, ú, ñ, ~");
    delay(50);
}


void boton6()
{
      Mouse.move(500, 0);
      delay(1000);
      Mouse.move(5000, 0);
      delay(1000);
      Mouse.move(500, 0);
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

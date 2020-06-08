//*Arduino USB Keyboard for PPT Ink Controls
//*Tool and Color
//*8-14-15 update includes different delay speeds for colors
//Code based on example found here: http://mitchtech.net/arduino-usb-hid-keyboard/

#define KEY_LEFT_CTRL 1
#define KEY_LEFT_SHIFT 2
#define KEY_F10 67

uint8_t buf[8] = {
  0
}; //Keyboard buffer bit rate


#define PIN_MESSAGE 3
#define PIN_LEDS 5

int state = 1;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_MESSAGE, INPUT);
  pinMode(PIN_LEDS, INPUT);
  //internal pull-ups
  digitalWrite(PIN_MESSAGE, 1);
  digitalWrite(PIN_LEDS,1);
  
  delay(200);
}

void loop()
{
    state = digitalRead(PIN_LEDS);
    if (state != 1) {
    buf[2] = 57;    // Keyboard Caps Lock
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    }
        
    state = digitalRead(PIN_MESSAGE);
    if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    buf[2] = 25;    // Letter A
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    
    delay(250);

    buf[2] = 11; // H
    Serial.write(buf, 8); // Send keypress
    releaseColor();

    buf[2] = 18; // o
    Serial.write(buf, 8); // Send keypress
    releaseColor();

    buf[2] = 15; // l
    Serial.write(buf, 8); // Send keypress
    releaseColor();

    buf[2] = 4; // l
    Serial.write(buf, 8); // Send keypress
    releaseColor();

    buf[2] = 44; // Space
    Serial.write(buf, 8); // Send keypress
    releaseColor();

    buf[2] = 40; // Enter
    Serial.write(buf, 8); // Send keypress
    releaseColor();
  }

}

// ------  Functions  -----------
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  delay(100);
}

void releaseColor() //seperate releases b/c need a faster response rate to reduce sensation of lag when going thru color menu
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); //release
  delay(50);
}

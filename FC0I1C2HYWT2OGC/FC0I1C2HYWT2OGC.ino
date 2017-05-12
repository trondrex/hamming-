/*
  Simple Chat Program
 
 Receives from the hardware serial, sends to hardware & software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 created 16 August 2014
 modified 16 August 2014
 by William Chang Wei Tan
 based on SoftwareSerial example
 */
#include <SoftwareSerial.h>

SoftwareSerial chat(10, 11); // RX, TX

int text;

void setup()  
{
  // open hardware serial, TX = 1, RX = 0
  Serial.begin(9600);
  Serial.println("Starting Chat Program...");
  // set the data rate for the SoftwareSerial port
  chat.begin(9600);
  delay(1000); // delay 1s to stabilize serial ports
  chat.println("Hello World");
}

void loop() 
{
  if (chat.available()) 
    Serial.write(chat.read());
    
  if (Serial.available()) 
  {
    Serial.print("Me:\t");
    while (Serial.available()) 
    {
      text = Serial.read();
      chat.write(text);
      Serial.write(text);
    }
    chat.println();
    Serial.println();
  }
}


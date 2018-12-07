/*  Bluetooth Relay Control With SoftwareSerial
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-Bluetooth-Relay-Control-With-SoftwareSerial
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com  
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - HC-05 / HC-06 Bluetooth Module
 *  - 2 Channel Relay Module
 *  - Bulb
 *  - Bulb Holder
 *  - Wire
 *  - Plug
 *  - Jumper Wires
 *  
 *  Libraries
 *  ---------
 *  - SoftwareSerial
 *  
 *  Play Store App
 *  --------------
 *  - Bluetooth Terminal - https://play.google.com/store/apps/details?id=project.bluetoothterminal
 *  
 */

#include <SoftwareSerial.h>   // Software Serial Library For UART Communication

int R1 = 6;   //Relay 1
int R2 = 7;   //Relay 2
char data = 0; //Variable for storing received data

SoftwareSerial bluetooth(10, 11); // RX, TX

void setup()
{
    Serial.begin(9600);
    bluetooth.begin(9600);
    Serial.println("Welcome To Bluetooth Relay Control");
    bluetooth.println("Welcome To Bluetooth Relay Control");                              
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
}

void loop()
{
   if(bluetooth.available() > 0)  // Send data only when you receive data:
   {
      data = bluetooth.read();
      if(data == '1') {
         digitalWrite(R1, LOW);
         Serial.println("Relay 1 - ON");
         bluetooth.println("Relay 1 - ON");
      }
      else if(data == '2') {
         digitalWrite(R1, HIGH);
         Serial.println("Relay 1 - OFF");
         bluetooth.println("Relay 1 - OFF");
      }
      else if(data == '3') {
         digitalWrite(R2, LOW);
         bluetooth.println("Relay 2 - ON");
      }
      else if(data == '4') {
         digitalWrite(R2, HIGH);
         Serial.println("Relay 2 - OFF");
         bluetooth.println("Relay 2 - OFF");
      }
      else if(data == '5') {
         digitalWrite(R1, LOW);
         digitalWrite(R2, LOW);
         Serial.println("Both Relay 1 And Relay 2 - ON");
         bluetooth.println("Both Relay 1 And Relay 2 - ON");
      }
      else if(data == '6') {
         digitalWrite(R1, HIGH);
         digitalWrite(R2, HIGH);
         Serial.println("Both Relay 1 And Relay 2 - OFF");
         bluetooth.println("Both Relay 1 And Relay 2 - OFF");
      }
   }
}

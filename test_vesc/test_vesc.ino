//#include <U8g2lib.h>
#include <VescUart.h>
#include <SoftwareSerial.h>

//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
EspSoftwareSerial::UART serialPort;
#define serial_Tx 12
#define serial_Rx 13
// SoftwareSerial softwareSerial = SoftwareSerial(15, 16); // ESP8266 (NodeMCU): RX (D5), TX (D6 / GPIO12)

/** Initiate VescUart class */
VescUart vesc;


 void setup(void) 
 {
  // Setup the Serial Port with your computer for Serial Monitor Data
  Serial.begin(9600);
  delay(500);

  // Setup serial connection to VESC
  serialPort.begin(115200, SWSERIAL_8N1, serial_Rx, serial_Tx, false);
  delay(500);

  // Setup the OLED Display
  
  /** Define which ports to use as UART */
  vesc.setSerialPort(&serialPort);
}

void loop(void) 
{
  static uint32_t input[2];
  vesc.setDuty((float)50/100.0);
  
  delay(50);
}

bool get_input(uint32_t *command)
{
  static int b = 0;
  static char ch[11];
  static int i = -1;
  if(Serial.available() > 0)
  {
    i++;
    ch[i] = (char)Serial.read();

    if(ch[i] == '\r' || ch[i] == '\n')
    {
      command[b] = atol(ch);
      Serial.println(command[b]);
      for(int j = 0; j < 10; j++)
      {
        ch[j] = '\0';
      }      
      i = -1;
      b = 0;
      return true;
    }
    if(isSpace(ch[i]))
    {
      command[b] = atol(ch);
      Serial.print(command[b]);
      Serial.print(F(" "));
      for(int j = 0; j < 10; j++)
      {
        ch[j] = '\0';
      }
      i = -1;
      b++;
    }
  }
  return false;
}

#include "oled.h"


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R1,/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);
/** Initiate SoftwareSerial class */

#include <VescUart.h>
#include <SoftwareSerial.h>

/** Initiate VescUart class */
VescUart vesc;

/** Initiate SoftwareSerial class */
SoftwareSerial vescSerial(13, 15);

void setup() {
  u8g2.begin();

  /** Setup Serial port to display data */
  Serial.begin(9600);

  /** Setup SoftwareSerial port */
  vescSerial.begin(19200);

  /** Define which ports to use as UART */
  vesc.setSerialPort(&vescSerial);
}


uint8_t percent = 100;
uint8_t speed = 100;
float wheel_circumference = 2.0; 
uint8_t max_voltage = 42;

void loop() {
  
  /** Call the function getVescValues() to acquire data from VESC */
  if ( vesc.getVescValues() ) {

    speed = (uint8_t)((vesc.data.rpm) * wheel_circumference);
    percent = (uint8_t)((vesc.data.inpVoltage) / max_voltage * 100);

  }
  else
  {
    Serial.println("Failed to get data!");
  }

    showBatteryLevel(percent,speed, u8g2);
    ShowBatteryPercent(percent, u8g2);
    iShowSpeed(speed, u8g2);

  delay(50);
}



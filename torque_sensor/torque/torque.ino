#include <HTTPClient.h>
#include <esp_adc_cal.h>
#include <esp32-hal-adc.h>
//#include <VescUart.h>
#include <SoftwareSerial.h>

EspSoftwareSerial::UART serialPort;
#define serial_Tx 12
#define serial_Rx 13

void setup() {
  // Setup the Serial Port with your computer for Serial Monitor Data
  Serial.begin(9600);
  delay(500);

  // Setup serial connection to VESC
  serialPort.begin(115200, SWSERIAL_8N1, serial_Rx, serial_Tx, false);
  delay(500);

  
  vesc.setSerialPort(&serialPort);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint16_t sensor_data = 0;

  sensor_data = adc1_get_raw(ADC1_CHANNEL_3);
  Serial.println(sensor_data);
  
}

//void handle_torque(uint16_t sensor_data, uint16_t &filtered_data, int32_t &acceleration){
//  
//  
//}

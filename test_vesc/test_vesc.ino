#include <VescUart.h>

int dutyVal = 70;
int rpmVal = 5;
int testDuty = 1;


/** Initiate VescUart class */
VescUart vesc;

void setup() {
  // Setup the Serial Port for UART communication
  Serial.begin(115200);
  delay(500);
  while (!Serial) {;}

  UART.setSerialPort(&Serial);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (testDuty)
    vesc.setDuty(dutyVal / 100.0);
  else
    vesc.setRPM(rpmVal);

  if ( UART.getVescValues() ) {
    Serial.println(UART.data.rpm);
    Serial.println(UART.data.inpVoltage);
    Serial.println(UART.data.ampHours);
    Serial.println(UART.data.tachometerAbs);
  }

  delay(1000);
}

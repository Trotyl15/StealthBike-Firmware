



// uint8_t finalReadingArray[200];
// void setup() {
//   //U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R1,/* reset=*/ U8X8_PIN_NONE, /* clock=*/ 9, /* data=*/ 10);
//   for (int i = 0; i<200; i++){
//     finalReadingArray[i] = 0;
//   }
//   Serial.begin(9600);
//   pinMode(9, INPUT_PULLUP);
  
// }


//   uint8_t inputArray[4] = {1,1,1,1};
//   uint8_t counter = 0;

//   uint8_t status = 0;
  
//   uint8_t finalCounter = 0;

// void loop() {
//   // put your main code here, to run repeatedly:
//     (void)checkForRotation(inputArray, &status, counter, finalReadingArray, finalCounter);
//     Serial.println(rpmCalculation(finalReadingArray));
//     //Serial.println(digitalRead(9));

//     counter = (counter == 4) ? 0 : counter+1;
//     finalCounter = (finalCounter == 200) ? 0 : finalCounter+1;



//   delay(10);

// }
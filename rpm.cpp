// #include <cmath>

// void RPMRead(void){
//   pinMode(9, INPUT_PULLUP);
//   uint8_t inputArray[4] = {1,1,1,1};
//   uint8_t counter = 0;

//   uint8_t status = 0;
//   uint8_t finalReadingArray[50];
//   uint8_t finalCounter = 0;
//   for(;;){  //12 magnets per rotation
   

// }

// int checkForRotation(uint8_t* readingArray, uint8_t* status, uint8_t counter, uint8_t* finalReadingArray, uint8_t finalCounter){
//   readingArray[counter%4] = digitalRead(9);

//     int sum = 0;
//     for (int i{0}; i<4; i++){
//       sum += readingArray[i];
//     }

//     if ((sum == 0 && *status == 0) || (sum == 4 && *status == 1)){ //If we are looking for 0s and get 0s OR if we are looking for all 1s and get 1s
//       (*status) ^= 1;
//       finalReadingArray[finalCounter%50] = 1;
//       return 1;
//     } else {
//       return 0;
//     }

// }


// float rpmCalculation(uint8_t* finalReadingArray){
//   float rpm = 0;
//   for (int i{0}; i<50; i++){
//     rpm += finalReadingArray[i];
//   }
//   rpm /= 24;  

// }


// //Sample rate - 1ms, 3ms = 1 count, 166 counts per second = 13.9 rotations per second = 24 m/s = 80 km/h 
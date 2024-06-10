// int checkForRotation(uint8_t* readingArray, uint8_t* status, uint8_t counter, uint8_t* finalReadingArray, uint8_t finalCounter){
//   readingArray[counter] = digitalRead(9);

//     int sum = 0;
//     for (int i{0}; i<4; i++){
//       sum += readingArray[i];
//     }

//     if ((sum == 0 && (*status) == 0) || (sum == 4 && (*status) == 1)){ //If we are looking for 0s and get 0s OR if we are looking for all 1s and get 1s
//       (*status) ^= 1;
//       finalReadingArray[finalCounter] = 1;
//       return 1;
//     } else {
//       finalReadingArray[finalCounter] = 0;
//       return 0;
//     }
// }

// float rpmCalculation(uint8_t* finalReadingArray){
//   float rpm = 0;
//   for (int i{0}; i<200; i++){
//     rpm += finalReadingArray[i];
//   }
//   //rpm = rpm/24;
//   return rpm;  
// }

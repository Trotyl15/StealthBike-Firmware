// #include <cmath>

// void RPMRead(void){
//   pinMode(9, INPUT_PULLUP);
//   uint8_t readingArray[4] = {1,1,1,1};
//   uint8_t status = 0;
//   uint8_t magnetCount = 0;
//   uint8_t counter = 0;
//   for(;;){  //12 magnets per rotation
//     magnetCount

//     counter++;
//   }

// }

// int checkForRotaion(int* readingArray, int* status, int counter){
//   readingArray[counter%4] = digitalRead(9);

//     int sum = 0;
//     for (int i{0}; i<4; i++){
//       sum += readingArray[i];
//     }

//     if ((sum == 0 && *status == 0) || (sum == 4 && *status == 1)){ //If we are looking for 0s and get 0s OR if we are looking for all 1s and get 1s
//       (*status) ^= 1;
//       return 1;
//     } else {
//       return 0;
//     }

// }


// int rpmCalculation(int* magnetCount, int counter){
  
//   int rotation = 

// }


// //Sample rate - 1ms, 3ms = 1 count, 166 counts per second = 13.9 rotations per second = 24 m/s = 80 km/h 
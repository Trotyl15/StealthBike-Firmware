#include <cmath>


int currVal;
int prevVal;
int prevVal2;
int initial = 0;
// NEED TO FIND RIGHT VALUE
int threshold = 30


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}




// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  
  currVal = analogRead(A0);
  if (initial==0){
    prevVal = currVal;
    prevVal2 = currVal;
    initial = 1;
  }


  if (abs(abs(prevVal-currVal)-abs(prevVal-prevVal2)) < threshold){
    prevVal = currVal;
  }
  // print out the value you read:
  Serial.println(prevVal);
  delay(100);  // delay in between reads for stability
}

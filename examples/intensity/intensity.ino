#include <Matrix_LED.h>

MLED mled(0); //set intensity=0

void setup() {
  for (int i = 0; i < 8; i++) {
    mled.disBuffer[i]=0xff; // Set all in the current row
  }  
}

void loop() {
  for (int i = 0; i < 8; i++) {
    mled.intensity=i; //Change intensity
    mled.display();
    delay(1000);
  }
}

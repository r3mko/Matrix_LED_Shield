#include <Matrix_LED.h>

MLED mled(4); //set intensity=4

void setup() {}

void loop() {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
        mled.dot(x, y); // draw dot
        mled.display();
        delay(200);
        mled.dot(x, y, 0); //clear dot
        mled.display();
        delay(200);        
    }  
  }
}

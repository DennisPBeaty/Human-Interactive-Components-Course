#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
 
void setup() {
  SerialBT.begin("Corporeal Eyedropper");
}
 
void loop() {
  SerialBT.println("Hello World");
  delay(1000);
}

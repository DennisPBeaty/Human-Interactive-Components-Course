// 3 is red which is total 1 and z
// 4 is green which is total 2 and x
// 5 is yellow which is total 3 and c

#include <CapacitiveSensor.h>

CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);      
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); 
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);  
 
int total1; 
int total2;
int total3;

void setup() {
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  Serial.begin(9600);
}

void loop() {
  long total1 =  cs_2_3.capacitiveSensor(3000);
  long total2 =  cs_2_4.capacitiveSensor(3000);
  long total3 =  cs_2_5.capacitiveSensor(3000);

  if (total1 >= 2000) {
     Serial.println("pressZ\n");
     delay(100);
  }
  if (total2 >= 2000) {
     Serial.println("pressX\n");
     delay(100);
  }
  if (total3 >= 2000) {
     Serial.println("pressC\n");
     delay(100);
  }

  
    //Serial.print(total1);
    //Serial.print("\t");
    //Serial.print(total2);
    //Serial.print("\t");
    //Serial.print(total3);
    //Serial.println("\t");
}

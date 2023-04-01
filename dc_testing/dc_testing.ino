int motorControl=8;
void setup(){
pinMode(motorControl,OUTPUT);
}
void loop(){
for(int x = 0; x <= 255; x+=5){
      analogWrite(motorControl, x);
      delay(50);
    }

    for(int x = 255; x >= 0; x-=5){
      analogWrite(motorControl, x);
      delay(50);
    }
}

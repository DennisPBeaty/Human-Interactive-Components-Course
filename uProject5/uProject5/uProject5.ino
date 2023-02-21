// Preston Beaty
// uProject5
// 2/21/2023
// COSC 494

const int sampleSpeed = 50;
unsigned int soundRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  unsigned long startSample = millis();
//  unsigned int peak = 0;
//  unsigned int soundMin = 0;
//  unsigned int soundMax= 1024;
//
//  while(millis() - startSample < sampleSpeed) {
//    soundRead = analogRead(0);
//    if (soundRead < 1024)
//    {
//      soundMax = soundRead;  
//    }
//    else if (soundRead < soundMin){
//      soundMin = soundRead;  
//    }
//  }
//
//  peak = soundMax - soundMin;
//  double volts = (peak * 5.00) / 1024;
//
//  Serial.println(volts);

// read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
}

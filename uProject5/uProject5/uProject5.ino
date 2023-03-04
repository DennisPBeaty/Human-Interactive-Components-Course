// White/Potato = pin 13
// Green/Tomato = pin 27
// Red/Buzzer = pin 10

const int potato = 13;
const int tomato = 27;
const int buzzer = 10;
int tomVal = 0;
int potVal = 0;

void readVals() {
    tomVal = touchRead(27);
    potVal = touchRead(13);
}

void printPot() {
  Serial.println(potVal);  
}

void printTom() {
  Serial.println(tomVal);  
}

void setup()
{
 Serial.begin(115200);
 delay(1000); 
}
void loop(){
  ledcDetachPin(buzzer);
  readVals();
  
  if (potVal < 30 && tomVal < 30) {
    ledcAttachPin(buzzer, 0);
    ledcWriteNote(0, (note_t)NOTE_G, 8);
  }
  else if (potVal < 30) {
    ledcAttachPin(buzzer, 0);
    ledcWriteNote(0, (note_t)NOTE_D, 8);
  }
  else if (tomVal < 30) {
    ledcAttachPin(buzzer, 0);
    ledcWriteNote(0, (note_t)NOTE_A, 8);
  }
}

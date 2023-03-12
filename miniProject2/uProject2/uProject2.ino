// Green is Z which is Shield
// Blue is C which is Syringe
// Orange is X which is Phoenix kit
const int button1 = 12; 
const int button2 = 11; 
const int button3 = 10; 

int prevState1 = HIGH; 
int state1;
int prevState2 = HIGH; 
int state2;
int prevState3 = HIGH; 
int state3;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
  state3 = digitalRead(button3);

  if (state1 == LOW && prevState1 == HIGH) {
    Serial.println("pressZ");
    delay(50);
  }
  if (state2 == LOW && prevState2 == HIGH) {
    Serial.println("pressX");
    delay(50);
  }
  if (state3 == LOW && prevState3 == HIGH) {
    Serial.println("pressC");
    delay(50);
  }
  
  prevState1 = state1;
  prevState2 = state2;
  prevState3 = state3;
}

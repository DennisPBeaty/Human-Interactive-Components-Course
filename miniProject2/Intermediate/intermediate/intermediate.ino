const int button1 = 12; 

int prevState1 = HIGH; 
int state1;
uint8_t buf[8] = {0}; //Keyboard timing buffer.

void setup() {
  pinMode(button1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  state1 = digitalRead(button1);

  if (state1 == LOW && prevState1 == HIGH) {
    Serial.println("pressA");
    delay(50);
  }
  
  prevState1 = state1;
}

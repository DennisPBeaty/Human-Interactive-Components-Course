int blue_led = 12;
int delay_speed = 5;
int ledValue = 0;
int maxValue = 255;
int minValue = 0;
bool countUp = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blue_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(blue_led, ledValue);
  delay(delay_speed);
  Serial.println("Led Value is: " + String(ledValue));

  if (countUp == true) {
    ledValue++;
    if (ledValue >= maxValue) {
      countUp = false;
    }
  }
  else {
    ledValue--;
    if (ledValue <= minValue) {
      countUp = true;
    }
  }
}

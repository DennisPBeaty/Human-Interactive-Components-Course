int blue_led = 12;
int delay_speed = 250;
void setup() {
  // put your setup code here, to run once:
  pinMode(blue_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(blue_led, HIGH);
  delay(delay_speed);
  digitalWrite(blue_led, LOW);
  delay(delay_speed);
}

int blue_led = 12;
int green_led = 11;
int red_led = 10;
int yellow_led = 9;

int delay_speed = 250;
void setup() {
  // put your setup code here, to run once:
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(blue_led, HIGH);
  delay(2000);
  digitalWrite(blue_led, LOW);
  digitalWrite(green_led, HIGH);
  delay(1000);
  digitalWrite(green_led, LOW);
  digitalWrite(red_led, HIGH);
  delay(500);
  digitalWrite(red_led, LOW);
  digitalWrite(yellow_led, HIGH);
  delay(250);
  digitalWrite(yellow_led, LOW);
  delay(250);
  digitalWrite(yellow_led, HIGH);
  delay(250);
  digitalWrite(yellow_led, LOW);
  delay(250);
  digitalWrite(yellow_led, HIGH);
  delay(250);
  digitalWrite(yellow_led, LOW);
  delay(250);
  digitalWrite(yellow_led, HIGH);
  delay(250);
  digitalWrite(yellow_led, LOW);
  delay(500);
}

int blue_led = 12;
int green_led = 11;
int red_led = 10;
int yellow_led = 9;
int potentiometerPin = A0;
int potentiometerVal = 0;

float reduceVal = 0.00488758553;

int delay_speed = 250;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
}

void loop() {
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  // put your main code here, to run repeatedly:
  digitalWrite(blue_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *2000);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(blue_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(green_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *1000);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(green_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(red_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *500);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(red_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  digitalWrite(yellow_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, HIGH);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *250);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  digitalWrite(yellow_led, LOW);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  delay( (potentiometerVal * reduceVal) *500);
  potentiometerVal = analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
}

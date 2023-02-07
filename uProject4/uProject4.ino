int blue_led = 12;
int green_led = 11;
int red_led = 10;
int yellow_led = 9;
int lightSensor = A0;

void setup() {
  Serial.begin(9600);
  int lightValue = analogRead(lightSensor);
  // put your setup code here, to run once:
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("New Loop");

  int lightValue = analogRead(lightSensor);
  
  if (lightValue < 30) {
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
    Serial.println("Blue");
  } else if (lightValue < 200) {
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
    Serial.println("Green");
  } else if (lightValue < 500) {
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, HIGH);
    Serial.println("Red");
  } else if (lightValue < 800) {
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, LOW);
    Serial.println("Yellow");
  }
}

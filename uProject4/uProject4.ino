int blue_led = 12;
int green_led = 11;
int red_led = 10;
int yellow_led = 9;
int potentiometerPin = A0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
}

void loop() {
  Serial.println("Program start");
  // put your main code here, to run repeatedly:
  digitalWrite(blue_led, HIGH);

}

const int trig = 9;
const int echo = 10;

long time;
int distance;
String direction;
int potVal;
int forceVal;

void readDistance() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  time = pulseIn(echo, HIGH);
  distance = time * .034 / 2;

  if (distance <= 5) {
    direction = "LEFT";
  }
  else if (distance <= 9) {
    direction = "UP";
  }
  else if (distance <= 14) {
    direction = "RIGHT";
  }
  else {
    direction = "DOWN";
  }
}

void potRead() {
  potVal = analogRead(A0);
}

void potPrint() {
  Serial.print("Potentiometer Value: ");
  Serial.println(potVal);
}

void printDistance(){
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm.");
}

void forceRead() {
  forceVal = analogRead(A1);
}

void forcePrint() {
  Serial.print("Force Value: ");
  Serial.println(forceVal);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readDistance();
  potRead();
  forceRead();
}

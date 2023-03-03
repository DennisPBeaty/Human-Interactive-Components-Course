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

int randomOption() {
  return random(1,5);
}
const int buzzer = 3;

extern volatile unsigned long timer0_millis;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void lightNone() {
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void lightAll() {
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void lightOne() {
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
}

void lightTwo() {
  digitalWrite(A2, HIGH);
  digitalWrite(4, HIGH);
}

void lightThree() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
}

void lightFour() {
  digitalWrite(A4, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void playSound() {
  tone(buzzer, 500);
  delay(250);
  noTone(buzzer);  
}

void endSound() {
  tone(buzzer, 500);
  delay(250);
  tone(buzzer, 750);
  delay(250);
  tone(buzzer, 1000);
  delay(250);
  tone(buzzer, 1250);
  delay(250);
  tone(buzzer, 1500);
  delay(250);
  tone(buzzer, 1750);
  delay(250);
  tone(buzzer, 2000);
  delay(250);
  tone(buzzer, 2250);
  delay(250);
  noTone(buzzer);  
}

// For the Lights
// 1: A5
// 2: A4
// 3: A3
// 4: A2
// 5: 4
// 6: 5
// 7: 6
// 8: 7

void readValues() {
  readDistance();
  potRead();
  forceRead();
}

int pastOption = 0;
unsigned long minutes = 6000;
bool playing = true;

//we want game to range between length of 1-5

void loop() {
  // put your main code here, to run repeatedly:
  int score = 0;
  int option = 0;
  
  if (playing) {
    if (millis() < minutes * 1) {
      
      bool newVal = false;
      while (!newVal) {
        option = randomOption();
        if (option != pastOption) {
            pastOption = option;
            newVal = true;
        }
      }
      bool correct = false;
      
      while (!correct) {
        if (option == 1) {
          lightOne();
          readValues();
          if (0 <= distance && distance <= 5) {
              score++;
              playSound();
              correct = true;    
          }
        }
        else if (option == 2) {
          lightTwo();
          readValues();
          if (5 < distance && distance <= 9) {
              score++;
              playSound();
              correct = true;    
          }
        }
        else if (option == 3) {
          lightThree();
          readValues();
          if (9 < distance && distance <= 14) {
              score++;
              playSound();
              correct = true;    
          }
        }
        else if (option == 4) {
          lightFour();
          readValues();
          if (14 < distance) {
              score++;
              playSound();
              correct = true;    
          }
        }
      }
      lightNone();
    }
    else {
      endSound();
      playing = false;
    }
  }
  else {
    Serial.println(score);
    forceRead();
    if (forceVal >= 100) {
      playing = true;
    }
    noInterrupts ();
    timer0_millis = 0;
    interrupts ();
  }
}
  

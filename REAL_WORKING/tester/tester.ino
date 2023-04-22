#define BUTTON_PIN 21
#define S0 22
#define S1 14
#define S2 4
#define S3 16
#define sensorOut 17

#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;

// Calibration Values
// *Get these from Calibration Sketch
int redMin = 17; // Red minimum value
int redMax = 168; // Red maximum value
int greenMin = 18; // Green minimum value
int greenMax = 218; // Green maximum value
int blueMin = 14; // Blue minimum value
int blueMax = 172; // Blue maximum value

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Variables for final Color values
int redValue;
int greenValue;
int blueValue;

void setup() {
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  //button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Setup Serial Monitor
  SerialBT.begin("Corporeal Eyedropper");
}

void loop() {
  // Read Red value
  redPW = getRedPW();
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(200);

  // Read Green value
  greenPW = getGreenPW();
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(200);

  // Read Blue value
  bluePW = getBluePW();
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(200);

  if (redValue < 0) {
    redValue = 0;
  }
  if (greenValue < 0) {
    greenValue = 0;
  }
  if (blueValue < 0) {
    blueValue = 0;
  }

  // Print output to Serial Monitor
  SerialBT.print("Red = ");
  SerialBT.print(redValue);
  SerialBT.print(" - Green = ");
  SerialBT.print(greenValue);
  SerialBT.print(" - Blue = ");
  SerialBT.println(blueValue);

  if (digitalRead(BUTTON_PIN) == 0) {
    SerialBT.println("ACTIVATE");  
  }
}


// Function to read Red Pulse Widths
int getRedPW() {
  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {
  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Blue Pulse Widths
int getBluePW() {
  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int voltageSensorPin = A0;   
const int ledPin1 = 3;             
const int ledPin2 = 4;             
const int ledPin3 = 5;             

float voltage = 0.0;
int milliVoltage = 0;

// Threshold voltage to detect footstep
const int threshold = 50;  // mV

void setup() {

  lcd.init();
  lcd.backlight();

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);   

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Footstep Power");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
}

void loop() {

  int sensorValue = analogRead(voltageSensorPin);
  voltage = (sensorValue * 5000.0) / 1023.0;
  milliVoltage = (int) voltage;
  if (milliVoltage > threshold) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);   
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);    
  }

  Serial.print("Voltage: ");
  Serial.print(milliVoltage);
  Serial.println(" mV");

  // LCD display
  lcd.setCursor(9, 0);
  lcd.print("      ");
  lcd.setCursor(9, 0);
  lcd.print(milliVoltage);
  lcd.print("mV");

  delay(500);
}



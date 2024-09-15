
#include <LiquidCrystal.h>

// Define LCD pin connections (adjust based on your wiring scheme)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ledPin = 13; // LED connected to pin 13
const int voltagePin = A0;

// Function to read voltage (adjust conversion factor based on your circuit)
float readVoltage() {
  // Read analog value
  int analogReading = analogRead(voltagePin);
  
  // Convert analog reading to voltage (assuming a 5V reference and adjust factor if needed)
  float voltage = analogReading * 5.0 / 1023.0;
  return voltage;
}


void setup() {
  Serial.begin(9600);
  // Initialize LED pin as output
  pinMode(ledPin, OUTPUT);
  // Configure analog input pin
  lcd.begin(16, 2);
  
  // Set LCD display to show voltage in two decimal places
  lcd.print(F("Voltage: "));
  lcd.print(".");
  lcd.print(0);  // Placeholder for decimal digits
  lcd.print(0);
}

void loop() {

  float voltage = readVoltage();

  lcd.setCursor(9, 0);  // Set cursor to the second row, 9th column
  // Print the voltage value with two decimal places
  lcd.print(voltage, 2);  


  // Print the voltage reading to the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V"); 

  // Control LED based on voltage (optional)
  if (voltage > 2.5) { // Adjust threshold voltage for LED illumination
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED
  }

  // Delay between readings (adjust as needed)
  delay(5000);
}

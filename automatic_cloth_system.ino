#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

Servo clothLineServo;

const int rainSensorPin = A0;
const int servoPin = 9;

int rainThreshold = 400; // Adjust based on calibration

void setup() {
  Serial.begin(9600);

  clothLineServo.attach(servoPin);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true); // Halt
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  clothLineServo.write(0); // Start with line extended
  displayMessage("System Ready", "Line: Extended");
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < rainThreshold) {
    // Rain Detected
    clothLineServo.write(90); // Retract line
    displayMessage("Rain Detected", "Line: Retracted");
  } else {
    // No Rain
    clothLineServo.write(0); // Extend line
    displayMessage("Weather Clear", "Line: Extended");
  }

  delay(3000); // Wait before rechecking
}

void displayMessage(String status, String action) {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Auto Cloth Line");
  display.setCursor(0, 30);
  display.println(status);
  display.setCursor(0, 45);
  display.println(action);
  display.display();
}


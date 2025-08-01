#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT settings
#define DHTPIN 2          // Digital pin connected to DHT11
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is typical OLED I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.println("Weather Monitor");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Display readings on serial monitor
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.print(F(" °C  Humidity: "));
  Serial.print(humidity);
  Serial.println(F(" %"));

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.println("Weather Monitor");

  display.setCursor(0, 20);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.display();
  delay(2000);
}


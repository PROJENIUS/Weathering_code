# Weathering_code
# 🌤️ Arduino Weather Monitoring System

This project is a simple weather monitoring system using a **DHT11 temperature & humidity sensor** and a **128x64 OLED display (SSD1306)**. It displays live temperature and humidity readings on the OLED screen.

---

## 🧰 Components

- Arduino Uno or Nano
- DHT11 Sensor
- OLED Display (128x64 I2C - SSD1306)
- Jumper Wires
- Breadboard (optional)

---

## 🔌 Connections

### DHT11:
- VCC → 5V
- GND → GND
- DATA → D2

### OLED:
- VCC → 5V  
- GND → GND  
- SCL → A5 (UNO)  
- SDA → A4 (UNO)  

---

## 📦 Libraries Required

Install the following libraries via Arduino Library Manager:

- **Adafruit SSD1306**
- **Adafruit GFX**
- **DHT sensor library**

---

## 🧪 How It Works

- Reads **temperature (°C)** and **humidity (%)** from the DHT11 sensor.
- Displays the values on the OLED display.
- Also prints the readings to the Serial Monitor for debugging.

---

## 🕹️ Usage

1. Connect all components as shown above.
2. Upload the code to your Arduino board using the Arduino IDE.
3. Open the Serial Monitor (9600 baud).
4. View real-time data on the OLED screen.

---

## 📈 Sample Output

Temperature: 27.4 °C
Humidity: 60.2 %  


OLED Display:

Weather Monitor
Temp: 27.4 C
Humidity: 60.2 %


## 🛠️ Future Scope

- Upgrade to DHT22 for better accuracy
- Add weather icons or graphics
- Log data to SD card or send to cloud (e.g., Thingspeak)

---


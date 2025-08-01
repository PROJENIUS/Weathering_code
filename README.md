# ☁️ Automatic Cloth Line System using Rain Sensor, Servo Motor & OLED (IoT Project)

This Arduino-based IoT project automatically retracts or extends a cloth line based on weather conditions detected by a rain sensor. A servo motor physically moves the cloth line, and an OLED display shows real-time status messages like "Rain Detected" or "Weather Clear".

---

## 🔧 Features

- 🌧️ **Rain Detection** using analog rain sensor
- ⚙️ **Servo-controlled cloth line** (extends or retracts)
- 🖥️ **OLED Display** (128x64 SSD1306) shows system status
- 💡 Easily expandable with IoT platforms like Blynk, Firebase, or ThingSpeak

---

## 🧰 Hardware Requirements

| Component          | Description                  |
|-------------------|------------------------------|
| Arduino Uno/Nano  | Microcontroller board        |
| Rain Sensor       | YL-83 or FC-37 module        |
| Servo Motor       | SG90 or MG90S                |
| OLED Display      | 0.96" I2C SSD1306 (128x64)   |
| Breadboard + Wires| For connections              |
| External 5V Power | Optional (for servo power)   |

---

## 🖇️ Circuit Connections

### 🟦 Rain Sensor (Analog Mode)
| Rain Sensor Pin | Arduino Pin |
|-----------------|-------------|
| AO              | A0          |
| VCC             | 5V          |
| GND             | GND         |

### 🔁 Servo Motor
| Servo Pin  | Arduino Pin |
|------------|-------------|
| Signal     | D9          |
| VCC        | 5V          |
| GND        | GND         |

### 📺 OLED Display (I2C)
| OLED Pin | Arduino Uno/Nano Pin |
|----------|----------------------|
| SDA      | A4                   |
| SCL      | A5                   |
| VCC      | 3.3V / 5V            |
| GND      | GND                  |

---

## 📜 Code Overview

### Libraries Used
Install via **Arduino Library Manager**:
- `Adafruit GFX Library`
- `Adafruit SSD1306`

### Functional Flow
1. Reads analog value from rain sensor.
2. If **rain is detected**:
   - OLED displays `Rain Detected`
   - Servo moves to **retracted** position.
3. If **weather is clear**:
   - OLED displays `Weather Clear`
   - Servo moves to **extended** position.
4. OLED continuously updates the current system state.

---

## 🧪 Calibration Tip

You can adjust the sensitivity by tweaking this line in the code:

```cpp
int rainThreshold = 400; // Adjust this value based on your sensor

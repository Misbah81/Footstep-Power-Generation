# 👣 Footstep Power Generation System (Arduino + LCD + Voltage Detection)

A simple embedded system project that detects voltage generated from footstep pressure (piezoelectric or similar source) and displays the generated voltage on an LCD while triggering LEDs when a threshold is exceeded.

---

# 📌 Project Overview

This project demonstrates **energy harvesting from footsteps**. When pressure is applied to a sensor (e.g., piezo plate), it generates a small voltage. The Arduino reads this voltage, converts it into millivolts, displays it on an LCD, and activates LEDs if the voltage crosses a defined threshold.

This project is useful for:

* Smart floor systems
* Energy harvesting demos
* IoT sensor triggers
* Educational embedded systems labs

---

# 🧰 Hardware Components Required

| Component                    | Quantity  | Description                     |
| ---------------------------- | --------- | ------------------------------- |
| Breadboard                   | 1         | Circuit prototyping board       |
| LEDs                         | 3         | Visual indicators               |
| Jumper Wires                 | Several   | Connections between components  |
| Piezoelectric Sensors        | 1 or more | Generates voltage from pressure |
| Rectifier Circuit (4 Diodes) | 1         | Converts AC from piezo to DC    |
| Voltage Sensor Module        | 1         | Reads generated voltage safely  |
| LCD 16×2 (I2C)               | 1         | Displays voltage readings       |
| 18650 Li‑ion Battery         | 1         | Power storage / supply          |
| Arduino Uno                  | 1         | Microcontroller board           |
| Resistors                    | 3+        | Current limiting for LEDs       |

---

# 💻 Software Requirements

* Arduino IDE (latest version recommended)
* USB Driver for Arduino (if not auto-installed)

---

# 📚 Required Libraries

Install these libraries in Arduino IDE:

1. **LiquidCrystal_I2C**
2. **Wire** (pre-installed with Arduino IDE)

### How to Install Library

1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for **LiquidCrystal_I2C**
4. Click **Install**

---

# 🔌 Circuit Connections

## LCD (I2C)

| LCD Pin | Arduino |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| SDA     | A4      |
| SCL     | A5      |

---

## Voltage Sensor

| Sensor | Arduino |
| ------ | ------- |
| Output | A0      |
| GND    | GND     |

---

## LEDs

| LED  | Arduino Pin |
| ---- | ----------- |
| LED1 | 3           |
| LED2 | 4           |
| LED3 | 5           |

(All LEDs must have 220Ω resistors in series.)

---

# ⚙️ Working Principle

1. Footstep applies pressure to sensor.
2. Sensor generates small voltage.
3. Arduino reads analog value from A0.
4. Value converted to millivolts.
5. LCD displays voltage.
6. If voltage > threshold → LEDs turn ON.

---

# 📊 Voltage Calculation Formula

Arduino ADC resolution = **10-bit (0–1023)**

Voltage formula used:

```
Voltage(mV) = (ADC_value × 5000) / 1023
```

---

# 🚀 Step-by-Step Setup Guide

### Step 1 — Assemble Circuit

Connect LCD, sensor, and LEDs according to wiring tables.

### Step 2 — Install Libraries

Install LiquidCrystal_I2C library.

### Step 3 — Upload Code

* Connect Arduino via USB
* Select Board → Arduino Uno
* Select correct COM Port
* Click Upload

### Step 4 — Test System

Press or step on sensor → LCD should display voltage and LEDs should glow.

---

# 🧪 Calibration (Optional)

If sensor outputs small voltage:

Change threshold value:

```
const int threshold = 50;
```

Suggested ranges:

* 20 → very sensitive
* 100 → medium
* 200 → strong pressure only

---

# 📈 Future Improvements

* Store generated energy in capacitor
* Add battery charging circuit
* Log data to SD card
* Wireless monitoring (ESP8266)
* Add graph plotting

---

# 🐞 Troubleshooting

| Problem            | Solution                         |
| ------------------ | -------------------------------- |
| LCD not displaying | Check I2C address (0x27 or 0x3F) |
| LED not glowing    | Check resistor & polarity        |
| Voltage always 0   | Sensor wiring incorrect          |
| Random values      | Add capacitor filter             |

---

# 📜 License

Open-source project for educational and research purposes.

---

# 🙌 Author

**Misbah Rafique**

GitHub Repository:
[https://github.com/Misbah81/Footstep-Power-Generation](https://github.com/Misbah81/Footstep-Power-Generation)

---

⭐ *If you like this project, consider starring the repo!*

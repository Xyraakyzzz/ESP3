# Arduino Ultrasonic Distance Indicator

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang

Proyek ini merupakan indikator jarak sederhana menggunakan sensor ultrasonik **HC-SR04** dan Arduino. Sensor akan mengukur jarak objek di depannya, kemudian menyalakan LED indikator sesuai dengan rentang jarak yang terdeteksi.

Nilai jarak juga akan ditampilkan pada **Serial Monitor**.

## Fitur

- Mengukur jarak menggunakan HC-SR04
- Menampilkan hasil pengukuran pada Serial Monitor
- Indikator LED berdasarkan jarak objek
- Program sederhana untuk pembelajaran sensor ultrasonik

---

## Komponen

- Arduino Uno / Nano
- HC-SR04 Ultrasonic Sensor
- 4 LED
- 4 Resistor 220Ω
- Breadboard
- Jumper Wire

---

## Konfigurasi Pin

### HC-SR04

| Sensor | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| Trig | D3 |
| Echo | D2 |

### LED

| LED | Pin |
|-----|-----|
| LED 1 | D12 |
| LED 2 | D11 |
| LED 3 | D10 |
| LED 4 | D9 |

---

## Indikator Jarak

| Jarak | LED Aktif |
|--------|-----------|
| ≥ 300 cm | D12 & D9 |
| 200–299 cm | D11 |
| < 200 cm | D10 |

---

## Library

Tidak memerlukan library tambahan.

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project is a simple distance indicator using the **HC-SR04 ultrasonic sensor** and Arduino. The sensor measures the distance to an object and lights different LEDs depending on the detected range.

The measured distance is also displayed on the **Serial Monitor**.

## Features

- Distance measurement using HC-SR04
- Serial Monitor output
- LED indicators based on distance
- Beginner-friendly Arduino example

---

## Components

- Arduino Uno / Nano
- HC-SR04 Ultrasonic Sensor
- 4 LEDs
- 4 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Configuration

### HC-SR04

| Sensor | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| Trig | D3 |
| Echo | D2 |

### LEDs

| LED | Arduino Pin |
|-----|-------------|
| LED 1 | D12 |
| LED 2 | D11 |
| LED 3 | D10 |
| LED 4 | D9 |

---

## Distance Indicator

| Distance | Active LED |
|----------|------------|
| ≥ 300 cm | D12 & D9 |
| 200–299 cm | D11 |
| < 200 cm | D10 |

---

## Library

No additional libraries are required.

---

## Programming Language

- Arduino C++

---

## License

This project is licensed under the terms described in the **LICENSE** file.

---

**Author:** Xyraa Kyxzz

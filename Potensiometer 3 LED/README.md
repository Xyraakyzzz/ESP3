# Arduino Analog Level Indicator

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang Proyek

Proyek ini merupakan indikator level sederhana berbasis **Arduino** yang menggunakan nilai input analog untuk mengendalikan tiga buah LED sebagai indikator.

Nilai analog dibaca dari pin **A0**, kemudian dipetakan ke rentang **0–300** menggunakan fungsi `map()`. Berdasarkan nilai tersebut, salah satu LED akan menyala sebagai indikator level.

Proyek ini cocok untuk mempelajari:

- Arduino Analog Input
- ADC (Analog to Digital Converter)
- Penggunaan fungsi `map()`
- Kontrol LED berdasarkan nilai sensor

---

## Fitur

- Membaca input analog dari pin A0
- Mengubah nilai ADC menjadi rentang 0–300
- Menampilkan level menggunakan 3 LED
- Program sederhana dan mudah dipelajari

---

## Komponen

| Komponen | Jumlah |
|----------|--------|
| Arduino Uno/Nano | 1 |
| LED | 3 |
| Resistor 220Ω | 3 |
| Potensiometer 10K *(atau sensor analog lainnya)* | 1 |
| Breadboard | 1 |
| Jumper Wire | Secukupnya |

---

## Konfigurasi Pin

| Komponen | Pin Arduino |
|----------|-------------|
| Input Analog | A0 |
| LED Hijau | D11 |
| LED Kuning | D12 |
| LED Merah | D13 |

---

## Cara Kerja

- Nilai analog dibaca dari pin **A0**.
- Nilai tersebut dipetakan dari **0–1023** menjadi **0–300**.
- Berdasarkan hasil pembacaan:
  - **0–99** → LED Hijau menyala.
  - **100–199** → LED Kuning menyala.
  - **200–300** → LED Merah menyala.

---

## Library

Tidak memerlukan library tambahan.

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project is a simple **Arduino-based analog level indicator** that uses an analog input to control three LEDs.

The analog value is read from pin **A0** and mapped to a **0–300** range using the `map()` function. Depending on the measured value, one of the LEDs turns on to indicate the current level.

This project is suitable for learning:

- Arduino Analog Input
- ADC (Analog-to-Digital Conversion)
- Using the `map()` function
- LED control based on sensor values

---

## Features

- Reads analog input from A0
- Maps ADC values to a 0–300 range
- Displays three different indicator levels
- Simple and beginner-friendly code

---

## Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno/Nano | 1 |
| 3 LEDs | 3 |
| 220Ω Resistors | 3 |
| 10K Potentiometer *(or any analog sensor)* | 1 |
| Breadboard | 1 |
| Jumper Wires | As needed |

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Analog Input | A0 |
| Green LED | D11 |
| Yellow LED | D12 |
| Red LED | D13 |

---

## How It Works

- The Arduino reads the analog value from **A0**.
- The ADC value is mapped from **0–1023** to **0–300**.
- According to the mapped value:
  - **0–99** → Green LED turns on.
  - **100–199** → Yellow LED turns on.
  - **200–300** → Red LED turns on.

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

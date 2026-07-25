# Arduino LED Blinking Sequence

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang

Proyek ini merupakan contoh dasar penggunaan output digital pada Arduino dengan menyalakan tiga buah LED secara bergantian menggunakan fungsi `digitalWrite()` dan `delay()`.

Program ini sangat cocok untuk pemula yang ingin mempelajari dasar pemrograman Arduino dan kontrol LED.

---

## Fitur

- Menyalakan LED secara bergantian
- Menggunakan output digital
- Mudah dipahami dan dimodifikasi
- Cocok untuk latihan dasar Arduino

---

## Komponen

- Arduino Uno / Nano
- 3 LED
- 3 Resistor 220Ω
- Breadboard
- Jumper Wire

---

## Konfigurasi Pin

| LED | Arduino Pin |
|-----|-------------|
| LED 1 | D13 |
| LED 2 | D12 |
| LED 3 | D11 |

---

## Cara Kerja

Program akan menjalankan urutan berikut secara berulang:

1. LED pada pin D13 menyala selama 500 ms kemudian mati.
2. LED pada pin D12 menyala selama 500 ms kemudian mati.
3. LED pada pin D11 menyala selama 500 ms kemudian mati.
4. Proses akan terus berulang selama Arduino menyala.

---

## Library

Tidak memerlukan library tambahan.

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project is a basic Arduino example demonstrating digital output by turning three LEDs on and off sequentially using `digitalWrite()` and `delay()`.

It is suitable for beginners who want to learn the fundamentals of Arduino programming and LED control.

---

## Features

- Sequential LED blinking
- Uses Arduino digital output
- Simple and beginner-friendly
- Easy to modify and expand

---

## Components

- Arduino Uno / Nano
- 3 LEDs
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Configuration

| LED | Arduino Pin |
|-----|-------------|
| LED 1 | D13 |
| LED 2 | D12 |
| LED 3 | D11 |

---

## How It Works

The program repeatedly performs the following sequence:

1. Turn on the LED connected to D13 for 500 ms, then turn it off.
2. Turn on the LED connected to D12 for 500 ms, then turn it off.
3. Turn on the LED connected to D11 for 500 ms, then turn it off.
4. Repeat the sequence continuously while the Arduino is powered.

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

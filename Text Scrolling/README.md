# Arduino LCD Text Scrolling with SD Card

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang

Proyek ini menampilkan teks yang tersimpan pada **microSD Card** ke **LCD 16×2 I2C** dengan efek scrolling dari kanan ke kiri. Teks dibaca secara otomatis dari file **example.txt** yang berada di dalam SD Card.

Proyek ini cocok digunakan sebagai papan informasi, running text sederhana, atau media pembelajaran penggunaan LCD dan SD Card pada Arduino.

---

## Fitur

- Membaca file teks dari microSD Card
- Menampilkan teks pada LCD 16×2 I2C
- Efek scrolling otomatis
- Mendukung teks dengan panjang lebih dari ukuran LCD
- Restart otomatis setelah seluruh teks selesai ditampilkan

---

## Komponen

- Arduino Uno / Nano
- LCD 16×2 I2C
- SD Card Module (SPI)
- MicroSD Card
- Jumper Wire
- Breadboard (Opsional)

---

## Konfigurasi Pin

### LCD I2C

| LCD | Arduino |
|-----|----------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### SD Card Module

| Module | Arduino |
|--------|----------|
| VCC | 3.3V |
| GND | GND |
| CS | D4 |
| MOSI | D11 |
| MISO | D12 |
| SCK | D13 |

---

## Struktur File

Simpan file teks berikut pada root MicroSD Card.

```
example.txt
```

Contoh isi file:

```
Selamat datang di Arduino LCD Scrolling Text.
```

---

## Library

- LiquidCrystal_I2C
- SD

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project displays text stored on a **microSD card** on a **16×2 I2C LCD** with a scrolling animation from right to left. The text is automatically read from **example.txt** located in the root directory of the SD card.

It can be used as a simple information display, scrolling message board, or as an educational example for using LCD and SD card modules with Arduino.

---

## Features

- Reads text from a microSD card
- Displays text on a 16×2 I2C LCD
- Automatic scrolling effect
- Supports text longer than the LCD width
- Automatically restarts after the entire text has been displayed

---

## Components

- Arduino Uno / Nano
- 16×2 I2C LCD
- SD Card Module (SPI)
- MicroSD Card
- Jumper Wires
- Breadboard (Optional)

---

## Pin Configuration

### I2C LCD

| LCD | Arduino |
|-----|----------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### SD Card Module

| Module | Arduino |
|--------|----------|
| VCC | 3.3V |
| GND | GND |
| CS | D4 |
| MOSI | D11 |
| MISO | D12 |
| SCK | D13 |

---

## File Structure

Place the following text file in the root directory of the microSD card.

```
example.txt
```

Example content:

```
Welcome to Arduino LCD Scrolling Text.
```

---

## Libraries

- LiquidCrystal_I2C
- SD

---

## Programming Language

- Arduino C++

---

## License

This project is licensed under the terms described in the **LICENSE** file.

---

**Author:** Xyraa Kyxzz

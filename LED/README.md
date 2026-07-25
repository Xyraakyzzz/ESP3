# LED Control with Push Button (Arduino)

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang Proyek

Proyek ini merupakan program sederhana berbasis **Arduino** untuk mengontrol beberapa LED menggunakan **satu tombol push button**. Setiap urutan penekanan tombol akan mengubah mode kerja LED.

Program ini cocok digunakan sebagai media pembelajaran mengenai:

- Arduino Programming
- Digital Input (Push Button)
- Digital Output (LED)
- Buzzer
- State Machine sederhana

---

## Fitur

- Aktivasi sistem menggunakan push button
- Running LED
- LED berkedip (Blinking)
- Indikator buzzer saat sistem aktif
- Reset otomatis kembali ke mode standby

---

## Komponen

| Komponen | Jumlah |
|----------|--------|
| Arduino Uno/Nano | 1 |
| LED | 4 |
| Resistor 220Ω | 4 |
| Push Button | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wire | Secukupnya |

---

## Konfigurasi Pin

| Komponen | Pin Arduino |
|----------|-------------|
| LED 1 | D2 |
| LED 2 | D3 |
| LED 3 | D4 |
| LED 4 | D5 |
| Buzzer | D7 |
| Push Button | D9 |

---

## Urutan Cara Kerja

1. Sistem berada pada mode standby.
2. Tekan tombol sebanyak **2 kali** untuk mengaktifkan sistem.
3. LED akan menyala sebagai indikator kemudian buzzer berbunyi.
4. Tekan tombol **2 kali** lagi untuk menjalankan mode **Running LED**.
5. Tekan tombol **2 kali** lagi untuk masuk ke mode **Blinking LED**.
6. Tekan tombol **2 kali** lagi untuk menghentikan sistem.
7. Sistem akan melakukan reset dan kembali ke mode standby.

---

## Library

Tidak memerlukan library tambahan.

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project is a simple **Arduino** program that controls multiple LEDs using a **single push button**. Each sequence of button presses changes the operating mode of the LEDs.

This project is suitable for learning:

- Arduino Programming
- Digital Input
- Digital Output
- Buzzer Control
- Simple State Machine

---

## Features

- Push button system activation
- Running LED effect
- Blinking LED mode
- Buzzer activation indicator
- Automatic reset back to standby mode

---

## Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno/Nano | 1 |
| LED | 4 |
| 220Ω Resistor | 4 |
| Push Button | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As needed |

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| LED 1 | D2 |
| LED 2 | D3 |
| LED 3 | D4 |
| LED 4 | D5 |
| Buzzer | D7 |
| Push Button | D9 |

---

## How It Works

1. The system starts in standby mode.
2. Press the button **twice** to activate the system.
3. All LEDs turn on briefly and the buzzer beeps.
4. Press the button **twice** again to start the **Running LED** mode.
5. Press the button **twice** again to switch to **Blinking LED** mode.
6. Press the button **twice** once more to stop the system.
7. The program resets automatically and returns to standby mode.

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

📖 Help Guide / Panduan Penggunaan

Welcome to the Arduino Games Collection repository. This guide explains how to download, install, upload, and play every game included in this project.

Selamat datang di repository Arduino Games Collection. Panduan ini menjelaskan cara mengunduh, memasang, mengunggah, dan memainkan setiap game yang tersedia pada proyek ini.

---

🇺🇸 English

Requirements

Before using this project, prepare the following hardware:

- Arduino Uno R3 (recommended)
- SSD1306 OLED Display (128×64, I2C)
- 3 Push Buttons
- Passive Buzzer
- Breadboard & Jumper Wires
- USB Cable
- Arduino IDE 2.x

Required Arduino Libraries:

- Adafruit GFX Library
- Adafruit SSD1306 Library

Both libraries can be installed from:

Arduino IDE → Library Manager

---

Hardware Wiring

Component| Arduino Pin
OLED SDA| A4
OLED SCL| A5
Button UP| D2
Button DOWN| D3
Button SELECT| D4
Passive Buzzer| D7
OLED VCC| 5V
OLED GND| GND

---

Installation

1. Download or clone this repository.
2. Open the desired ".ino" file using Arduino IDE.
3. Install the required libraries.
4. Connect your Arduino board.
5. Select:
   - Board: Arduino Uno
   - Port: Your Arduino COM Port
6. Click Upload.
7. Wait until uploading is complete.
8. Enjoy the game.

---

Menu Navigation

Button| Function
D2| UP / Jump
D3| DOWN
D4| Select / Return to Menu

---

Available Games

Flappy Bird

Control the bird and avoid incoming pipes.

Controls:

- D2 → Fly
- D4 → Exit to Menu

Objective:

Earn the highest score by passing through as many pipes as possible.

---

Chrome Dino

Jump over obstacles and survive as long as possible.

Controls:

- D2 → Jump
- D4 → Exit

The game speed increases automatically.

---

Pong Pro

Single-player Pong against the wall.

Controls:

- D2 → Move Up
- D3 → Move Down
- D4 → Exit

Each successful hit increases your score.

---

Reaction Test

Test your reaction speed.

Controls:

- D2 → Start / React
- D4 → Exit

Wait until the buzzer sounds, then press D2 as quickly as possible.

---

Troubleshooting

OLED shows nothing

Check:

- SDA → A4
- SCL → A5
- Correct I2C Address (0x3C)

---

Upload Failed

Check:

- USB cable
- COM Port
- Arduino Board selection

---

Buttons not working

Make sure the buttons are connected correctly using INPUT_PULLUP configuration.

---

Buzzer has no sound

Verify:

- Pin D7
- GND connection
- Passive buzzer polarity

---

🇮🇩 Bahasa Indonesia

Persiapan

Sebelum menggunakan proyek ini, siapkan:

- Arduino Uno R3
- OLED SSD1306 128×64 (I2C)
- 3 Push Button
- Passive Buzzer
- Breadboard
- Kabel Jumper
- Kabel USB
- Arduino IDE 2.x

Library yang dibutuhkan:

- Adafruit GFX Library
- Adafruit SSD1306 Library

Install melalui:

Arduino IDE → Library Manager

---

Skema Pin

Komponen| Pin Arduino
OLED SDA| A4
OLED SCL| A5
Tombol Atas| D2
Tombol Bawah| D3
Tombol Select| D4
Buzzer| D7
VCC OLED| 5V
GND OLED| GND

---

Cara Menggunakan

1. Download repository ini.
2. Buka file ".ino" menggunakan Arduino IDE.
3. Install semua library yang diperlukan.
4. Hubungkan Arduino ke komputer.
5. Pilih:
   - Board: Arduino Uno
   - Port: COM Arduino
6. Tekan Upload.
7. Tunggu proses selesai.
8. Game siap dimainkan.

---

Navigasi Menu

Tombol| Fungsi
D2| Atas / Jump
D3| Bawah
D4| Pilih / Kembali ke Menu

---

Daftar Game

Flappy Bird

Terbang melewati pipa tanpa menyentuh rintangan.

- D2 → Terbang
- D4 → Keluar ke Menu

---

Chrome Dino

Lompat melewati kaktus dan bertahan selama mungkin.

- D2 → Lompat
- D4 → Keluar

Kecepatan permainan akan terus meningkat.

---

Pong Pro

Pantulkan bola menggunakan paddle.

- D2 → Naik
- D3 → Turun
- D4 → Keluar

Semakin lama bertahan, semakin tinggi skor.

---

Reaction Test

Uji kecepatan refleks.

- D2 → Mulai / Menekan saat buzzer berbunyi
- D4 → Keluar

Tekan tombol secepat mungkin setelah buzzer berbunyi.

---

Mengatasi Masalah

OLED tidak menyala

Periksa:

- Kabel SDA
- Kabel SCL
- Alamat I2C (0x3C)

---

Upload gagal

Periksa:

- Kabel USB
- COM Port
- Board Arduino yang dipilih

---

Tombol tidak berfungsi

Pastikan rangkaian menggunakan konfigurasi INPUT_PULLUP.

---

Buzzer tidak berbunyi

Pastikan:

- Terhubung ke pin D7
- GND benar
- Menggunakan passive buzzer

---

License

This project is licensed under the MIT License.

See the LICENSE file for complete license information.

© 2026 Xyraa Kyxzz. All Rights Reserved.

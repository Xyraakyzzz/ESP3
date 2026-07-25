# ESP32 Bluetooth Controlled Robot Car

🇮🇩 Bahasa Indonesia | 🇺🇸 English

---

# 🇮🇩 Bahasa Indonesia

## Tentang

Proyek ini merupakan robot mobil berbasis **ESP32** yang dikendalikan melalui koneksi **Bluetooth Classic (SPP)**. Perintah dikirim dari smartphone melalui aplikasi Bluetooth Terminal atau aplikasi robot controller yang kompatibel.

Kecepatan motor dapat diatur secara real-time menggunakan PWM, sedangkan arah gerak dikontrol melalui perintah karakter yang diterima melalui Bluetooth.

---

## Fitur

- Kontrol melalui Bluetooth Classic
- Gerak maju
- Gerak mundur
- Belok kiri
- Belok kanan
- Berhenti
- Pengaturan kecepatan PWM (0–255)

---

## Komponen

- ESP32 Development Board
- Driver Motor L298N / L293D
- 2 DC Motor
- Robot Chassis
- Battery Pack
- Smartphone Android
- Jumper Wire

---

## Konfigurasi Pin

### Motor Driver

| Pin ESP32 | Fungsi |
|-----------|--------|
| GPIO 22 | ENA (PWM) |
| GPIO 23 | ENB (PWM) |
| GPIO 5 | IN1 |
| GPIO 21 | IN2 |
| GPIO 19 | IN3 |
| GPIO 18 | IN4 |

---

## Nama Bluetooth

```
KYXZZ-PROJECTS
```

---

## Daftar Perintah

### Kontrol Gerakan

| Karakter | Fungsi |
|----------|---------|
| F | Maju |
| B | Mundur |
| L | Belok Kiri |
| R | Belok Kanan |
| S | Berhenti |

### Pengaturan Kecepatan

| Karakter | PWM |
|----------|-----|
| 0 | 100 |
| 1 | 110 |
| 2 | 120 |
| 3 | 130 |
| 4 | 140 |
| 5 | 150 |
| 6 | 180 |
| 7 | 200 |
| 8 | 220 |
| 9 | 240 |
| q | 255 (Maksimum) |

---

## Library

- BluetoothSerial (ESP32)
- Arduino

---

## Board

- ESP32

---

## Bahasa Pemrograman

- Arduino C++

---

# 🇺🇸 English

## About

This project is an **ESP32-based Bluetooth robot car** controlled using **Bluetooth Classic (SPP)**. Commands are sent from a smartphone using a Bluetooth Terminal or any compatible robot controller application.

Motor speed is controlled using PWM, while movement directions are controlled through Bluetooth commands.

---

## Features

- Bluetooth Classic control
- Forward movement
- Backward movement
- Left turn
- Right turn
- Stop
- Adjustable PWM speed (0–255)

---

## Components

- ESP32 Development Board
- L298N / L293D Motor Driver
- 2 DC Motors
- Robot Chassis
- Battery Pack
- Android Smartphone
- Jumper Wires

---

## Pin Configuration

### Motor Driver

| ESP32 Pin | Function |
|------------|----------|
| GPIO 22 | ENA (PWM) |
| GPIO 23 | ENB (PWM) |
| GPIO 5 | IN1 |
| GPIO 21 | IN2 |
| GPIO 19 | IN3 |
| GPIO 18 | IN4 |

---

## Bluetooth Device Name

```
KYXZZ-PROJECTS
```

---

## Command List

### Movement

| Character | Action |
|-----------|--------|
| F | Forward |
| B | Backward |
| L | Turn Left |
| R | Turn Right |
| S | Stop |

### Speed Control

| Character | PWM |
|-----------|-----|
| 0 | 100 |
| 1 | 110 |
| 2 | 120 |
| 3 | 130 |
| 4 | 140 |
| 5 | 150 |
| 6 | 180 |
| 7 | 200 |
| 8 | 220 |
| 9 | 240 |
| q | 255 (Maximum) |

---

## Libraries

- BluetoothSerial (ESP32)
- Arduino

---

## Board

- ESP32

---

## Programming Language

- Arduino C++

---

## License

This project is licensed under the terms described in the **LICENSE** file.

---

**Author:** Xyraa Kyxzz

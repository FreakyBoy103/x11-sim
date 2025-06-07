
# 🕹️ x11-sim ![Alpha](https://img.shields.io/badge/Status-Alpha-red)

**x11-sim** is a lightweight Linux C++ application using the X11 library to render a bouncing ball simulation. The ball’s movement is controlled by two parameters: **elasticity** and **gravity**.


---

## ✨ Features

* Real-time rendering with X11
* A bouncing ball with simple physics
* Configurable **elasticity** and **gravity** parameters
* Minimal and clean C++ codebase
* Designed for Linux systems

---

## 📦 Prerequisites

* Linux system with X11 development libraries (`libx11-dev` or equivalent)
* C++ compiler (e.g., `g++`)
* CMake (optional)

---

## 🛠 How It Works

* Creates an X11 window
* Spawns a ball initially centered
* Updates ball position every frame applying:
  * Gravity (downward force)
  * Velocity affected by elasticity (bouncing strength)
* Ball bounces off window edges, reversing velocity scaled by elasticity


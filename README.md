Tank-Tread Robotic Autonomous Mapper (TtRAM)
=====================================================================


## Introduction
  -This robot uses lidar for vision, and maps its current terrain before selecting a complementary mapping location.
  -The robot has a main brain system which runs python, and then accessory smaller sub-brains which process and relay local info back to the main brain.

## Requirements
### Hardware
  - UDOO x86
  - Arduino Pro Micro (Sub-Brain in head uint)
  - Garmin LIDAR v3 (Provides Vision)
  - Adafruit 10DOF Sensor (Provides data for the Lidar return vector)
  - Hextronic 9g Servo (Currentl providing pitch for the LIDAR)
  - Small DC gearbox motor (Provides Yaw)
  - 2x 130 DC gearbox motor (Provides movement for the Devastator Tank)
  - 3S Lipo Battery 11.1V
  - Devastator Tank Chassis
  - Motor Controller (main chassis)
  - Motor Controller (Pan Robot Head)

### Software
  - Archlinux (with kernel in 4.X branch)
  - Python 3.7.1+ with pyserial
  - Use the requirements file or pipenv to get them automatically

## Installation

### Arduino
  - [INSTALL](docs/Arduino/INSTALL.md)
  - [Opcodes](docs/Arduino/Opcodes.md)

### UDOO
  - [INSTALL](docs/Arduino/INSTALL.md)
  - [Opcodes](docs/MiniD/Opcodes.md)



# Licenses





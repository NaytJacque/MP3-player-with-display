# MP3-Player-Berbasis-Arduino
MP3 player berbasis Arduino dengan display

## Komponen
* 1x Arduino Nano
* 1x Display OLED SSD1306 I2C
* 1x DFPlayer Mini
* 1x TP4056 Charger 3.7v
* 1x Baterai Lipo/Li-Ion 3.7v
* 1x MT3608 Step Up DC
* 1x Resistor 1k Ohm
* 2x Resistor 10k Ohm
* 3x Tactile Switch
* 1x On/Off Switch

### Library-Arduino
* [DFRobotDFplayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini) - by DFRobot
* [U8g2lib](https://github.com/olikraus/u8g2) - by olikraus
* [OneButton](https://github.com/mathertel/OneButton) - by Mathertel


### Installing

Buka Arduino IDE dan ikuti cara berikut:
```
Sketch -> include library -> ManageLibrary -> *Cari library yang ada di atas*
```

### Python Script

Untuk transfer files ke DFPlayer, foldernya harus di beri nama 01,02.. dan file lagu harus di beri nama 001,002,.. 
Script Python ini membantu mentransfer file tanpa harus mengganti namanya.

![Soundpod final build](https://github.com/Neutrino-1/Arduino-Soundpod/blob/master/DFPlayer_Helper/DFplayer%20Helper.png)



//подключение библиотек
#include <EEPROM.h>
#include <iarduino_NeoPixel.h>
#include "GyverButton.h"
//настройки
#define COUNT_DIOD 20
#define PIN_BUT 3
#define PIN_LED 13
//иницилизаторы классов
GButton butt1(PIN_BUT);
iarduino_NeoPixel led(PIN_LED, COUNT_DIOD);
//иницилизация переменных
byte Color[3], bright = 127;
int  mode;
String input_string;


void setup() {
  for(int i = 0; i < 3; i++){
    Color[i] = EEPROM.read(i);
  }
  delay(300);
  led.begin();
  led.setColor(NeoPixelAll, 0, 0, 0, bright);
  led.write();
  butt1.setDebounce(50);
  Serial.begin(9600);
}
void loop() {
  butt1.tick(); //выжная функция для работы кнопки
  //обработка единичного нажатия кнопки
  if (butt1.isSingle()) {
    if (mode > 3) {
      mode = 0;
    }
    else {
      mode++;
    }
    switch (mode) {
      case 1:
        led.setColor(NeoPixelAll, 255, 0, 0, bright);
        break;
      case 2:
        led.setColor(NeoPixelAll, 0, 255, 0, bright);
        break;
      case 3:
        led.setColor(NeoPixelAll, 0, 0, 255, bright);
        break;
      case 4:
        led.setColor(NeoPixelAll, 255, 255, 255, bright);
        break;
      default:
        led.setColor(NeoPixelAll, 0, 0, 0, bright);
        break;
    }
    led.write();
  }
  //обработка двойного нажатия кнопки
  if (butt1.isDouble()) {
    if (mode < 1) {
      mode = 0;
    }
    else {
      mode--;
    }
    switch (mode) {
      case 1:
        led.setColor(NeoPixelAll, 255, 0, 0, bright);
        break;
      case 2:
        led.setColor(NeoPixelAll, 0, 255, 0, bright);
        break;
      case 3:
        led.setColor(NeoPixelAll, 0, 0, 255, bright);
        break;
      case 4:
        led.setColor(NeoPixelAll, 255, 255, 255, bright);
        break;
      default:
        led.setColor(NeoPixelAll, 0, 0, 0, bright);
        break;
    }
    led.write();
  }
  //обработка тройного нажатия кнопки
  if (butt1.isTriple()) {
    led.setColor(NeoPixelAll, Color[0], Color[2], Color[1], bright);
    led.write();
  }
}

//обработка serial с помощью встроенной функции
void serialEvent() {
  char c = Serial.read();
  if (c == '\n') {
    Command();
    input_string = "";
    led.setColor(NeoPixelAll, Color[0], Color[2], Color[1], bright);
    led.write();
  }
  else
  {
    input_string += c;
  }
}

void Command() // функция для работы Serial
{
  if (input_string.startsWith("R") == true) // обработка красного цвета
  {
    input_string.replace("R", "");
    Color[0] = input_string.toInt();      // преобразовываем строку в число
    EEPROM.write(0, Color[0]);            // сохранение цвета в EEPROM
  }
  else if (input_string.startsWith("B") == true) // обработка синего цвета
  {
    input_string.replace("B", "");
    Color[1] = input_string.toInt();      // преобразовываем строку в число
    EEPROM.write(1, Color[1]);            // сохранение цвета в EEPROM
  }
  else if (input_string.equals("White") == true) // обработка красного цвета
  {
    for (int i = 0; i < 3; i++) {
      Color[i] = 255;
    }
  }
  else if (input_string.startsWith("G") == true) // обработка зеленого цвета
  {
    input_string.replace("G", "");        // заменяем строку
    Color[2] = input_string.toInt();      // преобразовываем строку в число
    EEPROM.write(2, Color[2]);            // сохранение цвета в EEPROM
  }
  else if (input_string.startsWith("br") == true) // обработка яркости цвета
  {
    input_string.replace("br", "");     // заменяем строку
    bright = input_string.toInt();      // преобразовываем строку в число
  }
}

#include <U8g2lib.h>

#define FONT_USED      u8x8_font_pxplusibmcgathin_f

U8X8_SSD1306_128X64_NONAME_HW_I2C u8g2(U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  u8g2.setPowerSave(0);
  u8g2.setFont(FONT_USED);
}

void loop() {
  for (uint8_t i = 0; i < 5; i++) {
    u8g2.setCursor(0, i);
    u8g2.print("Hello world ");
    u8g2.print(i);
    delay(1000);
  }
}

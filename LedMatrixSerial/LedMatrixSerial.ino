#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 36          // NeoPixels PER STRAND, total number is 8X this!
#define COLOR_ORDER NEO_RGB  // NeoPixel color format (see Adafruit_NeoPixel)

int8_t pins[8] = { 15, 14, 13, 12, 11, 10, 9, 8 };  // GPxx indices!
uint8_t brightness = 25;

const size_t packetSize = 864;
uint8_t pixelData[packetSize];

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, 15, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, 14, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS, 13, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUM_LEDS, 12, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUM_LEDS, 11, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(NUM_LEDS, 10, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(NUM_LEDS, 9, COLOR_ORDER + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(NUM_LEDS, 8, COLOR_ORDER + NEO_KHZ800);

void setup() {
  Serial.begin(2000000);

  strip1.begin();
  strip1.setBrightness(brightness);
  strip1.show();

  strip2.begin();
  strip2.setBrightness(brightness);
  strip2.show();

  strip3.begin();
  strip3.setBrightness(brightness);
  strip3.show();

  strip4.begin();
  strip4.setBrightness(brightness);
  strip4.show();

  strip5.begin();
  strip5.setBrightness(brightness);
  strip5.show();

  strip6.begin();
  strip6.setBrightness(brightness);
  strip6.show();

  strip7.begin();
  strip7.setBrightness(brightness);
  strip7.show();

  strip8.begin();
  strip8.setBrightness(brightness);
  strip8.show();
}

void loop() {

  if (Serial.available() > 0) {
    size_t readSize = Serial.readBytes(pixelData, packetSize);

    if (readSize == 8) {
      
    }

    if (readSize == packetSize) {
      uint16_t idx = 0;

      for (uint16_t i = 0; i < 864; i = i + 3) {
/*      Serial.print("PixelData: ");
        Serial.print(" ");
        Serial.print(pixelData[i]);
        Serial.print(" ");
        Serial.print(pixelData[i + 1]);
        Serial.print(" ");
        Serial.print(pixelData[i + 2]);
        Serial.print(" ");
        Serial.println(idx); */
        setLED(idx, strip1.Color(pixelData[i], pixelData[i + 1], pixelData[i + 2]));
        idx = idx + 1;
      }
      showAll();
    }
  }
}

void setLED(uint16_t n, uint32_t c) {
  // LED index = n
  // LED color = c

  uint16_t idx = n / 36;

  switch (idx) {
    case 0:
      strip1.setPixelColor(n, c);
      break;
    case 1:
      strip2.setPixelColor(n - 36, c);
      break;
    case 2:
      strip3.setPixelColor(n - 72, c);
      break;
    case 3:
      strip4.setPixelColor(n - 108, c);
      break;
    case 4:
      strip5.setPixelColor(n - 144, c);
      break;
    case 5:
      strip6.setPixelColor(n - 180, c);
      break;
    case 6:
      strip7.setPixelColor(n - 216, c);
      break;
    case 7:
      strip8.setPixelColor(n - 252, c);
      break;
  }
}

void showAll() {
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  strip6.show();
  strip7.show();
  strip8.show();
}

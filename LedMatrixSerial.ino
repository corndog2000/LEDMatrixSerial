#include <Adafruit_NeoPXL8.h>

#define NUM_LEDS 36          // NeoPixels PER STRAND, total number is 8X this!
#define COLOR_ORDER NEO_GRB  // NeoPixel color format (see Adafruit_NeoPixel)

int8_t pins[8] = { 15, 14, 13, 12, 11, 10, 9, 8 };  // GPxx indices!

const size_t packetSize = 864;
uint8_t pixelData[packetSize];

Adafruit_NeoPXL8 leds(NUM_LEDS, pins, COLOR_ORDER);

void setup() {
  Serial.begin(115200);

  leds.begin();

  leds.setBrightness(25); // Tone it down, NeoPixels are BRIGHT!
}

void loop() {

  Serial.println("Hello World");
  delay(1000);

  if (Serial.available() > 0) {
    size_t readSize = Serial.readBytes(pixelData, packetSize);

    if (readSize == packetSize) {
      memcpy(leds.getPixels(), pixelData, readSize);
      leds.show();
    }
  }
}

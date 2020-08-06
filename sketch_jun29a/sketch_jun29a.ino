#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 13
#define CLOCK_PIN 12


CRGB ring[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  LEDS.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(ring, NUM_LEDS);
  LEDS.setBrightness(30); // LEDS.setBrightness(20);
  ring[1] = CHSV(128, 128, 128);
}

void fadeAll() {
  for (int i = 0; i < NUM_LEDS; i++) {
    ring[i].nscale8(225);
  }
}

void sparkle(int base) {
  ring[random(0, NUM_LEDS)] = CHSV(base % 256, 150, 200);
//  ring[random(0, NUM_LEDS)] = CHSV((base+10) % 256, 150, 255);
//  ring[random(0, NUM_LEDS)] = CHSV((base-10) % 256, 150, 255);
  fadeAll();
  FastLED.show();
  delay(5);
}

void monoSpin(uint8_t hue) {
  for (int i = 0; i < NUM_LEDS; i++) {
    ring[i] = CHSV(hue, 150, 255);
    fadeAll();
    FastLED.show();
    delay(5);
  }
}

void spin() {
  static uint8_t hue_1 = 0;
  static uint8_t hue_2 = 85;
  static uint8_t hue_3 = 170;
  for (int i = 0; i < NUM_LEDS; i++) {
    ring[i] = CHSV(hue_1++, 150, 255);
//    ring[(i+NUM_LEDS/3) % (NUM_LEDS)] = CHSV(hue_2++, 150, 255);
//    ring[(i+2*NUM_LEDS/3) % (NUM_LEDS)] = CHSV(hue_3++, 150, 255);
    fadeAll();
    FastLED.show();
    delay(10);
  }
}

void breath(uint8_t hue) {
  for (int j = 0; j < 120; j = j+4) {
    for (int i = 0; i < NUM_LEDS; i++) {
      ring[i] = CHSV(hue, 150, 128 + 64 + abs(j-64));
    }  
    FastLED.show();
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

//  for (int i = 0; i < 1000; i++) {
//    sparkle(i);
//  }
//
  for (int i = 0; i < 10; i++) {
    spin();
  }

//  sparkle(160);
//  breath(160);
}

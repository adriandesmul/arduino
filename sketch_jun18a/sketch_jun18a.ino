#include <FastLED.h>
#define NUM_LEDS 2
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 0>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
      for (int i = 0; i < 256; i++) {
        leds[0] = CHSV(i,216,100+random(0, 120)); FastLED.show(); 
        leds[1] = CHSV(i+(256/2)%256,216,100+random(0, 120)); FastLED.show(); delay(25);
      }
  
  
  
//  leds[0] = OvercastSky; FastLED.show(); delay(300);
//  leds[0] = ClearBlueSky; FastLED.show(); delay(300);
//  leds[0] = HighNoonSun; FastLED.show(); delay(300);
//  leds[0] = Halogen; FastLED.show(); delay(300);
//  leds[0] = Candle; FastLED.show(); delay(300);
}

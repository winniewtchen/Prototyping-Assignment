#include <FastLED.h>
#include <FastLED.h>
#include <FastLED.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define DATA_PIN    6
#define NUM_LEDS    10
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

const int trigPin = 9;
const int echoPin = 10;

int hue[9];

CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(DATA_PIN, OUTPUT);
  // put your setup code here, to run once:
   FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void loop()

{ long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance < 20)
{ for( int i = 0; i < NUM_LEDS; i ++) {
        hue[i] = random8();
        leds[i] = CHSV( hue[i], 255, 255);
        FastLED.show();
      }
}
else {
{ for( int i = 0; i < NUM_LEDS; i ++) {
        leds[i] = CHSV( hue[i], 255, 255);
        FastLED.show();
      }
}
Serial.print(distance);
Serial.println(" cm");
delay(500);
}
}

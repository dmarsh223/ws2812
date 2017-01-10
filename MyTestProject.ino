#include <FastLED.h>
#define NUM_LEDS 150
#define DATA_PIN 5
#define CHIPSET WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS         50
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];


void setup()
{

delay(3000); // 3 second delay for recovery

FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

FastLED.setBrightness(BRIGHTNESS);

}

uint8_t gHue = 0;

void loop()
{
FastLED.show();
FastLED.delay(1000 / FRAMES_PER_SECOND);


//this sets the LED to a rainbow colors
//rainbow();

//this sets the LED string to a dark blue color
blue(); 

//this picks a random color and has it trace along the length of the LED strip
//tracer();

}

void rainbow() {
	fill_rainbow(leds, NUM_LEDS, gHue, 7);
}

void blue() {

	for (int dot = 0; dot < NUM_LEDS; dot++) {
		leds[dot] = CRGB(0, 12, 255);
		//  leds[dot]= CRGB (1,86,15); 
	}
}

void tracer() {

	int randomNum1 = random8();
	int randomNum2 = random8();
	int randomNum3 = random8();

	for (int dot = 0; dot < NUM_LEDS; dot++) {


		leds[dot] = CRGB(randomNum1, randomNum2, randomNum3);

		FastLED.show();

		leds[dot] = CRGB::Black; //clear this led for the next time around the loop
		delay(30);

	}
}


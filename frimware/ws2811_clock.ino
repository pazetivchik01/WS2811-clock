#include "button.h"
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <FastLED.h>

#define NUM_LEDS 28 // leds count
#define DATA_PIN 9 // the pin to which the LED strip is connected
#define BRIGHTNES 75 // max 255

const int BTN_PIN = 2; // the pin to which the button is connected
unsigned long prev = 0;

ThreeWire myWire(7,6,8);
RtcDS1302<ThreeWire> Rtc(myWire);


CRGB leds[NUM_LEDS];

int clock_mode = 0;

Button btn1(BTN_PIN);

void setup () {
  Rtc.Begin();
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNES);
  delay(2000);
 }
 
   byte counter;
   
void loop() {
  
  Rtc.GetDateTime();
  RtcDateTime now = Rtc.GetDateTime();
  
  int HOUR =  now.Hour();
  int MINUTE = now.Minute();

  if(btn1.click()){
    clock_mode++;
    if(clock_mode > 14)
    clock_mode = 1;
  }
  effects(clock_mode, HOUR, MINUTE);
}

void effects(int option, int HOUR, int MINUTE){
  switch (option){
    
    case 1:{
        show_digit(HOUR/10, 0, 255, 0, 0);
        show_digit(HOUR%10, 1,255, 0, 0);
        
        show_digit(MINUTE/10, 2, 255, 0, 0);
        show_digit(MINUTE%10, 3, 255, 0, 0);
        FastLED.show();
    }
    break;

    case 2:{
        show_digit(HOUR/10, 0, 170, 85, 0);
        show_digit(HOUR%10, 1,170, 85, 0);
        
        show_digit(MINUTE/10, 2,170, 85, 0);
        show_digit(MINUTE%10, 3,170, 85, 0);
        FastLED.show();
    }
    break;

    case 3:{
        show_digit(HOUR/10, 0, 128, 128, 0);
        show_digit(HOUR%10, 1,128, 128, 0);
        
        show_digit(MINUTE/10, 2,128, 128, 0);
        show_digit(MINUTE%10, 3,128, 128, 0);
        FastLED.show();
    }
    break;

    case 4:{
        show_digit(HOUR/10, 0, 85, 170, 0);
        show_digit(HOUR%10, 1,85, 170, 0);
        
        show_digit(MINUTE/10, 2,85, 170, 0);
        show_digit(MINUTE%10, 3,85, 170, 0);
        FastLED.show();
    }
    break;
    
    case 5:{
        show_digit(HOUR/10, 0, 0, 255, 0);
        show_digit(HOUR%10, 1,0, 255, 0);
        
        show_digit(MINUTE/10, 2,0, 255, 0);
        show_digit(MINUTE%10, 3,0, 255, 0);
        FastLED.show();
    }
    break;

    case 6:{
        show_digit(HOUR/10, 0, 0, 170, 85);
        show_digit(HOUR%10, 1,0, 170, 85);
        
        show_digit(MINUTE/10, 2,0, 170, 85);
        show_digit(MINUTE%10, 3,0, 170, 85);
        FastLED.show();
    }
    break;

    case 7:{
        show_digit(HOUR/10, 0, 0, 128, 128);
        show_digit(HOUR%10, 1,0, 128, 128);
        
        show_digit(MINUTE/10, 2,0, 128, 128);
        show_digit(MINUTE%10, 3,0, 128, 128);
        FastLED.show();
    }
    break;

    case 8:{
        show_digit(HOUR/10, 0, 0, 85, 170);
        show_digit(HOUR%10, 1,0, 85, 170);
        
        show_digit(MINUTE/10, 2,0, 85, 170);
        show_digit(MINUTE%10, 3,0, 85, 170);
        FastLED.show();
    }
    break;
    
    case 9:{
        show_digit(HOUR/10, 0,0, 0, 255);
        show_digit(HOUR%10, 1,0, 0, 255);
        
        show_digit(MINUTE/10, 2,0, 0, 255);
        show_digit(MINUTE%10, 3,0, 0, 255);
        FastLED.show();
    }
    break;

    case 10:{
        show_digit(HOUR/10, 0,85, 0, 170);
        show_digit(HOUR%10, 1,85, 0, 170);
        
        show_digit(MINUTE/10, 2,85, 0, 170);
        show_digit(MINUTE%10, 3,85, 0, 170);
        FastLED.show();
    }
    break;
    case 11:{
        show_digit(HOUR/10, 0,128, 0, 128);
        show_digit(HOUR%10, 1,128, 0, 128);
        
        show_digit(MINUTE/10, 2,128, 0, 128);
        show_digit(MINUTE%10, 3,128, 0, 128);
        FastLED.show();
    }
    break;
    case 12:{
        show_digit(HOUR/10, 0,170, 0, 85);
        show_digit(HOUR%10, 1,170, 0, 85);
        
        show_digit(MINUTE/10, 2,170, 0, 85);
        show_digit(MINUTE%10, 3,170, 0, 85);
        FastLED.show();
    }
    break;
    
  case 13:{
    unsigned long currentMillis = millis();
    if (currentMillis - prev >= 20){
      prev = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
  
        // Получаем цвет в формате HSV
        CHSV color = CHSV(counter + i * 2, 255, 255);
    
        // Преобразуем HSV в RGB
        CRGB rgbColor = color;

        show_digit(HOUR/10, 0, rgbColor.r, rgbColor.g, rgbColor.b);

        show_digit(HOUR%10, 1,rgbColor.r, rgbColor.g, rgbColor.b);

        show_digit(MINUTE/10, 2, rgbColor.r, rgbColor.g, rgbColor.b);

        show_digit(MINUTE%10, 3, rgbColor.r, rgbColor.g, rgbColor.b);

      }
    counter++; 
    FastLED.show();
    }
    
    
  }
    break;
    case 14:{
      int _1 = 0, _2 = 0, _3 = 0, _4 = 0;
      unsigned long currentMillis = millis();
    if (currentMillis - prev >= 20){
      prev = currentMillis;
      for (int i = 0; i < NUM_LEDS * 2; i++) {
        CHSV color = CHSV(counter + ((i / 2) * 255 / NUM_LEDS), 255, 255); 
        CRGB rgbColor = color;
        
        if(_1 == 0){
          show_digit(MINUTE%10, 3, rgbColor.r, rgbColor.g, rgbColor.b);
          _1 = 1;
          continue;
          }
        if(_2 == 0){
          show_digit(MINUTE/10, 2, rgbColor.r, rgbColor.g, rgbColor.b);
          _2 = 1;
          continue;
        }
        if(_3 == 0){
          show_digit(HOUR%10, 1,rgbColor.r, rgbColor.g, rgbColor.b);
          _3 = 1;
          continue;
        }
        if(_4 == 0){
          show_digit(HOUR/10, 0, rgbColor.r, rgbColor.g, rgbColor.b);
          _4 = 1;
          continue;
        }

        _1 = 0; _2 = 0; _3 = 0; _4 = 0;
      }
  counter++;
  FastLED.show();
  }
  }
  break;
  }
}

void show_digit(int digit, int pl, short red, short green, short blue){ 
    if(pl == 0)
  pl = 21;
    if(pl == 1)
  pl = 14;
    if(pl == 2)
  pl = 7;
    if(pl == 3)
  pl = 0;
  
  switch(digit){
    
        case 0:
         leds[NUM_LEDS - 1 - pl] = CRGB(red, green, blue);
         leds[NUM_LEDS - 2 - pl] = CRGB(red, green, blue);
         leds[NUM_LEDS - 3 - pl] = CRGB(red, green, blue);
         leds[NUM_LEDS - 5 - pl] = CRGB(red, green, blue);
         leds[NUM_LEDS - 6 - pl] = CRGB(red, green, blue);
         leds[NUM_LEDS - 7 - pl] = CRGB(red,  green, blue);
         leds[NUM_LEDS - 4 - pl] = CRGB::Black;
    break;
        case 1:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 2 - pl] = CRGB::Black;
           leds[NUM_LEDS - 3 - pl] = CRGB::Black;
           leds[NUM_LEDS - 4 - pl] = CRGB::Black;
           leds[NUM_LEDS - 6 - pl] = CRGB::Black;
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
        case 2:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 2 - pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4 - pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 7- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3 - pl] = CRGB::Black;
           leds[NUM_LEDS - 5 - pl] = CRGB::Black;
           
          
    break;
        case 3:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3 - pl] = CRGB::Black;
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
        case 4:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 3- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 2 - pl] = CRGB::Black;
           leds[NUM_LEDS - 6 - pl] = CRGB::Black;
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
        case 5:
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 1 - pl] = CRGB::Black;
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
        case 6:
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 7- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 1 - pl] = CRGB::Black;
    break;
        case 7:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3 - pl] = CRGB::Black;
           leds[NUM_LEDS - 4 - pl] = CRGB::Black;
           leds[NUM_LEDS - 6 - pl] = CRGB::Black;
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
        case 8:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 7- pl] = CRGB(red, green, blue);
    break;
        case 9:
           leds[NUM_LEDS - 1- pl] = CRGB(red,  green, blue);
           leds[NUM_LEDS - 2- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 3- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 4- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 5- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 6- pl] = CRGB(red, green, blue);
           leds[NUM_LEDS - 7 - pl] = CRGB::Black;
    break;
  }
}

#include <Wire.h>
#include <U8g2lib.h>


#define FONT_USED      u8x8_font_pxplusibmcgathin_f



U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R1,/* reset=*/ U8X8_PIN_NONE, /* clock=*/ D4, /* data=*/ D3);

// This is the battery bitmap


// This is the area inside the battery bitmap, in pixels
#define CHARGE_AREA_START_X     53
#define CHARGE_AREA_START_Y     2
#define CHARGE_AREA_WIDTH       3
#define CHARGE_AREA_HEIGHT      5

// This is the battery fill mode
// BATTERY_MODE_SOLID = 1 means the battery bitmap will be filled with
// a solid rectangle according to the battery charge.
// BATTERY_MODE_SOLID = 0 means the battery will be filled with a
// rectangle subdivided in 3. If the battery level is 66% or more, it will
// draw 3 rectangles. If it's 33% or more, it will draw 2 rectangles. It will
// draw 1 rectagle if the battery is less than 33%.

#define BATTERY_MODE_SOLID 0

// This is the main function, and the one you will want to transplant to your
// code. Pass the battery charge percent and it will draw the battery with
// the corresponding charge level.
void showBatteryLevel(uint8_t percent, uint8_t speed)
{
    uint8_t width;

    if (percent > 100)
        percent = 100;

    u8g2.clearBuffer();
    u8g2.drawHLine(52,1,11);
    u8g2.drawHLine(52,7,11);
    u8g2.drawHLine(52,2,1);
    u8g2.drawHLine(52,3,1);
    u8g2.drawHLine(52,4,1);
    u8g2.drawHLine(52,5,1);
    u8g2.drawHLine(52,6,1);

    u8g2.drawHLine(62,2,10);
    u8g2.drawHLine(62,3,10);
    u8g2.drawHLine(62,4,10);
    u8g2.drawHLine(62,5,10);
    u8g2.drawHLine(62,6,10);

    u8g2.drawBox(62,2,1,5);
    if (BATTERY_MODE_SOLID)
    {
        width = (percent * CHARGE_AREA_WIDTH) / 100;
        u8g2.drawBox(CHARGE_AREA_START_X, CHARGE_AREA_START_Y, width, CHARGE_AREA_HEIGHT);
    } else {
        uint8_t bars;
        
        
         if (percent >= 66)
        {
            // Show two bars
            bars = 3;
        }else if (percent >= 33)
        {
            // Show two bars
            bars = 2;
        } else if (percent > 0)
        {
            // Show one bar
            bars = 1;
        } else {
            // Show nothing
            bars = 0;
        }

        uint8_t offset = CHARGE_AREA_START_X;
        for (uint8_t i = 0; i < bars; i++)
        {
            u8g2.drawBox(offset, CHARGE_AREA_START_Y, 3, CHARGE_AREA_HEIGHT);
            offset += 3;
        }
    }
//speedometer code

      u8g2.drawBox(31,70,4,4);


    if(speed > 0 && speed <=5){
      //0 position
      u8g2.drawLine(29,72,7,72);
      u8g2.drawLine(29,71,7,71);
    }

    if(speed > 5 && speed <= 15){
      //1st position
      u8g2.drawLine(29,72,8,66);
      u8g2.drawLine(29,71,8,65);
    }
    
    //2nd position
    if(speed > 15 && speed <= 25){
      u8g2.drawLine(29,71,13,61);
      u8g2.drawLine(29,70,13,60);
    }
    
    //3rd position
    if(speed>25 && speed <= 35){
      u8g2.drawLine(29,69,17,55);
      u8g2.drawLine(29,68,17,54);
    }

    //4th position
    if(speed>35 && speed < 45){
      u8g2.drawLine(30,68,25,50);
      u8g2.drawLine(31,68,25,49);
    }
    //middle position
    if(speed >= 45 && speed <= 55){ 
      u8g2.drawLine(32,68,32,45);
      u8g2.drawLine(33,68,33,45);
    }

    //last 
    if(speed >= 95 && speed <=100){
      u8g2.drawLine(35,72,62,72);
      u8g2.drawLine(35,71,62,71);
    }

    u8g2.sendBuffer();
}

void ShowBatteryPercent(uint8_t percent){
  char cstr[16];
  itoa(percent, cstr, 10);
  u8g2.setFont(u8g2_font_torussansbold8_8r);
 do {
    u8g2.setFont(u8g2_font_6x10_mr);
    u8g2.drawStr(32,8, cstr);
    u8g2.drawStr(45,8, "%");
 }while ( u8g2.nextPage() );
  delay(1000);
}

//not used right now...
void Speedometer(uint8_t speed){
    u8g2.clearBuffer();

    u8g2.drawBox(31,70,4,4);


    if(speed > 0 && speed <=5){
      //0 position
      u8g2.drawLine(29,72,7,72);
      u8g2.drawLine(29,71,7,71);
    }

    if(speed > 5 && speed <= 15){
      //1st position
      u8g2.drawLine(29,72,8,66);
      u8g2.drawLine(29,71,8,65);
    }
    
    //2nd position
    if(speed > 15 && speed <= 25){
      u8g2.drawLine(29,71,13,61);
      u8g2.drawLine(29,70,13,60);
    }
    
    //3rd position
    if(speed>25 && speed <= 35){
      u8g2.drawLine(29,69,17,55);
      u8g2.drawLine(29,68,17,54);
    }

    //4th position
    if(speed>35 && speed < 45){
      u8g2.drawLine(30,68,25,50);
      u8g2.drawLine(31,68,25,49);
    }
    //middle position
    if(speed >= 45 && speed <= 55){ 
      u8g2.drawLine(32,68,32,45);
      u8g2.drawLine(33,68,33,45);
    }

    //last 
    if(speed >= 95 && speed <=100){
      u8g2.drawLine(35,72,62,72);
      u8g2.drawLine(35,71,62,71);
    }
        u8g2.sendBuffer();

}

void setup()
{
    // Initialize the display object
    u8g2.begin();
}

// A variable to test our code.
uint8_t percent = 100;
// A variable to test the speedometer
uint8_t speed = 0;

void loop()
{
    // Some test code to scan all the battery levels
    showBatteryLevel(percent,speed);
    ShowBatteryPercent(percent);

    if (percent)
        percent--;
    else{
        percent = 100;
    }
    
    if (speed==101)
        speed = 0;
    else{
        speed++;
    }
    delay(100);
}



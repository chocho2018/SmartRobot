#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_VL53L0X.h"
#include "U8glib.h"
#include "font.h"
#include <Servo.h>

DFRobotVL53L0X sensor;
Servo myservo;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

bool checkDistance(void){
  uint8_t i = 5;
  if(sensor.getDistance() <= 60 && sensor.getDistance() >= 20.00 && sensor.getDistance() != 5.00){
    while(i--){
      Serial.println(i);
      if(sensor.getDistance() <= 60 && sensor.getDistance() >= 20.00 && sensor.getDistance() != 5.00){
      }else{
        break;
      }
      delay(100);
    }
  }
  
  return((i==0)?true:false);
}

void caozuo()
{
  Serial.println(sensor.getDistance());
  if (checkDistance())
  {
    delay(2000);
    u8g.firstPage();
    do {
      u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits9);
    } while (u8g.nextPage());
    delay(500);
    myservo.write(30);
    delay(200);
    myservo.write(130);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensor.begin(0x50);
  sensor.setMode(Continuous, High);
  sensor.start();
  myservo.attach(11);
}

void loop()
{
  unsigned char i;
  myservo.write(130);
  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  for (i = 8; i > 0; i--)
  {
    delay(100);
    caozuo();
  }

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits1);
  } while (u8g.nextPage());
  delay(100);
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  delay(100);
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits2);
  } while (u8g.nextPage());
  delay(100);
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  for (i = 5; i > 0; i--)
  {
    delay(100);
    caozuo();
  }

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits3);
  } while (u8g.nextPage());
  delay(50);//bishuangyan 0.05s

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  delay(50);//xiaolian 0.05s
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits3);
  } while (u8g.nextPage());
  delay(50);//bishuangyan 0.05s

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  delay(50);//xioalian 0.05s
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits7);
  } while (u8g.nextPage());
  delay(50);//zuoxiaoyiyan 0.05s

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits4);
  } while (u8g.nextPage());
  for (i = 3; i > 0; i--)
  {
    delay(100);
    caozuo();
  }

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits7);
  } while (u8g.nextPage());
  delay(50);//zuoxiaoyiyan 0.05s

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  delay(50);//xiaolian 0.05s
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits8);
  } while (u8g.nextPage());
  delay(50);//youxiaoyiyan 0.05s

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits5);
  } while (u8g.nextPage());
  delay(100);//youdayiyan 0.1s
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits8);
  } while (u8g.nextPage());
  delay(100);//youxiaoyiyan 1s
  caozuo();

  u8g.firstPage();
  do {
    u8g.drawXBMP( 0, 0, 128, 64, u8g_logo_bits0);
  } while (u8g.nextPage());
  delay(500);
  caozuo();

  u8g.firstPage();
  do {
  } while (u8g.nextPage());
  delay(200);
  caozuo();

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr( 23, 25, "Put a coin!");
    u8g.drawStr( 7, 55, "Get a surprise!");
  } while ( u8g.nextPage() );
  delay(500);
  caozuo();
}

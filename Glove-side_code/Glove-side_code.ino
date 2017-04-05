#include <Wire.h>

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

byte buffer[24];

void loop() 
{
  Wire.beginTransmission(0x19);
  Wire.write(0x28);
  Wire.endTransmission();
  Wire.requestFrom(0x19, 6);
  for(int a = 0; a < 6; a++)
  {
    buffer[a] = Wire.read();
  }
  Wire.beginTransmission(0x1E);
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.requestFrom(0x1E, 6);
  for(int a = 6; a < 12; a++)
  {
    buffer[a] = Wire.read();
  }
  Wire.beginTransmission(0x1C);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.requestFrom(0x1C, 6);
  for(int a = 12; a < 18; a++)
  {
    buffer[a] = Wire.read();
  }
  Wire.beginTransmission(0x1D);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.requestFrom(0x1D, 6);
  for(int a = 18; a < 24; a++)
  {
    buffer[a] = Wire.read();
  }
  for(int a = 0; a < 24; a++)
  {
    Serial.println(buffer[a]);
  }
  delay(1000);
}



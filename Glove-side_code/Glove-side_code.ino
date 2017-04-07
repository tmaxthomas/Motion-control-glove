#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_MMA8451.h>
#include <Serial_addons.h>

//Declare sensors as globals 
//Don't worry-the numbers aren't random. There's a bad reason for each of them.
Adafruit_LSM303_Accel_Unified index_accel;
Adafruit_LSM303_Mag_Unified mag_meter;
Adafruit_MMA8451 thumb_accel, middle_accel;

void setup() 
{
  //Set up I2C/Serial
  Serial.begin(9600);

  Serial.println("Serial test");

  //Initialize & do error-checking
  index_accel = new Adafruit_LSM303_Accel_Unified(42);
  mag_meter = new Adafruit_LSM303+Mag_Unified(8);
  thumb_accel = new Adafruit_MMA8451(26);
  middle_accel = new Adafruit_MMA8451(101);
  
  if(!index_accel.begin()){
    //For testing, delete once everything works
    Serial.println("ERROR: LMS303 accelerometer not detected. Check wiring.");
  }

  if(!mag_meter.begin()) {
    //For testing, delete once eveything works
    Serial.println("ERROR: LMS303 magnetometer not detected. Check wiring.");
  }

  if(!middle_accel.begin()){
    //For testing, delete once everything works
    Serial.println("ERROR: Middle finger MMA8451 accelerometer not detected. Check wiring.");
  }
  //Set the address for the thumb accelerometer
  if(!thumb_accel.begin(0x1C)){
    //For testing, delete once everything works
    Serial.println("ERROR: Thumb MMA8451 accelerometer not detected. Check wiring.");
  }
}

void loop() 
{
  //Used for grabbing sensor values
  sensors_event_t event;
  thumb_accel.getEvent(&event);
  
  //Write out thumb_accel values
  Serial.print("Thumb accelerometer X: ");
  Serial.print(event.acceleration.x);
  Serial.print("   Y:");
  Serial.print(event.acceleration.y);
  Serial.print("   Z:");
  Serial.println(event.acceleration.z);
  
  index_accel.getEvent(&event);
  
  //Write out index_accel values
  Serial.print("\nIndex accelerometer X: ");
  Serial.print(event.acceleration.x);
  Serial.print("   Y:");
  Serial.print(event.acceleration.y);
  Serial.print("   Z:");
  Serial.println(event.acceleration.z);
  
  middle_accel.getEvent(&event);
  
  //Write out middle_accel values
  Serial.print("\nMiddle finger accelerometer X: ");
  Serial.print(event.acceleration.x);
  Serial.print("   Y:");
  Serial.print(event.acceleration.y);
  Serial.print("   Z:");
  Serial.println(event.acceleration.z);

  mag_meter.getEvent(&event);

  //Write out magnetometer values
  Serial.print("\nMagnetometer X: ");
  Serial.print(event.magnetic.x);
  Serial.print("   Y:");
  Serial.print(event.magnetic.y);
  Serial.print("   Z:");
  Serial.println(event.magnetic.z);
  
  
  
  //DEPRECATED
  /*
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
  
  
  //Thumb accelerometer
  Wire.requestFrom(0x1C, 6);
  for(int a = 12; a < 18; a++)
  {
    buffer[a] = Wire.read();
  }

  //Middle finger accelerometer
  Wire.requestFrom(0x1D, 6);
  for(int a = 18; a < 24; a++)
  {
    buffer[a] = Wire.read();
  }
  for(int a = 0; a < 24; a++)
  {
    Serial.println(buffer[a]);
  }
  */
  
  delay(1000);
}



/*
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_MMA8451.h>
#include <Serial_addons.h>
*/
/*
//Declare sensors as globals 
//Don't worry-the numbers aren't random. There's a bad reason for each of them.
Adafruit_LSM303_Accel_Unified index_accel(8451);
Adafruit_LSM303_Mag_Unified mag_meter(1493);
Adafruit_MMA8451 thumb_accel(1076);
Adafruit_MMA8451 middle_accel(2791);
*/
void setup() 
{
  //Set up I2C/Serial
  Serial.begin(9600);

  Serial.println("Serial test");

  //Initialize & do error-checking

  /*
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
  */
}

void loop() 
{
  /*
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
  
  delay(1000);
  */
}



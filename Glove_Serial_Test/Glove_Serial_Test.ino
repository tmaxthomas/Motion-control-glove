void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long a = millis();
  if(a % 500 == 0){
    Serial.write(a);
  }
}

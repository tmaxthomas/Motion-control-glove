float tick = 1;

void setup() {
  Serial.begin(19200, SERIAL_8N1);
  delay(5000);
}

void loop() {
  Serial.write((byte*)&tick, 4);
  tick++;
}

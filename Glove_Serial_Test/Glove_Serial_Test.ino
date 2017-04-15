void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte ack = 1;
  byte* buf;
  long msg = 42;
  void* ptr = (void*)&msg;
  buf = (byte*)ptr;
  Serial.write(ack);
  Serial.write(buf, 4);
  delay(5000);
}

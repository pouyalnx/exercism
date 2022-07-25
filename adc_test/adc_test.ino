void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc_val=analogRead(0);
  Serial.println(adc_val);
  delay(100);
}

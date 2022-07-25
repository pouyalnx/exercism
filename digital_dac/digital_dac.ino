void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=analogRead(A0);
  analogWrite(11, val);
}

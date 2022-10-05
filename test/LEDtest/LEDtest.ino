int LED1 = 13;
int LED2 = 12;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(LED1,HIGH);
  delay(1000);
  digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  delay(1000);
  digitalWrite(LED2,LOW);
  delay(1000);

}

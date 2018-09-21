#define LED1 A4
#define LED2 A5
#define SW1  8
#define SW2  9

void setup() {
  // put your setup code here, to run once:
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED2, LOW);
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(1000);
}

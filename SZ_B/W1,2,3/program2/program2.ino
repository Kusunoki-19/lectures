#define LED1 A4
#define LED2 A5
#define SW1  8
#define SW2  9
#define ON LOW
#define OFF HIGH

void setup() {
  // put your setup code here, to run once:
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(SW1 , INPUT_PULLUP);
    pinMode(SW2 , INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
  digitalWrite(LED2, LOW);
  if(digitalRead(SW1) == LOW) {
     digitalWrite(LED1, HIGH);
     delay(1000);
     digitalWrite(LED1, LOW);
  }
  if(digitalRead(SW2) == LOW) {
     digitalWrite(LED2, HIGH);
     delay(1000);
     digitalWrite(LED2, LOW);
  }
}

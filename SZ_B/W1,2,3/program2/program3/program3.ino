#define Potentio  A0
#define SEN_L  A1
#define SEN_R  A2
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
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Potentio\t:");   Serial.println(analogRead(Potentio));
  Serial.print("Line Sen L\t:"); Serial.println(analogRead(SEN_L));
  Serial.print("Line Sen R\t:"); Serial.println(analogRead(SEN_R));
  delay(1000);
}

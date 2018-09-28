#define Potentio  A0
#define SEN_L  A1
#define SEN_R  A2
#define LED1 A4
#define LED2 A5

#define CW1  2
#define PWM1 3
#define CCW1 4

#define CW2  5
#define PWM2 6
#define CCW2 7

#define SW1  8
#define SW2  9

#define STNBY1 10
#define STNBY2 11

#define ON LOW
#define OFF HIGH

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  Serial.begin(115200);
  delay(100);
  digitalWrite(CW1 , HIGH);
  digitalWrite(STNBY1 , HIGH);

}

void loop() {
  //Serial.print("Potentio\t:");
  Serial.print(millis());
  Serial.print(",");
  //Serial.print("Potentio\t:");
  Serial.print(analogRead(Potentio));
  Serial.print(",");
  //Serial.print("Line Sen L\t:");
  Serial.print(analogRead(SEN_L));
  Serial.print(",");
  //Serial.print("Line Sen R\t:");
  Serial.print(analogRead(SEN_R));
  Serial.print("\n");
  delay(50);
}

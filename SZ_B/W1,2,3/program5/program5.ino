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
  // put your main code here, to run repeatedly:
  static int potentioVal = 0;
  static int servoVal = 0;
  potentioVal = analogRead(Potentio);
  servoVal = 255.0 / 1024.0 * float(potentioVal);
  analogWrite(PWM1, servoVal);
  Serial.println(servoVal);
  delay(100);
}

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
    pinMode(PWM1, OUTPUT);
    pinMode(PWM2, OUTPUT);
    pinMode(STNBY1, OUTPUT);
    pinMode(STNBY2, OUTPUT);
    pinMode(CW1, OUTPUT);
    pinMode(CW2, OUTPUT);
    
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    
    Serial.begin(115200);
    delay(100);
    digitalWrite(STNBY1 , HIGH); //STNBYをHIGHでロック解除
    digitalWrite(STNBY2 , HIGH);
    digitalWrite(CW1 , HIGH); //時計回りを使用
    digitalWrite(CW2 , HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(SW1) == ON) {
        Serial.println("SW1");
        analogWrite(PWM1, 255);
        delay(1000);
        analogWrite(PWM1, 0);
    }
    else if(digitalRead(SW2) == ON) {
        Serial.println("SW2");
        analogWrite(PWM2, 255);
        delay(1000);
        analogWrite(PWM2, 0);
    }
    else if((digitalRead(SW1) == ON) &&(digitalRead(SW2) == ON)) {
        Serial.println("SW1 + SW2");
        analogWrite(PWM1, 255);
        analogWrite(PWM2, 255);
        delay(1000);
        analogWrite(PWM1, 0);
        analogWrite(PWM2, 0);
    }
}

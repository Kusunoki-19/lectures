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

struct Cur_Time {
  float pre;
  float now;
} CUR_TIME;


struct Cur_Potentio {
  int pre;
  int now;
  float deliv;
  float integ;
} CUR_POTENTIO;

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

  CUR_TIME.now = 0;
  CUR_TIME.pre = 0;
  CUR_POTENTIO.now = 0;
  CUR_POTENTIO.pre = 0;
  CUR_POTENTIO.deliv = 0;
  CUR_POTENTIO.integ = 0;

}
void loop() {
    
  static int count = 0;
  double dt = 0;
  int dv = 0;

  if (count < 200) {
    CUR_TIME.now = millis() / pow(10, 3);
    CUR_POTENTIO.now = analogRead(Potentio);

    //Serial.print("count : ");    
    //Serial.print(count);    Serial.print(",");
    //Serial.print("time : ");    
    Serial.print(CUR_TIME.now);    Serial.print(",");
    //Serial.print("pote : ");    
    Serial.print(CUR_POTENTIO.now);    Serial.print(",");

    if (count == 0) {
      dt = (CUR_TIME.now);
      dv = CUR_POTENTIO.now;
    } else {
      dt = (CUR_TIME.now - CUR_TIME.pre);
      dv = (CUR_POTENTIO.now - CUR_POTENTIO.pre);
      
      CUR_TIME.pre = CUR_TIME.now;
      CUR_POTENTIO.pre = CUR_POTENTIO.now;
    }

    CUR_POTENTIO.deliv = dv / dt;
    CUR_POTENTIO.integ += CUR_POTENTIO.now * dt;

    //Serial.print("dt : ");    
    //Serial.print(dt);    Serial.print("\t");
    //Serial.print("dv : ");    
    //Serial.print(dv);    Serial.print("\t");
    //Serial.print("deli : ");    
    Serial.print(CUR_POTENTIO.deliv);    Serial.print(",");
    //Serial.print("inte : ");    
    Serial.print(CUR_POTENTIO.integ);    Serial.print("\n");

  }
  count++;
  delay(50);
}

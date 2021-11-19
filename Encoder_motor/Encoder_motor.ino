#define ENCA 2
#define ENCB 3
#define IN1 4
#define IN2 5
#define pwmPin 6

int pos = 0;
long prevT = 0;
float eprev = 0;
float eintegral = 0;

void setup() {
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ENCA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCB), doEncoderB, CHANGE);

}

void loop() {
  //int encA = digitalRead(ENCA);
  //int encB = digitalRead(ENCB);

  //Serial.print("Encoder A =");
  //Serial.println(encA);
  //Serial.print("Encoder B =");
  //Serial.println(encB);

 // Serial.println(pos);
 int goalpos = 1000;
 float kp = 1;
 float kd = 0.299;
 float ki = 0.0;

 long currT = micros();
 float deltaT = ((float)(currT - prevT)/(1.0e6));
 prevT = currT;

 int e = pos - goalpos;
 float dedt = (e - eprev)/(deltaT);
 eintegral = eintegral + (e*deltaT);

 float u = kp*e + kd*dedt + ki*eintegral;

 int pwr = fabs(u);
  if (pwr>255){
    pwr = 255;
    }
 int dir = 1;
 if (u<0){
   dir = -1;
  }

  setMotor(dir, pwr, pwmPin, IN1, IN2);

  eprev = e;
 Serial.println(pwr);
 Serial.println(pos);
}

void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm, pwmVal);
  if (dir == 1){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    }
  else if (dir == -1){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    }
}
void doEncoderA(){  

  // look for a low-to-high on channel A
  if (digitalRead(ENCA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(ENCB) == LOW) {  
      pos = pos + 1;         // CW
    } 
    else {
      pos = pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(ENCB) == HIGH) {   
      pos = pos + 1;          // CW
    } 
    else {
      pos = pos - 1;          // CCW
    }
  }
 
}

void doEncoderB(){  

  // look for a low-to-high on channel B
  if (digitalRead(ENCB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(ENCA) == HIGH) {  
      pos = pos + 1;         // CW
    } 
    else {
      pos = pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(ENCA) == LOW) {   
      pos = pos + 1;          // CW
    } 
    else {
      pos = pos - 1;          // CCW
    }
  }
  

}

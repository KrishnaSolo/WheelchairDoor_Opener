
#define InA1            7                  // INA motor pin
#define InB1            8                  // INB motor pin
#define PWM1            5                   // PWM motor pin

void setup() {
 pinMode(InA1, OUTPUT);
 pinMode(InB1, OUTPUT);
 pinMode(PWM1, OUTPUT);
}

void loop() {
 motorForward(200);                        //(25%=64; 50%=127; 100%=255)
 delay(2400);

 motorStop();
 delay(10000);

 motorBackward(200);
 delay(2400);

 
}

void motorForward(int PWM_val)  {
 analogWrite(PWM1, PWM_val);
 digitalWrite(InA1, LOW);
 digitalWrite(InB1, HIGH);
}

void motorStop()  {
 analogWrite(PWM1, 0);
 digitalWrite(InA1, LOW);
 digitalWrite(InB1, LOW);
}

void motorBackward(int PWM_val)  {
 analogWrite(PWM1, PWM_val);
 digitalWrite(InA1, HIGH);
 digitalWrite(InB1, LOW);
}

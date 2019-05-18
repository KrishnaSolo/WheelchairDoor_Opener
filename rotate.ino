int motorPin1=7;
int motorPin2=8;
int EnablePin=5;
int flag=0;
int check;
int encoderPinA=2;
int encoderPinB=3;
long int c = 0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  analogWrite(EnablePin, 200);
  Serial.begin(115200);
  attachInterrupt(0,counter,CHANGE);
  attachInterrupt(1,counter,CHANGE);

}

void loop() {
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    check=1;
    analogWrite(EnablePin,90);

    if (flag==0)
    {
      Serial.println("MOTOR:right");
      flag=1;
    }
  }
  if(c>800);
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2,HIGH);
    Serial.println("MOTOR: stop");
    analogWrite(EnablePin,0);
  }
  Serial.println(c);
}  

void counter()
{
  if(check==0)
  {
    c--;
  }
  else if(check==1)
  {
    c++;
  }
}





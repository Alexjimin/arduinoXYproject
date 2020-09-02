#include <Arduino.h>

#include <Servo.h>

/* ###############################




############################### */

// make servo objects
Servo Xservo;
Servo Yservo;

// declare constant servo pins (out)
const int XSpin=7;
const int YSpin=6;

// declare constant joystick pins (read)
const int XJpin=A0;
const int YJpin=A1;
const int Bpin=5;

//declare X, Y and Button states
int Xval;
int Yval;
int Bval;

// declare servo rotation as values (out)
int XSval;
int YSval;

// declare delay time
const int dt=100;

void setup() {
  // begin serial monitor @ boardrate 9600
  Serial.begin(9600);

  // set pin modes
  pinMode(XJpin,INPUT);
  pinMode(YJpin,INPUT);
  pinMode(Bpin, INPUT);
  // attaches servoes to 
  Xservo.attach(XSpin);
  Yservo.attach(YSpin);

  // set servoes to initial rotation, need to find init rotation
  XSval=20;
  YSval=105;
  Xservo.write(XSval);
  Yservo.write(YSval);
}

void loop() {
  Xval=analogRead(XJpin);
  Yval=analogRead(YJpin);
  //Bval = digitalRead(Bpin);

// Serial Monitor
//  Serial.println("X axis: ");
//  Serial.println(XSval);
//  Serial.println("Y axis: ");
//  Serial.println(YSval);
//  Serial.println(Yval);
//  Serial.println("Button: ");
//  Serial.println(Bval);
  delay(dt);

  

  //slow increments mode code;
  if (Xval>682) {XSval++;Xservo.write(XSval);}
  if (Xval<350) {XSval--;Xservo.write(XSval);}
  if (Yval>682) {YSval++;Yservo.write(YSval);}
  if (Yval<350) {YSval--;Yservo.write(YSval);}

  // quick increments mode code
  Xservo.write(map(Xval, 0, 1023, 0, 180));
  Yservo.write(map(Yval, 0, 1023, 0, 180));


  
  //button code
  if(Bval==HIGH){
    XSval=905;
    YSval=90;
    Xservo.write(XSval);
    Yservo.write(YSval);
  }


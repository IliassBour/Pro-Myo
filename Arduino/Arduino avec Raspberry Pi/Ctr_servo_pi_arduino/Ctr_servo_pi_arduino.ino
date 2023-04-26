#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

//--------------Constantes-------------//
const int EMGpin=A15;
const int Pressurepin=A3;
const int SERVOpin1=2;
const int SERVOpin2=3;
const int SERVOpin3=4;
const int SERVOpin4=5;
const byte numChars = 32;
const int temps_move = 30000;
const int temps_calib = 2000;
const int position_max = 170;
const int ForceMaxCapteur = 457;
const int Iindex = 170;
const int Imajeur = 170;
const int Ianulaire = 10;
const int Iauriculaire = 10;
//--------------Variables--------------//
String cmd;
String refCmd_0 = String(0);
String refCmd_1 = String(1);
String refCmd_2 = String(2);
String refCmd_3 = String(3);
String refCmd_4 = String(4);
String refCmd_5 = String(5);
String refSubCmd_1 = String(-1);
String refSubCmd_2 = String(-2);
String refSubCmd_3 = String(-3);
String data;
int EMG_value = 0;
int sensor_value = 0;
int pos_moteur34 = 10;
int pos_moteur12 = 155;
//--------------Fonctions--------------//
void writeToPi(){
  EMG_value = analogRead(EMGpin);
  Serial.println(EMG_value);
  //while(Serial.available() <= 0){}
  //cmd = Serial.readStringUntil('\n');
  //sensor_value = analogRead(Pressurepin);
  //Serial.println(sensor_value);
}
//-------------------------------------//

void setup() {
  Serial.begin(115200);
  pinMode(SERVOpin1, OUTPUT);
  pinMode(SERVOpin2, OUTPUT);
  pinMode(SERVOpin3, OUTPUT);
  pinMode(SERVOpin4, OUTPUT);
  pinMode(EMGpin, INPUT);
  myservo1.attach(SERVOpin1);
  myservo2.attach(SERVOpin2);
  myservo3.attach(SERVOpin3);
  myservo4.attach(SERVOpin4);
  //Serial.println("<Arduino is ready>\n");
  myservo1.write(Iindex);
  myservo2.write(Imajeur);
  myservo3.write(Ianulaire);
  myservo4.write(Iauriculaire);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() <= 0){
  }
  cmd = Serial.readStringUntil('\n');
  int comand = cmd.toInt();

  switch(comand) {
    case 1://--------------Calibration--------------//
      writeToPi();
      break;

    case 2://--------------Prise cylindrique--------------//
      while(1){
        delay(2);
        writeToPi();
        while(Serial.available() <= 0){
        }
        cmd = Serial.readStringUntil('\n');
        comand = cmd.toInt();
        sensor_value = analogRead(Pressurepin);
        if(comand == 1) {
          pos_moteur34 = 10;
          pos_moteur12 = 155;
          myservo1.write(pos_moteur12);
          myservo2.write(pos_moteur12);
          myservo3.write(pos_moteur34);
          myservo4.write(pos_moteur34);
        } else if(comand == 2 && sensor_value < 400 || pos_moteur34 >= position_max || pos_moteur12 <= 10) {
          myservo1.write(pos_moteur12);
          myservo2.write(pos_moteur12);
          myservo3.write(pos_moteur34);
          myservo4.write(pos_moteur34);
        } else {
          pos_moteur34 += 1;
          pos_moteur12 -= 1;
          myservo1.write(pos_moteur12);
          myservo2.write(pos_moteur12);
          myservo3.write(pos_moteur34);
          myservo4.write(pos_moteur34);
          delay(1);
        }
      }
      break;

    case 3://--------------Back--------------//
      pos_moteur34 = 10;
      pos_moteur12 = 155;
      myservo1.write(pos_moteur12);
      myservo2.write(pos_moteur12);
      myservo3.write(pos_moteur34);
      myservo4.write(pos_moteur34);
      break;

    case 4://--------------Countdown--------------//
      myservo1.write(155);
      myservo2.write(155);
      myservo3.write(10);
      myservo4.write(10);
      delay(1000);
      myservo3.write(155);
      delay(1000);
      myservo4.write(155);
      delay(1000);
      myservo2.write(10);
      delay(1000);
      myservo1.write(10);
      break;

    case 5://--------------Prise Pouce Index--------------//
      while(1){
        delay(2);
        writeToPi();
        while(Serial.available() <= 0){
        }
        cmd = Serial.readStringUntil('\n');
        comand = cmd.toInt();

        sensor_value = analogRead(Pressurepin);
        if(comand == 1) {
          pos_moteur12 = 155;
          myservo1.write(pos_moteur12);
        } else if(comand == 2 && sensor_value < 400 || pos_moteur12 <= 10) {
          myservo1.write(pos_moteur12);
        } else {
          pos_moteur12 -= 1;
          myservo1.write(pos_moteur12);
          delay(1);
        }
      }
      break;

    default:
      delay(1);
      break;
  }
  delay(2);
}

#include <Servo.h>
Servo myservo;

//--------------Constantes-------------//
const int EMGpin=A0;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_calib = 2000;
const int temps_move = 30000;
//--------------Variables--------------//
int Seuil=0;
int SeuilComparaison = 0;
int SeuilMove = 0;
int valeur_precedent = 0;
int temps_initial = 0;
int temps_final = 0;
//--------------Fonctions--------------//
//Pas certain si nous devons les instancier avant pour les utiliser dans le setup par exemple.
//void Calibration();
//void MoveMotors();


void setup() {
  Serial.begin(115200);
  pinMode(SERVOpin, OUTPUT);
  pinMode(EMGpin, INPUT);
  pinMode(10, OUTPUT);
  myservo.attach(13);
  //Serial.println("<Arduino is ready>\n");

}

int i = 0;
String data;

void loop() {
  //Send data
  /*Serial.println(i);
  i++;/**/
  //Receive data then send it back
  /*while(Serial.available() <= 0) {}
  data = Serial.readStringUntil('\n');
  Serial.println("Data=" + data);*/
  if(Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    //delay(100);
    //Serial.println("Data=" + data);
    Serial.println(data+"\n"+i);
    i++;
  }

  //Alumer LED
  if(i >= 1000) {
    analogWrite(10, 0);
  } 
  else if(i > 0) {
    analogWrite(10, 200);
  }/**/
}

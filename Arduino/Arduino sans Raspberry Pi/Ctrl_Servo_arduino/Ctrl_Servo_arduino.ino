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
const int temps_move = 900000;
const int position_max = 170;
const int ForceMaxCapteur = 457;
const int Iindex = 170;
const int Imajeur = 170;
const int Ianulaire = 10;
const int Iauriculaire = 10;
//--------------Variables--------------//
int temps_initial = 0;
int temps_final = 0;
int SeuilMove = 170;
int Seuil = 170;
int SeuilComparaison = 170/2;
int ForceCapteur = 0;
int pos_moteur34 = 10;
int pos_moteur12 = 170;
int pos_moteur = 10;

//--------------Fonctions--------------//
//Pas certain si nous devons les instancier avant pour les utiliser dans le setup par exemple.
//void Calibration();
//void MoveMotors();


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
  Serial.println("<Arduino is ready>\n");
  myservo1.write(Iindex);
  myservo2.write(Imajeur);
  myservo3.write(Ianulaire);
  myservo4.write(Iauriculaire);

}


void PriseCylindre(){
  if (analogRead(EMGpin) <= SeuilMove){  
    pos_moteur34 = 10;
    pos_moteur12 = 170;
    myservo1.write(pos_moteur12);
    myservo2.write(pos_moteur12);
    myservo3.write(pos_moteur34);
    myservo4.write(pos_moteur34);
    SeuilMove = Seuil;
  }
  else if ((analogRead(EMGpin)> SeuilMove && analogRead(Pressurepin) < 400) || pos_moteur34 >= position_max || pos_moteur12 <= 10) {
    myservo1.write(pos_moteur12);
    myservo2.write(pos_moteur12);
    myservo3.write(pos_moteur34);
    myservo4.write(pos_moteur34);
    SeuilMove = SeuilComparaison;
  }
  else {
    pos_moteur34 += 1;
    pos_moteur12 -= 1;
    myservo1.write(pos_moteur12);
    myservo2.write(pos_moteur12);
    myservo3.write(pos_moteur34);
    myservo4.write(pos_moteur34);
    SeuilMove = SeuilComparaison;
    delay(1);
  }
  //Serial.println("Capteur");
  Serial.println(analogRead(EMGpin));
  //Serial.println("pos_moteur");
  //Serial.println(pos_moteur);
}


void PrisePouceIndex(){
  
  if (analogRead(EMGpin) <= SeuilMove){  
    pos_moteur12 = 170;
    myservo1.write(pos_moteur12);
    SeuilMove = Seuil;
  }
  else if ((analogRead(EMGpin)> SeuilMove && analogRead(Pressurepin) < 400) || pos_moteur12 <= 10) {
    myservo1.write(pos_moteur12);
    SeuilMove = SeuilComparaison;
  }
  else {
    pos_moteur12 -= 1;
    myservo1.write(pos_moteur12);
    SeuilMove = SeuilComparaison;
    delay(10);
  }
  //Serial.println("Capteur");
  Serial.println(analogRead(EMGpin));
  //Serial.println("pos_moteur");
  //Serial.println(pos_moteur);
}

void loop() {
  Serial.println("Make A Choice\n 1- Calibration\n 2- Prise Cynlindrique\n 3- Back\n 4- Count Down\n 5- Prise Pouce Index\n");
  while (Serial.available() == 0) {
  }
  int menuChoice = Serial.parseInt();
  Serial.println(menuChoice+"\n");
  switch (menuChoice) {
    case 1:
      Serial.println("Calibration Start");
      Seuil = 0;
      //CalibrationMinMax();
      Serial.println("Calibration Done");
      Serial.println("Seuil :"); 
      Serial.println(Seuil);
      Serial.println("\n");
      break;

    case 2:
      Serial.println("Motors Start");
      temps_initial = millis(); 
      temps_final = millis();
      while(1){ //Pour le moment, bouge pendant un temps défini. Éventuellement, faire sortir avec une selection de l'utilisateur.
        PriseCylindre();              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
        temps_final = millis();
        //Serial.println("Pression");
        //Serial.println(analogRead(Pressurepin));
        delay(1);
      }
      Serial.println("Motors Done");
      //Serial.println("Motors position");
      //Serial.println(myservo.read());
      Serial.println("\n");
      break;

    case 3:
      pos_moteur34 = 10;
      pos_moteur12 = 170;
      myservo1.write(pos_moteur12);
      myservo2.write(pos_moteur12);
      myservo3.write(pos_moteur34);
      myservo4.write(pos_moteur34);

      break;

    case 4:
      myservo1.write(180);
      myservo2.write(180);
      myservo3.write(10);
      myservo4.write(10);
      delay(1000);
      myservo3.write(180);
      delay(1000);
      myservo4.write(180);
      delay(1000);
      myservo2.write(10);
      delay(1000);
      myservo1.write(10);
      break;

    case 5:
      Serial.println("Motors Start");
      temps_initial = millis(); 
      temps_final = millis();
      while(1){ //Pour le moment, bouge pendant un temps défini. Éventuellement, faire sortir avec une selection de l'utilisateur.
        PrisePouceIndex();              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
        temps_final = millis();
        //Serial.println("Pression");
        //Serial.println(analogRead(Pressurepin));
        delay(1);
      }
      Serial.println("Motors Done");
      //Serial.println("Motors position");
      //Serial.println(myservo.read());
      Serial.println("\n");
      break;
      
    default:
      Serial.println("Please choose a valid selection\n");
  }
}

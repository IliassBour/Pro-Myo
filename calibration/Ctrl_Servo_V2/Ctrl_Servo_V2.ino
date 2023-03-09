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
  myservo.attach(13);
  Serial.println("<Arduino is ready>\n");

}


void Calibration(int valeur) {
  if(valeur > valeur_precedent){
    Seuil = valeur/6;
    SeuilComparaison = Seuil/2;
    SeuilMove = Seuil;
    valeur_precedent = valeur;
  }
  Serial.println(valeur);
}


void MoveMotors(int valeur){
  if(valeur > SeuilMove){
    myservo.write(170);
    SeuilMove = SeuilComparaison;
  }
  else {
    myservo.write(10);
    SeuilMove = Seuil;
  }
}


void loop() {
  Serial.println("Make A Choice\n 1- Calibration\n 2- Move Motors\n 3- Back");
  while (Serial.available() == 0) {
  }
  int menuChoice = Serial.parseInt();
  switch (menuChoice) {
    case 1:
      Serial.println("Calibration Start");
      Seuil = 0;
      temps_initial = millis();
      temps_final = millis();
      while(temps_final < temps_calib+temps_initial){ //Pour le moment, bouge pendant un temps défini. Éventuellement, ajouter une sortie si mauvais choix appliquer.
        Calibration(analogRead(EMGpin));             //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction Calibation
        //Serial.println(analogRea1d(EMGpin));
        temps_final = millis();
        delay(1);
      }
      Serial.println("Calibration Done");
      Serial.println("Seuil :");
      Serial.println(Seuil);
      Serial.println("\n");
      break;

    case 2:
      Serial.println("Motors Start");
      temps_initial = millis();
      temps_final = millis();
      while(temps_final < temps_move+temps_initial){ //Pour le moment, bouge pendant un temps défini. Éventuellement, faire sortir avec une selection de l'utilisateur.
        MoveMotors(analogRead(EMGpin));              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
        temps_final = millis();
      }
      Serial.println("Motors Done");
      Serial.println("Motors position");
      Serial.println(myservo.read());
      Serial.println("\n");
      break;

    case 3:
      Serial.println("Back\n");
      break;

    default:
      Serial.println("Please choose a valid selection\n");
  }
}

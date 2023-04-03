#include <Servo.h>
Servo myservo;

//--------------Constantes-------------//
const int EMGpin=A0;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_calib = 1000;
const int temps_move = 2000;
//--------------Variables--------------//
int Seuil=0;
int SeuilComparaison = 0;
int SeuilMove = 0;
int valeur_precedent = 0;
int valeurNewRelax = 0;
long valeurOldRelax = 0;
int valeurNewForce = 0;
long valeurOldForce = 0;
int nbvaleurRelax = 0;
int nbvaleurForce = 0;
int MoyRelax = 0;
int MoyForce = 0;
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


void CalibrationMinMax() {
  valeurOldRelax = 0;
  valeurNewRelax = 0;
  Serial.println("Relaxez votre bras");
  delay(1000);
  temps_initial = millis();
  temps_final = millis();
  while(temps_final < temps_calib+temps_initial){
    valeurNewRelax = analogRead(EMGpin);
    if (valeurNewRelax > valeurOldRelax){
      valeurOldRelax = valeurNewRelax;
    }
    Serial.println(valeurNewRelax);
    delay(1);
    temps_final = millis();
  }
  Serial.println("Fin");
    
  Serial.println("Forcez");
  valeurOldForce = 1024;
  valeurNewForce = 1024;
  delay(1000);
  temps_initial = millis();
  temps_final = millis();
  while(temps_final < temps_calib+temps_initial){
    valeurNewForce = analogRead(EMGpin);
    if (valeurNewForce < valeurOldForce){
      valeurOldForce = valeurNewForce;
    }
    Serial.println(valeurNewForce);
    delay(1);
    temps_final = millis();
  }  
  Serial.println("Fin");
  Seuil = (valeurOldForce + valeurOldRelax)/2;
  SeuilComparaison = Seuil/2;
  SeuilMove = Seuil;
  Serial.println(Seuil);
  Serial.println(SeuilComparaison);
  Serial.println(SeuilMove);
}


void CalibrationMinMaxMoyen() {
  valeurOldRelax = 0;
  valeurNewRelax = 0;
  nbvaleurRelax = 0;
  Serial.println("Relaxez votre bras");
  delay(1000);
  temps_initial = millis();
  temps_final = millis();
  while(temps_final < temps_calib+temps_initial){
    valeurNewRelax = analogRead(EMGpin);
    valeurOldRelax += valeurNewRelax;
    nbvaleurRelax += 1;
    Serial.println(valeurNewRelax);
    delay(1);
    temps_final = millis();
  }
  MoyRelax = valeurOldRelax/nbvaleurRelax;
  Serial.println("Fin");
    
  Serial.println("Forcez");
  valeurOldForce = 0;
  valeurNewForce = 0;
  nbvaleurForce = 0;
  delay(1000);
  temps_initial = millis();
  temps_final = millis();
  while(temps_final < temps_calib+temps_initial){
    valeurNewForce = analogRead(EMGpin);
    valeurOldForce += valeurNewForce;
    nbvaleurForce += 1;
    Serial.println(valeurNewForce);
    delay(1);
    temps_final = millis();
  }  
  MoyForce = valeurOldForce/nbvaleurForce;
  Serial.println("Fin");
  Seuil = (MoyRelax + MoyForce)/2;
  SeuilComparaison = Seuil/2;
  SeuilMove = Seuil;
  Serial.println(Seuil);
  Serial.println(SeuilComparaison);
  Serial.println(SeuilMove);
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
  Serial.println(valeur);
}


void loop() {
  Serial.println("Make A Choice\n 1- Calibration\n 2- Move Motors\n 3- Back\n");
  while (Serial.available() == 0) {
  }
  int menuChoice = Serial.parseInt();
  switch (menuChoice) {
    case 1:
      Serial.println("Calibration Start");
      Seuil = 0;
      CalibrationMinMaxMoyen();
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
        delay(1);
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

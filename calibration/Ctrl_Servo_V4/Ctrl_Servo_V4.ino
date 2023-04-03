#include <Servo.h>
Servo myservo;

//--------------Constantes-------------//
const int EMGpin=A0;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_move = 1000;
//--------------Variables--------------//
int valeur_precedent1 = 0;
int valeur_precedent2 = 0;
int temps_initial = 0;
int temps_final = 0;
float temps_initial_derive = 0;
float temps_final_derive = 0;
int SeuilMove = 0;
int Seuil = 0;
int SeuilComparaison = 0;
float dt = 0;
float derive = 0;
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


void MoveMotors(float valeur, byte Type){
  temps_initial_derive = millis();
  dt = (temps_initial_derive - temps_final_derive)/1000.00;
  switch (Type)
  {
    case 0:
      derive = (valeur_precedent1-valeur_precedent2)/dt;
      break;

    case 1:
      derive = (valeur - valeur_precedent1)/dt;
      break;

    case 2:
      derive = (valeur - valeur_precedent2)/(2.0*dt);
      break;
    
  }
  valeur_precedent2 = valeur_precedent1;
  valeur_precedent1 = valeur;
  temps_final_derive = millis();

  if(derive > Seuil){
    myservo.write(170);
    SeuilMove = SeuilComparaison;
  }
  else if(derive < -Seuil) {
    myservo.write(10);
    SeuilMove = Seuil;
  }
  Serial.println(valeur);
  Serial.println(derive);
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
      while(temps_final < temps_move+temps_initial){ //Pour le moment, bouge pendant un temps défini. Éventuellement, faire sortir avec une selection de l'utilisateur.
        MoveMotors(analogRead(EMGpin), 1);              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
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

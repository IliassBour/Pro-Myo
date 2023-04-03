#include <Servo.h>
Servo myservo;

//--------------Constantes-------------//
const int EMGpin=A0;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_move = 2000;
//--------------Variables--------------//
int temps_initial = 0;
int temps_final = 0;
int SeuilMove = 0;
int Seuil = 0;
int SeuilComparaison = 0;
int taille_lot = 10;
int nb_lot = 0;
long lot = 0;
long lot_precedent = 0;
float diff_lot = 0;
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


void MoveMotors(){
  diff_lot = 0;
  lot = 0;
  while (nb_lot < taille_lot){
    nb_lot += 1;
    lot = lot + analogRead(EMGpin);
    delay(1);
    //Serial.println(nb_lot);
  }
  nb_lot = 0;
  lot = lot/taille_lot;
  diff_lot = lot - lot_precedent;
  lot_precedent = lot; 


  if(diff_lot > Seuil){
    myservo.write(170);
    SeuilMove = SeuilComparaison;
  }
  else if(diff_lot < -Seuil) {
    myservo.write(10);
    SeuilMove = Seuil;
  }
  Serial.println(lot);
  //Serial.println(lot_precedent);
  //Serial.println(diff_lot);
  //Serial.println(taille_lot);
  //Serial.println(nb_lot);

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
        MoveMotors();              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
        temps_final = millis();
        delay(1);
      }
      lot_precedent = 0;
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

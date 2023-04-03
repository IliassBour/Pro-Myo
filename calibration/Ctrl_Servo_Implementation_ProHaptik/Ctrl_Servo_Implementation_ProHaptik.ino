#include <Servo.h>
Servo myservo;

//--------------Constantes-------------//
const int EMGpin=A0;
const int Pressurepin=A3;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_move = 5000;
const int position_max = 170;
const int ForceMaxCapteur = 457;
//--------------Variables--------------//
int temps_initial = 0;
int temps_final = 0;
int SeuilMove = 170;
int Seuil = 170;
int SeuilComparaison = 170/2;
int ForceCapteur = 0;
int pos_moteur = 0;
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

  if (300 < SeuilMove){  
    pos_moteur = 10;
    myservo.write(pos_moteur);
  }
  else if ((300> SeuilMove && analogRead(Pressurepin) < 400) || pos_moteur >= position_max) {
    myservo.write(pos_moteur);
    SeuilMove = Seuil;
  }
  else {
    pos_moteur += 1;
    myservo.write(pos_moteur);
    SeuilMove = SeuilComparaison;
    delay(1);
  
  }
  //Serial.println("Capteur");
  //Serial.println(analogRead(EMGpin));
  Serial.println("pos_moteur");
  Serial.println(pos_moteur);

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
        Serial.println("Pression");
        Serial.println(analogRead(Pressurepin));
        delay(1);
      }
      Serial.println("Motors Done");
      Serial.println("Motors position");
      Serial.println(myservo.read());
      Serial.println("\n");
      break;

    case 3:
      Serial.println("Start\n");
      myservo.write(300);
      delay(3000);
      myservo.write(10);
      Serial.println(myservo.read());
      Serial.println("Back\n");
      break;

    default:
      Serial.println("Please choose a valid selection\n");
  }
}

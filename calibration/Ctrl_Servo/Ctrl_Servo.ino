#include <Servo.h>
Servo myservo;


//--------------Constantes-------------//
const int EMGpin=A0;
const int SERVOpin=13;
const byte numChars = 32;
const int temps_calib = 10000;
const int temps_move = 30000;
//--------------Variables--------------//
int Seuil=0;
int valeur_precedent = 0;
char receivedChars[numChars];
boolean newData = false;
int dataNumber = 0;
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
  Serial.println("<Arduino is ready>");
}


void Calibration(int valeur) {
  if(valeur > valeur_precedent){
    Seuil = valeur/2;
    valeur_precedent = valeur;
  }
}


void MoveMotors(int valeur){
  if(valeur > Seuil){
    myservo.write(170);
    Seuil = Seuil/2;
  }
  else {
    myservo.write(10);
    Seuil = Seuil*2;
  }
}


void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  Serial.print("Chose an option\n 1-Calibration\n 2-Moving Sequence\n 3-Back\n");
  if (Serial.available() > 0) {
    rc = Serial.read();

    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0';
      ndx = 0;
      newData = true;
    }
  }
}


void showNewNumber() {
  if (newData == true) {
    dataNumber = 0;
    dataNumber = atoi(receivedChars);
    Serial.print("This just in ... ");
    Serial.println(receivedChars);
    Serial.print("Data as Number ... ");
    Serial.println(dataNumber);
    newData = false;
  }
}


void loop() {
  recvWithEndMarker();
  showNewNumber();                        //Probablement pas necessaire, mais garder pour debug
  if(dataNumber ==1){  
    temps_initial = millis();
    temps_final = 0;
    while(temps_final < temps_calib+temps_initial){ //Pour le moment, bouge pendant un temps défini. Éventuellement, ajouter une sortie si mauvais choix appliquer.
      Calibration(analogRead(EMGpin));              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction Calibation
      temps_final = millis();
    }
  }
  else if(dataNumber == 2){
    temps_initial = millis();
    temps_final = 0;
    while(temps_final < temps_move+temps_initial){ //Pour le moment, bouge pendant un temps défini. Éventuellement, faire sortir avec une selection de l'utilisateur.
      MoveMotors(analogRead(EMGpin));              //Possibiliter d'alléger le loop en mettant la boucle while et le reste dans la fonction MoveMotors
      temps_final = millis();
    }
  }
  else if(dataNumber==3){
    break;
  }
  else{
    Serial.print("Not an option");
  }
}

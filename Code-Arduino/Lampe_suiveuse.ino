#include <Servo.h>                              // Importe la biblihotèques
Servo servo_lampe ;                             // declare le servo-moteur


int angle ;                                     // variable de la valeur de l'angle du servomoteur
int x ;                                         // variable de la valeur horizontal du joystick
int y ;                                         // variable de la valeur vertical du joystick
int red ;                                       // variable de la valeur du rouge ( 0 <= rouge <= 255 )
int r ;                                         // variable de la valeur du potentiometre rouge
int green ;                                     // variable de la valeur du vert ( 0 <= vert <= 255 )
int g ;                                         // variable de la valeur du potentiometre vert
int blue ;                                      // variable de la valeur du bleu ( 0 <= bleu <= 255 )
int b ;                                         // variable de la valeur du potentiometre bleu
int Power = 50;                                 // variable de la vélocité du moteur
int rota ;                                      // variable de la position du joystick

const int Moteur_Pied = 3 ;                     // declare la broche pour les moteurs de la base
const int Joystick_x = A0 ;                     // declare la broche pour le joystick ( donnée horizontale )
const int Joystick_y = A1 ;                     // declare la broche pour le joystick ( donnée verticale )
const int PontH = 2;                            // declare la broche pour le pont en H
const int MotorForward = 3;                     // declare la broche du signal PWM dans le sens direct
const int MotorReverse = 5;                     // declare la broche du signal PWM a contre-sens
const int Led = 8 ;                             // declare la broche pour la lampe LED
const int pot_r = A2 ;                          // declare la broche pour le potentiometre rouge
const int pot_g = A3 ;                          // declare la broche pour le potentiometre vert
const int pot_b = A4 ;                          // declare la broche pour le potentiometre bleu


void setup() {
  pinMode ( Moteur_Pied , OUTPUT ) ;            // declare la broche des moteurs de la base en sortie
  servo_lampe.attach(10) ;                      // attache le servomoteur a la broche 9
  pinMode ( Joystick_x , INPUT ) ;              // declare la borche du joystick x en entrée
  pinMode ( Joystick_y , INPUT ) ;              // declare la borche du joystick y en entrée
  pinMode ( MotorForward, OUTPUT) ;             // declare la broche en sortie pour un signal PWM pour tourner dans le sens horaire
  pinMode ( MotorReverse, OUTPUT) ;             // declare la broche en sortie pour un signal PWM pour tourner dans le sens anti-horaire
  pinMode ( PontH, OUTPUT );                    // declare la broche pour le pont H en tant que sortie
  pinMode ( Led , OUTPUT ) ;                    // declare la broche pour les LEDs en tant que sortie
  Serial.begin ( 9600 ) ;                       // ouverture du port-serie a 9600 bauds

}

void Servo_Lampe () {
  y = analogRead ( Joystick_y ) ;               // lecture de la valeur du joystick sur l'axe y
  angle = map(y, 0, 1023, 0, 180);              // attribue a angle la valeur du joystick dans un nouveau interval
  servo_lampe.write(angle);                     // regle l'angle du servo-moteur avec la valeur predéfinie
  delay(50);                                    // attendre 50 ms pour eviter de faire bugger les servo dans la lecture des données

}

void RGB_I () {
  r = analogRead ( pot_r ) ;                    // lecture de la valeur du potentiometre rouge
  g = analogRead ( pot_g ) ;                    // lecture de la valeur du potentiometre vert
  b = analogRead ( pot_b ) ;                    // lecture de la valeur du potentiometre bleu
  red = map ( r , 0 , 1023 , 0 , 255 ) ;        // attribue une valeur dependant du potentiometre a la variable
  green = map ( g , 0 , 1023 , 0 , 255 ) ;      // attribue une valeur a la variable
  blue = map ( b , 0 , 1023 , 0 , 255 ) ;       // attribue une valeur a la variable
  Serial.print ( "Rouge : " );
  Serial.print ( red ) ;
  Serial.print (' ') ;
  Serial.print ( "Vert : " );
  Serial.print ( green ) ;
  Serial.print (' ') ;
  Serial.print ( "Bleu : " );
  Serial.println ( blue ) ;

}

void Moteur_Rota() {
  x = analogRead ( Joystick_x ) ;               // lecture de la valeur du joystick sur l'axe x
  rota = map ( x , 0 , 1023 , 0 , 500 );
  if ( rota >  ) {                              // verification de la position du joystick
    digitalWrite ( PontH, HIGH );               // activation du pont en H
    while (x > ) {                              // verification de la position du joystick
      analogWrite( MotorForward, Power );       // allumage du moteur pour tourner dans le sens horaire
      analogWrite( MotorReverse, 0);            //
    }
  digitalWrite( PontH, LOW );                   // le mouvement a été effectué, le pont en H est fermé
  }

  if ( rota < ) {                                  // verificiation de la position du joystick
    digitalWrite( PontH, HIGH );
    while (x < ) {
      analogWrite( MotoForward, 0);
      analogWrite( MotorReverse, Power);
  }
  digitalWrite( PontH, LOW );
  }

}

void loop() {
  RGB_I() ;
  Moteur_Rota() ;
  Servo_Lampe() ;
}

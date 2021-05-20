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
int mil_joy_x = 485 ;                           // valeure du milieu du joytsick pour x
int mil_joy_y = 535 ;                           // valeure du milieu du joytsick pour y


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

/*
void RGB_I () {
  r = analogRead ( pot_r ) ;                    // lecture de la valeur du potentiometre rouge
  g = analogRead ( pot_g ) ;                    // lecture de la valeur du potentiometre vert
  b = analogRead ( pot_b ) ;                    // lecture de la valeur du potentiometre bleu
  red = map ( r , 0 , 1023 , 0 , 255 ) ;        // attribue une valeur a la variable
  green = map ( g , 0 , 1023 , 0 , 255 ) ;      // attribue une valeur a la variable
  blue = map ( b , 0 , 1023 , 0 , 255 ) ;       // attribue une valeur a la variable
  Serial.print ( "Rouge : " );                  // Test de reception des valeurs
  Serial.print ( red ) ;
  Serial.print (' ') ;
  Serial.print ( "Vert : " );
  Serial.print ( green ) ;
  Serial.print (' ') ;
  Serial.print ( "Bleu : " );
  Serial.println ( blue ) ;

}
*/

void Moteur_Rota() {
  x = analogRead ( Joystick_x ) ;               // lecture de la valeur du joystick sur l'axe y
  Serial.println ( x );
  if ( x < mil_joy_x - 80 ) {                   // test de la valeur du joystick
    digitalWrite ( PontH , HIGH );              // activation du pont en H
    analogWrite ( MotorForward , Power );       // activation du sens 1 du moteur
    analogWrite ( MotorReverse , 0 ) ;           
    }
  digitalWrite ( PontH , LOW ) ;                // desactivation du pont en H
  if ( x > mil_joy_x + 150 ) {                  // test de la valeur du joystick
    digitalWrite ( PontH , HIGH ) ;             // activation du pont en H
    analogWrite ( MotorForward , 0 ) ;
    analogWrite ( MotorReverse , Power ) ;      // activation du sens 2 du moteur
    }
  digitalWrite ( PontH , LOW ) ;                // desactivation du pont en H
}

void loop() {
  //RGB_I() ;
  Moteur_Rota() ;
  Servo_Lampe() ;
}

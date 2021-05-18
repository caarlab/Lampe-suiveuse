import processing.video.*;
Capture video;
PImage image_a_traiter;
//On importe la librairie de lecture vidéo

void setup(){
  size(600,400);
  video = new Capture(this,640,480,30);
  video.start();
}

void captureEvent(Capture video){
  video.read();
  //lis la vidéo dans une fenetre graphique
}

void draw(){
  detection_rouge();
}

void detection_rouge(){
  // Cette fonction va parcourir les pixels de l'image vidéo a chaque seconde afin de déterminer quelle partie de cette frame ressemblera le plus à du rouge
  float[] liste = new float[100];
  // On crée une liste de 100 élements (ou bien un tableau 10x10, c'est de cette manière que l'on divise l'image pour l'analyser plus efficacement)
  int B=1;
  int k = 0;
  // Toute la partie qui suit permet de parcourir l'image par blocs, 10 par ligne et 10 colonnes soit 100 blocs en tout, d'ou la liste de 100 élements
  while(B<=10){   
    for (int A=0; A<video.width; A=A+(video.width/10)){    
        float somme_red = 0;
        int nombre_pixels = 0;
      for (int i=A; i<=(B*(video.width/10));i++){
        for (int j=A; j<=(B*(video.height/10));j++){
          color x = video.get(i,j);
          float r = red(x);
          somme_red = somme_red + r;
          nombre_pixels = nombre_pixels + 1;
        }
      }
      float moyenne_r = somme_red / nombre_pixels;
      liste[k] = moyenne_r;
      // La moyenne de la composante rouge de chaque pixel d'un bloc est stocké dans sa place correspondante de la liste, liste que l'on va traiter plus bas afin de déterminer quel bloc sera plus rouge que les autres
      k = k+1;
    }
    B = B+1;
  }
  float res=255;
  int e=0;
  while(e<100){
    float stmp=abs(liste[e]-255);
    if(stmp<abs(liste[e+1]-255) && stmp<res){
      res=stmp;
      int num=e;
      // Selon la valeur de e nous savons dans quelle partie de l'image (quel élement de la liste, soit quel élement du tableau 10x10) celle-ci s'approche le plus du rouge, ainsi nous pouvons ici imaginer que le programme va communiquer avec arduino,       
      // qui réagira en conséquence afin de déplacer le dispositif pour qu'il s'oriente vers ce point
    }
    e+=1;
  }
}

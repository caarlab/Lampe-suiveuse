# Cahier de suivi du projet | Fornali Dorian

* Séance du 22 mars 2021

Nous avons formé notre groupe avec Arnaud HOFF et avons réfléchi sur le sujet de notre projet
Nous n'avons rien trouvé de très convaincant

* Séance du 29 mars 2021

Nous nous sommes mis d'accord sur un projet de "lampe" automatisée capable d'effectuer une rotation sur elle-même à 360°, de s'incliner vers le haut et le bas.
Le tout contrôlable à distance grâce à une télécommande. Cerise sur le gateau, on aimerait ensuite ajouter un système avec une caméra permettant à tout le dispositif de fonctionner de manière autonome afin de suivre un point précis de l'environnement.

Il y a beaucoup de travail à réaliser, nous avons commencé à nous répartir les tâches, place d'abord à la conception 3D

* Séances du 5 et 12 avril 2021

Ces séances ont été dédiées à la conception 3D de divers éléments de la lampe:
- Cercle de rotation
- Roues de rotation

J'ai aussi programmé sur Arduino la partie des moteurs de rotation

* Séance du 19 avril 2021

Conception 3D avec Arnaud de la télécommande

* Séance du 26 avril 2021

Étant donné qu'Arnaud s'occupe de toute la partie montage du dispositif j'ai commencé à réfléchir de quelle manière nous allions pouvoir faire suivre la lampe un point précis.
Nous devrons utiliser une caméra, cependant des problèmes se posent:
- L'algorithme parait trop compliqué à concevoir
- Arduino n'a pas l'air bien partique pour le traitement image

La détection de couleur pourrait permettre de détecter un point précis, mais encore une fois Arduino ne permet pas efficacement ce genre d'analyse

* Séance du 10 mai

J'ai eu l'idée d'effectuer tout le traitement image ailleurs que sur Arduino, par exemple sur processing qui permet plutôt facilement le traitement d'image.
Cependant un programme majeur vient s'interposer: comment faire pour que Processing communique avec Arduino ? Je peux certes détecter le point voulu avec un algorithme mais je ne sais même pas si je peux communiquer avec Arduino pour que le dispositif fonctionne en conséquence

* Séance du 17 mai

On manque de temps, on a abandonné toute la partie tracking car nous ne sommes même pas surs de pouvoir faire fonctionner le dispositif de base.
Des pièces se brisent, et entre leur temps d'impression un poil long et l'échéance arrivant à grands pas de la fin de projet ainsi que des examens finaux, il sera impossible d'aboutir notre projet.


















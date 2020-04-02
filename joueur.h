#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

typedef struct 
{ 
  SDL_Surface* sprite;
  SDL_Rect posimagette[4];

SDL_Surface *image;
SDL_Rect posimage;
  
  int nb_vie;
  int score;

 /* Variables utiles pour l'animation */
    int frameNumber, frameTimer;
    int etat, direction;
/* Variables utiles pour la gestion des collisions */
    int onGround, timerMort;
    float dirX, dirY;
    int saveX, saveY;
 
}personnage;

void initialiser_perso(personnage *perso);
void afficher_perso(personnage *perso);
void animate_perso(personnage *perso);
void deplacer_perso_clavier_droite(personnage *perso);
//void deplacer_perso_clavier_haut(personnage *perso);
//void deplacer_perso_clavier_bas(personnage *perso);
void deplacer_perso_clavier_gauche(personnage *perso)

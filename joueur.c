#include "SDL/SDL.h"
#include "joueur.h"
#include "SDL/SDL_image.h"

void initialiser_perso(personnage *perso)
{
perso->sprite=IMG_Load("moiill-ill-droite.png");
      perso->posSprite.x=0 ;
      perso->posSprite.y =0; 

      perso->posSprite.w =315; 
      perso->posSprite.h =181 ;

perso->image=IMG_Load("me11-droite.png");
 perso->posimage.x=0;
 perso->posimage.y=0;
 
perso->posimage.w=119;
perso->posimage.h=213;

perso->nb_vie=3;
perso->score=0;

 perso->direction = RIGHT;
    perso->etat = IDLE;
//Variables nécessaires au fonctionnement de la gestion des collisions
    perso->timerMort = 0;
    perso->onGround = 0;
 
    //Nombre de monstres (à déplacer plus tard dans initialzeGame()
    jeu.nombreMonstres = 0;

}

void afficher_perso(personnage *perso,SDL_rect posimagette[4], SDL_Surface sprite)
{
SDL_BlitSurface(sprite,NULL,ecran,&posSprite);
SDL_Flip(ecran);
}


void deplacer_perso_clavier_droite(personnage *perso)
{      
         

       perso->posSprite.x++;
} 

void deplacer_perso_clavier_gauche(personnage *perso)
{  
 		  
   perso->posSprite.x--;

}
		
/*void deplacer_perso_clavier_haut(personnage *perso)
	{		

  perso->posSprite.y--;
}
                 
void deplacer_perso_clavier_bas(personnage *perso)
	{	
perso->posSprite.y++;

}*/


void setrects(SDL_Rect* clip)
{
                clip[0].x =0 ;
                clip[0].y =0;
                clip[0].w = 83;
                clip[0].h =163;

                clip[1].x = 82;
                clip[1].y = 0;
                clip[1].w = 80;
                clip[1].h =163 ;

                clip[2].x =174 ;
                clip[2].y = 0;
                clip[2].w = 83;
                clip[2].h = 163;

                clip[3].x = 256;
                clip[3].y = 0;
                clip[3].w = 70;
                clip[3].h = 163;
}
/*void setrects(SDL_Rect* clip)
{
  int c;
  for( c=0; c<4; c++)
  {
                clip[c].x = 0+ c*55;
                clip[c].y = 0;
                clip[c].w = 55;
                clip[c].h = 163;

  }
}*/


int main()
{
  const int FPS=20;
  SDL_Surface *screen;
  SDL_Surface *perso;
  SDL_Rect rects[4];
  SDL_Rect rect;
/*rect.x= 500;
rect.y=110 ;
rect.w=12;
rect.h= 5;*/
  int done=1;
  int frame=0;
  Uint32 start;

  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(960,500,32,SDL_SWSURFACE);
	if(screen==NULL)
	{
		printf("unable to set video mode :%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
perso=SDL_DisplayFormat(IMG_Load("moiill-illdroite-espacé2.png"));
SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));
  if(perso==NULL)
	{
		printf("unable to load bitamp: %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
  setrects(rects);
 while(done)
  {
    rect.x=200;
    rect.y=100;

    
    SDL_BlitSurface(perso,&rects[frame],screen,&rect);
SDL_Flip(screen);

    start = SDL_GetTicks();
  
frame++;
    if(frame==4)
      frame=0;
    if(2000/FPS>(SDL_GetTicks()-start))
      SDL_Delay(2000/FPS-(SDL_GetTicks()-start));
  }

SDL_FreeSurface(perso);
  SDL_Quit();
}

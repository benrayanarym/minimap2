#include <SDL/SDL.h>//inclure SDL.h  pour permettre au programme d'être portable sur tous les systèmes.
//.................//Pour manipuler des images ayants des types autre que bmp
//.................//Pour manipuler de l’audio.
//.................//Pour manipuler des textes
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>


int main ( int argc, char** argv )
{

   
SDL_Surface *ecran;//Déclaration d'une variable pointeure sur surface:  pour l'écran,
SDL_Surface *image;//..................//Déclaration d'une variable pointeure sur surface: pour l'image 
image=IMG_Load("palestine.jpg");
///................../Déclaration des variables pointeurs sur surfaces:  pour le texte
//Déclaration des variables de type entier pour la boucle de jeu 
int quitter = 1;
//Déclaration d'un compteur pour la mise à jour aprés un événement
//..................
//Déclaration des positions d'affichage : une pour l'image et une pour le texte
//..................
//..................
//Déclaration du police
//..................
SDL_Color textColor={0,0,0};//Déclaration de la couleur
//..................
//Déclaration de l'événment 
SDL_Event event;
//Déclaration d'une chaine de caractère
//..................
//Déclaration d'une variable pointeur sur l'audio pour le son continue
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
//..................
//Initialisation des sous systhème de SDL vidéo, son et texte
SDL_Init( SDL_INIT_VIDEO) ;
SDL_Init( SDL_INIT_VIDEO|SDL_INIT_AUDIO);
TTF_Init();
//..................
//..................

	/* initialisation de SDL_Video */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	
	}
	
	else
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");
	/* creation d'une fenetre avec une zone d'affichage de 600*430 pixels et qui pemet d'afficher des image couleur*/
	ecran = SDL_SetVideoMode(600, 430,  32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de creation de la fenetre de 300*300: %s.\n", SDL_GetError());
		return 1;
	}
	
	//téléchargement de l'image palestine.jpg
	//..................
		/*if (image== NULL) {
			return ;
		}*/
	//Position de l'image palestine.jpg
	SDL_Rect posimage;//..................
	posimage.x=0;//..................
	posimage.y=0;//..................
	//..................	
	SDL_Surface *texte=NULL;
	//position du texte
	//..................
	//..................
        SDL_Color couleurNoir={0,0,0};
	// couleur du texte noire
        //..................
        //..................
        //..................
	TTF_Font* police=TTF_OpenFont( "arial.ttf",65);
	//téléchargement du police
        //..................
        //Télécharger la musique
	Mix_Music *musique;
	musique=Mix_LoadMUS("palestine.mp3");
	//..................
	//Lancer la musique avant la boucle du jeu
      	Mix_PlayMusic(musique,-1);
	//..................
      
      /* instructions f et g du workshop */

	while(quitter) 
	{
	// Activité 2 du workshop  Afficher l'image palestine.jpg
	SDL_BlitSurface(image,NULL,ecran,&posimage);//..................
	SDL_BlitSurface(texte,NULL,ecran,&posimage);//Lecture de l'événement	
	SDL_PollEvent(&event); 
	// Selon le type de l'événement
	switch (event.type)
         { 
        // exit if the window is closed
		case SDL_QUIT: quitter = 0;
        	break;
        //Lecture d'un événement par clavier
        		
       //Si on clique sur le bouton echap
           		
        	break;
        //lecture d'un événement clique bouton souris
         	    	
	 	break;
	 }
	//if(..........)
                {	//écriture du texte We Will NEVER forget \n We will NEVER stop sharing
		//..................
                //Affichage du texte 
               //..................
       		}

          SDL_Flip(ecran);//Refraichir l'écran
	//..................

	}
	
		//Fermeture des sous-systèmes audio et texte, libération de la mémoire des ressources images, texte et son.
	SDL_FreeSurface(image);
	Mix_FreeMusic(musique);
	Mix_CloseAudio();
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();
	return 0;

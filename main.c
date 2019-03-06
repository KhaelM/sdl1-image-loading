#include <SDL/SDL.h>
#include "function.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

int main(int argc, char const *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Error while initialising SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Load window
    SDL_Surface *icon = SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp");
    // Set window title
    SDL_WM_SetCaption("Display BMP", NULL);
    // Set window icon + transparency
    SDL_WM_SetIcon(icon, NULL);

    SDL_Surface *screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, Rich, SDL_HWSURFACE); 
    
    if(screen == NULL) {
        fprintf(stderr, "Error while setting Video Mode: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);   
    }

/// Background
    // Position
    int backgroundX = 0;
    int backgroundY = 0;
    SDL_Rect backgroundPosition = {backgroundX, backgroundY};    
    SDL_Surface *backgroundImg = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");

/// Character
    int characterX = 100;
    int characterY = 50;
    SDL_Rect characterPosition = {characterX, characterY};
    SDL_Surface *zozor = SDL_LoadBMP("pack_images_sdz/zozor.bmp");
    Uint32 blue = SDL_MapRGB(zozor->format, 0, 0, 255);
    // Apply TOTAL transparency on blue
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, blue);
    // Apply opacity on zozor (value range: 0 - 255)
    SDL_SetAlpha(zozor, SDL_SRCALPHA, 255);

/// Update window
    SDL_BlitSurface(backgroundImg, NULL, screen, &backgroundPosition);
    SDL_BlitSurface(zozor, NULL, screen, &characterPosition);
    SDL_Flip(screen);
    
    pause();
    
    SDL_FreeSurface(backgroundImg);
    SDL_Quit();

    return EXIT_SUCCESS;
}

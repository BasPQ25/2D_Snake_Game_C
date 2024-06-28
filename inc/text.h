#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL.h>


#define TEXT_SIZE_SCORE 120
#define TEXT_SIZE_POINTS 60


typedef struct TextParameters
{
    TTF_Font* Font;
    SDL_Surface* Surface;
    SDL_Texture* Texture;
}TextParameters;


int Initialize_Text_Configuration(TextParameters* Text_Score, int Text_Size,char text_to_print[]);

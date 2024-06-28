
#include"text.h"


TextParameters Text_Score = {.Font = NULL, .Surface = NULL, .Texture = NULL};
TextParameters* p_Text_Score = &Text_Score;

TextParameters Text_Points = {.Font = NULL, .Surface = NULL, .Texture = NULL};
TextParameters* p_Text_Points = &Text_Points;

//extern variables
extern SDL_Renderer* Renderer;


int  Initialize_Text_Configuration(TextParameters* Text_Score, int Text_Size,char text_to_print[])
{
    p_Text_Score->Font = TTF_OpenFont("/home/paul/Snake_Game_2D_C/Fonts/OpenSans-BoldItalic.ttf", Text_Size);
    if(p_Text_Score->Font == NULL)
    {
        fprintf(stderr,"Couldn't initialize Font\n");
        return 0;
    }
    p_Text_Score->Surface = TTF_RenderText_Blended_Wrapped(p_Text_Score->Font, text_to_print ,(SDL_Color){255,255,255,255}, 500);
    if(p_Text_Score->Surface == NULL)
    {
        fprintf(stderr,"Couldn't initialize Text surface\n");
        return 0;
    }

    p_Text_Score->Texture = SDL_CreateTextureFromSurface(Renderer, p_Text_Score->Surface);
    if(p_Text_Score->Texture == NULL)
    {
        fprintf(stderr,"Couldn't initialize Texture\n");
        return 0;
    }

    
    return 1;
}

#include"text.h"


TextParameters Text = {.Font = NULL, .Surface = NULL, .Texture = NULL};
TextParameters* p_Text = &Text;


//extern variables
extern SDL_Renderer* Renderer;


int  Initialize_Text_Configuration(TextParameters* p_Text, int Text_Size,char text_to_print[])
{
    p_Text->Font = TTF_OpenFont("/home/paul/Snake_Game_2D_C/Fonts/OpenSans-BoldItalic.ttf", Text_Size);
    if(p_Text->Font == NULL)
    {
        fprintf(stderr,"Couldn't initialize Font\n");
        return 0;
    }

    p_Text->Surface = TTF_RenderText_Blended_Wrapped(p_Text->Font, text_to_print ,(SDL_Color){255,255,255,255}, 2000);
    if(p_Text->Surface == NULL)
    {
        fprintf(stderr,"Couldn't initialize Text surface\n");
        return 0;
    }

    p_Text->Texture = SDL_CreateTextureFromSurface(Renderer, p_Text->Surface);
    if(p_Text->Texture == NULL)
    {
        fprintf(stderr,"Couldn't initialize Texture\n");
        return 0;
    }


    return 1;
}
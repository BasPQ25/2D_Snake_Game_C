#include"main.h"

int Only_once = 0;
int Only_once_2 = 0;
//extern variables
extern SDL_Renderer* Renderer ;

int Game_Lost  = FALSE;
extern int NumberOfTails;
extern Coordinates Snake_body[MAXIMUM_GENERATING_COINS];

extern TextParameters* p_Text;



void Check_If_Game_Lost(int Head_pozition_x , int Head_pozition_y , Coordinates Snake_Tails[MAXIMUM_GENERATING_COINS])
{
    //Sum with +- 20 so the Snake crashes with the walls..
    if( Head_pozition_x == (LOWER_BORDER_X - 20) || Head_pozition_x == (HIGHER_BORDER_X + 20) ||
        Head_pozition_y == (LOWER_BORDER_Y -20) || Head_pozition_y == (HIGHER_BORDER_Y + 20) )
    {
        Game_Lost = TRUE;
        
    }

    for(int i = 1; i <= NumberOfTails; i++)
    {
        if(Head_pozition_x == Snake_Tails[i].coord_x && Head_pozition_y == Snake_Tails[i].coord_y)
        {
            Game_Lost = TRUE;
        }
    }
}

void Pop_Screen_When_Lost()
{
    static char buffer[100];
    
    static int highScore = 0;

    FILE * fileText = fopen("highScore.txt", "r");
    if(!Only_once_2)
    {
        fscanf(fileText,"%d",&highScore);
        Only_once_2 = 1;
    }

   if(highScore < NumberOfTails)
    {
        if(!Only_once)
        {
            fclose(fileText);

            fileText = fopen("highScore.txt", "w");

            fprintf(fileText, "%d", NumberOfTails);
            
            Only_once = 1;
        }
        sprintf(buffer, " Game Over\nNew Best: %d\n", NumberOfTails);
        Initialize_Text_Configuration(p_Text,TEXT_GAME_LOST_SIZE,buffer);
        SDL_RenderCopy(Renderer, p_Text->Texture , NULL, &(SDL_Rect){400,200,p_Text->Surface->w,p_Text->Surface->h});
    }
    
    else
    {
        sprintf(buffer, " Game Over\n \tScore: %d\n", NumberOfTails);
        Initialize_Text_Configuration(p_Text,TEXT_GAME_LOST_SIZE,buffer);
        SDL_RenderCopy(Renderer, p_Text->Texture , NULL, &(SDL_Rect){400,200,p_Text->Surface->w,p_Text->Surface->h});
    }
    
    fclose(fileText);
}


#include"snake.h"
#include"coins.h"

Coordinates Snake_body[MAXIMUM_GENERATING_COINS];

//extern variables
extern Coordinates* Coord_Array[MAXIMUM_GENERATING_COINS];
extern int NumberOfCoinsSpawned;
extern SDL_Renderer* Renderer;


void Update_Snake_Head_Pozition(int Snake_pozition_x, int Snake_pozition_y)
{
    Snake_body[0].coord_x = Snake_pozition_x;
    Snake_body[0].coord_y = Snake_pozition_y;
}

void Eat_Coins_And_Grow_Tail(SDL_Rect Snake_body_parameters)
{
    static int NumberOfTails = 0;

    for(int i = 0 ; i < MAXIMUM_GENERATING_COINS; i++)
    {
        if(Coord_Array[i] == NULL) continue;

        if( Coord_Array[i]->coord_x - 5 <= Snake_body[0].coord_x && Snake_body[0].coord_x <= Coord_Array[i]->coord_x + 5 &&
            Coord_Array[i]->coord_y - 5 <= Snake_body[0].coord_y && Snake_body[0].coord_y <= Coord_Array[i]->coord_y + 5 )
        {

            free(Coord_Array[i]);
            Coord_Array[i] = NULL;
            
            NumberOfCoinsSpawned--;
            NumberOfTails++;
            

            break;
        }
    }
        
}

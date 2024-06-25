#include"coins.h"

extern SDL_Renderer* Renderer;
Coordinates Coord_Array[MAXIMUM_GENERATING_COINS];

void Initialize_Coord_array()
{
    for(int i = 0; i < MAXIMUM_GENERATING_COINS ; i++)
    {
        Coord_Array[i].coord_x = NULL;
        Coord_Array[i].coord_y = NULL;
    }
}

void DrawCoins(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // Horizontal offset
            int dy = radius - h; // Vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

int GenerateRandomNumbers(int Lower_Border, int Higher_Border)
{
    srand(time(NULL));

    int randomNumber;
    randomNumber = Lower_Border + rand() % (Higher_Border - Lower_Border + 1);

    return randomNumber;
}
void SpawnRandomCoins(int Lower_Border_X, int Higher_Border_X, int Lower_Border_Y, int Higher_Border_Y)
{   
    //check if empty;
    int i;
    for(i = 0; i < MAXIMUM_GENERATING_COINS; i++)
    {
        if( Coord_Array[i].coord_x == NULL && Coord_Array[i].coord_y == NULL )
        break;
    }

    //coordinates at fixed memory location 
    Coord_Array[i].coord_x = (int*)malloc(sizeof(int));
    *Coord_Array[i].coord_x = GenerateRandomNumbers(Lower_Border_X, Higher_Border_X);

    Coord_Array[i].coord_y = (int*)malloc(sizeof(int));
    *Coord_Array[i].coord_y = GenerateRandomNumbers(Lower_Border_Y, Higher_Border_Y);

    DrawCoins(Renderer,*Coord_Array[i].coord_x, *Coord_Array[i].coord_y, COINS_RADIUS);
}
#include"coins.h"

Coordinates* Coord_Array[MAXIMUM_GENERATING_COINS];
int NumberOfCoinsSpawned = 1;
//extern variables
extern SDL_Renderer* Renderer;

void Initialize_Coord_array()
{
    for(int i = 0; i < MAXIMUM_GENERATING_COINS ; i++)
    {
        Coord_Array[i] = NULL;
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
    int randomNumber;
    randomNumber = Lower_Border + rand() % (Higher_Border - Lower_Border + 1);

    return randomNumber;
}

void GenerateRandomCoordinates(int Lower_Border_X, int Higher_Border_X, int Lower_Border_Y, int Higher_Border_Y)
{
    if(NumberOfCoinsSpawned == MAXIMUM_GENERATING_COINS) return ; //do not generate  new coordinates


    //coordinates at fixed memory location
    int i = 0; 
    while(Coord_Array[i] !=NULL) i++;

    Coord_Array[i] = (Coordinates*)malloc(sizeof(Coordinates));
            
    Coord_Array[i]->coord_x = GenerateRandomNumbers(Lower_Border_X, Higher_Border_X);
    Coord_Array[i]->coord_y = GenerateRandomNumbers(Lower_Border_Y, Higher_Border_Y);
    
    NumberOfCoinsSpawned++;
}


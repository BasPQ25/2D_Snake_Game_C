#include<SDL2/SDL.h>
#include<time.h>
#include<math.h>

#define COINS_RADIUS 5

#define MAXIMUM_GENERATING_COINS 10

#define TIME_PASSED_TO_SPAWN_COIN 1 //in seconds

#define NOT_PASSED 1
#define PASSED 0

typedef struct 
{
    int* coord_x;
    int* coord_y;

}Coordinates;

void Initialize_Coord_array(void);
void GenerateRandomCoordinates(int Lower_Border_X, int Higher_Border_X, int Lower_Border_Y, int Higher_Border_Y);
void DrawCoins(SDL_Renderer* renderer, int centerX, int centerY, int radius);
int GenerateRandomNumbers(int Lower_Border, int Higher_Border);



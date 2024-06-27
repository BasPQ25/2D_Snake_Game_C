#include<SDL2/SDL.h>


#define MAXIMUM_TAILS 0xFFFF
void Update_Snake_Head_Pozition(int Snake_pozition_x, int Snake_pozition_y);
void Eat_Coins(SDL_Rect Snake_body_parameters);
void Update_Snake_Tails(void);
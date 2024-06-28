#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include"coins.h"
#include"snake.h"
#include"text.h"
#include<time.h>

#define FALSE 0
#define TRUE 1

#define WIDTH 1600  
#define LENGTH 1000

#define SNAKE_DISTANGE_TRAVELED 20
#define SNAKE_SPEED 30

#define LOWER_BORDER_X 200
#define HIGHER_BORDER_X 960

#define LOWER_BORDER_Y  100
#define HIGHER_BORDER_Y 860



typedef struct
{   
    float x;
    float y;
    float width;
    float height;  
}Objects;


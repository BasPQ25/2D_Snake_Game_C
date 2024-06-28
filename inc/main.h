#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<time.h>

#include"coins.h"
#include"snake.h"
#include"text.h"
#include"lost.h"

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

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1




typedef struct
{   
    int x;
    int y;
    int width;
    int height;  
}Objects;


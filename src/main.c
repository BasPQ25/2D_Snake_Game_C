#include<stdio.h>
#include<SDL2/SDL.h>
#include"constants.h"

int game_is_running = FALSE;

SDL_Window* Window = NULL;
SDL_Renderer* Renderer = NULL;

int last_frame_time = 0;

int move_x = 1;
int move_y = 1;

typedef struct
{   
    float x;
    float y;
    float width;
    float height;
}Snake_body;

Snake_body Snake;

int  Init_Window(void)
{
    if( SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr,"Couldn't initialize SDL\n");
        return FALSE;
    }

    Window = SDL_CreateWindow( "Snake Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH,  LENGTH, SDL_WINDOW_BORDERLESS);
    if(!Window)
    {
        fprintf(stderr,"Couldn't initialize Window\n");
        return FALSE;
    }

    Renderer = SDL_CreateRenderer(Window,-1,0);
    if(!Renderer)
    {
        fprintf(stderr,"Couldn't initialize Renderer");
        return FALSE;
    }

    return TRUE;

}
void destroy_window(void)
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
void process_input()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            game_is_running = FALSE;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    game_is_running = FALSE;
                    break;

                case SDLK_UP:
                    move_y = -1;
                    break;
                
                case SDLK_DOWN:
                    move_y = 1;
                    break;
                
                case SDLK_RIGHT:
                    move_x = 1;
                    break;
                
                case SDLK_LEFT:
                    move_x = -1;
                    break;

                default:
                    
            }

            
    }
    
}
void update()
{
    float delta_time = ( SDL_GetTicks() - last_frame_time) / 1000.0f;
    
    last_frame_time = SDL_GetTicks();

    Snake.x += move_x * 40 * delta_time; 
    Snake.y += move_y * 20 * delta_time;
}
void setup()
{
    Snake.x = 100;
    Snake.y = 100;
    Snake.width = 20;
    Snake.height = 20;
}
void render()
{
    SDL_SetRenderDrawColor( Renderer, 0 , 0 , 0 , 255);
    SDL_RenderClear(Renderer);

    //Drawing

    SDL_Rect Snake_Body ={ Snake.x , Snake.y , Snake.width , Snake.height };
    
    SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 ); //white
    SDL_RenderFillRect( Renderer , &Snake_Body);

    SDL_RenderPresent(Renderer);
}

int main()
{
    game_is_running = Init_Window();

    setup();

    while(game_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;

}
#include"main.h"

int game_is_running = FALSE;

SDL_Window* Window = NULL;
SDL_Renderer* Renderer = NULL;


//local variables
float last_frame_time_coins = 0;

//Snake moving direction
int move_x = 0;
int move_y = 0;
//Objects
Objects Snake;
Objects Limits[4] = { {.x = 160, .y = 80, .width = 840, .height = -20} ,
                        {.x = 980, .y = 80, .width = 20, .height = 820} ,
                        {.x = 980, .y = 880, .width = -820, .height = 20} ,
                        {.x = 180, .y = 880, .width = -20, .height = -800} };
//Flags for Switching the game state
int Stop_generating_Coins = FALSE;

//extern Variables
extern Coordinates* Coord_Array[MAXIMUM_GENERATING_COINS];
extern int NumberOfCoinsSpawned;
extern Coordinates Snake_body[MAXIMUM_GENERATING_COINS];
extern int NumberOfTails;

extern TextParameters* p_Text;

extern int Game_Lost;

char Points_Text[100] = {"Score:\n"};

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


    TTF_Init();

    sprintf(Points_Text, "Score:\n  \t%d", NumberOfTails);

    if(!Initialize_Text_Configuration(p_Text, TEXT_SIZE_SCORE , Points_Text) )
        return FALSE;

    return TRUE;

}
void setup()
{   
    //Snake Initial Coordinates and size
    Snake.x = 400;
    Snake.y = 400;
    Snake.width = 20;
    Snake.height = 20;
    
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
                    destroy_window();
                    game_is_running = FALSE;
                    
                    break;

                case SDLK_UP:
                    if(move_y != DOWN)
                    {
                        move_y = UP;
                        move_x = 0;
                    }
                    break;
                
                case SDLK_DOWN:
                   if(move_y != UP)
                   {
                        move_y = DOWN;
                        move_x = 0;
                   }
                    break;
                
                case SDLK_RIGHT:
                    if(move_x != LEFT)
                    {
                        move_x = RIGHT;
                        move_y = 0;
                    }
                    break;
                
                case SDLK_LEFT:
                    if(move_x != RIGHT)
                    {
                        move_x = LEFT;
                        move_y = 0;
                    }
                    break;
                //Enter key
                case SDLK_RETURN:
                    //Reset states to Initial
                    setup();
                    move_x = 0;
                    move_y = 0;
                    Game_Lost = FALSE;
                    NumberOfTails = 0;

                    //initial score 
                    sprintf(Points_Text, "Score:\n \t%d", NumberOfTails);
                    Initialize_Text_Configuration(p_Text,TEXT_SIZE_SCORE,Points_Text);
                default:
                    
            }
    }   
}
void update()
{
    //Moving direction and Snake Speeds
    static int last_frame_time = 0;

    int delta_time = ( SDL_GetTicks() - last_frame_time);
    if(delta_time > SNAKE_SPEED) //miliseconds
    {
        last_frame_time = SDL_GetTicks();
    
        Update_Snake_Tails();

        Snake.x += move_x * SNAKE_DISTANGE_TRAVELED; //20 pixels/ms
        Snake.y += move_y * SNAKE_DISTANGE_TRAVELED;
    
        Update_Snake_Head_Pozition(Snake.x, Snake.y);

        //If the snake crashes with the wall the game is lost        
        Check_If_Game_Lost(Snake.x,Snake.y,Snake_body);
    }

}
void render()
{
    //Window Color
    SDL_SetRenderDrawColor( Renderer, 0 , 0 , 0 , 255);
    SDL_RenderClear(Renderer);

    //Drawing Limits
    if(!Game_Lost)
    {
        for(int i = 0; i < 4; i++)
        {
            SDL_Rect Limits_Rect = {Limits[i].x, Limits[i].y, Limits[i].width, Limits[i].height};
            SDL_SetRenderDrawColor( Renderer, 255 , 0 , 0 , 255); //red
            SDL_RenderFillRect(Renderer, &Limits_Rect);
        }

        //Drawing Snake head
        SDL_Rect Snake_Body ={ Snake.x , Snake.y , Snake.width , Snake.height };
        Draw_Snake_Head(Renderer,Snake_Body);

        //Draw Snake Tails
        SDL_Rect Snake_Tails ={ Snake.x , Snake.y , Snake.width , Snake.height};
        Drawing_Snake_Tail(Renderer, Snake_Tails, Snake_body);

        //Generating Coins Coordinates;
        float delta_time_coins = ( SDL_GetTicks() - last_frame_time_coins) / 1000.0f;

        if(delta_time_coins >= TIME_PASSED_TO_SPAWN_COIN) 
        {
            GenerateRandomCoordinates(LOWER_BORDER_X, HIGHER_BORDER_X , LOWER_BORDER_Y ,  HIGHER_BORDER_Y);

            last_frame_time_coins = SDL_GetTicks();
        }
    
        //Spawning random Coins
        for(int i = 0; i < MAXIMUM_GENERATING_COINS ; i++)
        {
            if(Coord_Array[i] == NULL) continue;

            SDL_SetRenderDrawColor(Renderer, 255 , 255 , 0 , 255 ); //yellow
            DrawCoins(Renderer, Coord_Array[i]->coord_x, Coord_Array[i]->coord_y , COINS_RADIUS);
        }

        //Game Logic
        Eat_Coins(Snake_Body);

        //Game Text For Score: Points 
        static int PointsSwitchChecker = 0;

        if(PointsSwitchChecker < NumberOfTails)
        {
            sprintf(Points_Text, "Score:\n \t%d", NumberOfTails);
            Initialize_Text_Configuration(p_Text,TEXT_SIZE_SCORE,Points_Text);
            PointsSwitchChecker++;
        }

        SDL_RenderCopy(Renderer, p_Text->Texture , NULL, &(SDL_Rect){1110,100,p_Text->Surface->w,p_Text->Surface->h});
    }
    else
    {
        Pop_Screen_When_Lost();
    }
    //Present on Window
    SDL_RenderPresent(Renderer);
}

int main()
{
        SDL_RenderClear(Renderer);

        //initializa all the coins coordinates at 0;
        void Initialize_Coord_array();

        //initialize start timer for random numbers generations
        srand(time(NULL));

        //if TRUE game is running, if false game is ending
        game_is_running = Init_Window();

        setup();

        //game running infinite loop
        while(game_is_running)
        {
            process_input();
            update();
            render();
        }
    return 0;

}
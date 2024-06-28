#include"main.h"

extern int move_x;
extern int move_y;

extern int NumberOfTails;



void Draw_Snake_Head(SDL_Renderer* Renderer, SDL_Rect Snake_Body)
{
    SDL_SetRenderDrawColor(Renderer, 128, 0, 128, 255);
    SDL_RenderFillRect( Renderer , &Snake_Body);
    
    if( move_y == UP)
    {
        DrawCoins(Renderer, Snake_Body.x + 10 , Snake_Body.y , 10);
        SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 2, Snake_Body.y , 6);
        DrawCoins(Renderer, Snake_Body.x + 18, Snake_Body.y , 6);

        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 2, Snake_Body.y , 3);
        DrawCoins(Renderer, Snake_Body.x + 18, Snake_Body.y , 3);
    }
    else if( move_y  == DOWN )
    {
        DrawCoins(Renderer, Snake_Body.x + 10, Snake_Body.y + 20, 10);
        SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 2, Snake_Body.y + 20, 6);
        DrawCoins(Renderer, Snake_Body.x + 18, Snake_Body.y + 20, 6);
        
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 2, Snake_Body.y + 20, 3);
        DrawCoins(Renderer, Snake_Body.x + 18, Snake_Body.y + 20, 3);
        
    }
    else if( move_x == LEFT)
    {
        DrawCoins(Renderer, Snake_Body.x , Snake_Body.y + 10, 10);
        SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 );
        DrawCoins(Renderer, Snake_Body.x, Snake_Body.y + 2, 6);
        DrawCoins(Renderer, Snake_Body.x , Snake_Body.y + 18, 6);

        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255 );
        DrawCoins(Renderer, Snake_Body.x , Snake_Body.y + 2, 3);
        DrawCoins(Renderer, Snake_Body.x, Snake_Body.y + 18, 3);
    }
    else if( move_x == RIGHT)
    {
        DrawCoins(Renderer, Snake_Body.x + 20 , Snake_Body.y + 10, 10);
        SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 20, Snake_Body.y + 2, 6);
        DrawCoins(Renderer, Snake_Body.x + 20, Snake_Body.y + 18, 6);

        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255 );
        DrawCoins(Renderer, Snake_Body.x + 20, Snake_Body.y + 2, 3);
        DrawCoins(Renderer, Snake_Body.x + 20, Snake_Body.y + 18, 3);
    }
}

void Drawing_Snake_Tail(SDL_Renderer* Renderer, SDL_Rect Snake_Tails, Coordinates* Snake_body)
{
   
   // static int Variable_Tail_Color = 128;
    //static int Variable_Tail_Color_2 = 0;
    //static int Variable_Tail_Color_3 = 128;
    
    for(int i = 1; i <= NumberOfTails; i++)
        {
            Snake_Tails.x = Snake_body[i].coord_x;  
            Snake_Tails.y = Snake_body[i].coord_y;
            /*
            if(Variable_Tail_Color > 0)
            {
                Variable_Tail_Color -= 3*i;
            }
            else if(Variable_Tail_Color_3 > 0)
            {
                Variable_Tail_Color_2 -= 5*i;
            }
            else if( Variable_Tail_Color_2 > 0)
            {
                Variable_Tail_Color_2 += 5*i;
            }
            */
            
            SDL_SetRenderDrawColor(Renderer, 128 , 0 , 128 , 255 ); 
            SDL_RenderFillRect( Renderer , &Snake_Tails);
            
            SDL_SetRenderDrawColor(Renderer, 255 , 255 , 255 , 255 );
            SDL_RenderDrawLine(Renderer , Snake_Tails.x ,Snake_Tails.y ,Snake_Tails.x + Snake_Tails.w , Snake_Tails.y + Snake_Tails.h );
        }
}
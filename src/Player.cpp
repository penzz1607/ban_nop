#include "Player.h"

bool Box::cham(int minx, int miny, int max_x, int maxy)
    {
        if(x>=minx && y>=miny && x<=max_x && y<=maxy) return false;
        else return true;
    }
void Box::render(SDL_Renderer *renderer)
    {
        SDL_Texture* hinh;
        if(huong<0)
        {
              hinh = load_image("assets/pd.png",renderer);
        }
        else  hinh = load_image("assets/player.png",renderer);
        SDL_Rect sun;
        sun.x=x;
        sun.y=y;
        sun.w=30;
        sun.h=30;
        SDL_RenderCopy(renderer, hinh, NULL, &sun);
        SDL_DestroyTexture(hinh);
    }
void Box::move()
    {
        y+=huong;
        if(y<=0)        y=450;
        else if(y>=450) y=0;
    }
void Box::change()
    {
        huong*=-1;
    }

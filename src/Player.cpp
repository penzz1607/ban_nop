#include "Player.h"
void Box::render(SDL_Renderer* renderer)
{
    SDL_Texture* player;
    if(huong<0){
        player= load_image("assets/player.png",renderer);
    }
    else player= load_image("assets/pd.png",renderer);
    //if (player != NULL) cout <<"yes";
    SDL_Rect hcn;
    hcn.x = x;
    hcn.y = y;
    hcn.h = 30;
    hcn.w = 30;
    SDL_RenderCopy(renderer , player, NULL, &hcn);
    SDL_DestroyTexture(player);
    }
bool Box:: inside(int minx, int miny, int maxx, int maxy){
    return (minx<=x&&miny<=y&& x+30<=maxx&&y+30<=maxy);
    }
bool Box::cham (int min_x, int min_y, int max_x, int max_y){
    if (x>=min_x&&x<=max_x&&y>=min_y&&y<=max_y){
            return false;
    }
    else return true;
}
// lấy ý tưởng của hàm bool inside Trần Thị Minh Châu
void Box::move()
{
    y += huong;
    if(y<=0) y=SCREEN_HEIGHT-30;
    else if((y+30)>=SCREEN_HEIGHT) y=0;
}
void Box::change(){
    huong=huong*-1;
}

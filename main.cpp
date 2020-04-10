//// thu vien////
#include"SDL_utils.h"

using namespace std;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "chay test ngay 1!";
const int fps=100/60;
// /////het bien toan cuc
struct Box{
    int xpos;
    int ypos;
    int size=25;
    int huongx=0, huongy=0;
    Box (int x , int y)  {
        xpos=x;
        ypos=y;
    }
    //// ham in box len man hinh////
    void render(SDL_Renderer* renderer){
        SDL_Rect hcn;
        hcn.x=xpos;
        hcn.y=ypos;
        hcn.w=size;
        hcn.h=size;
        SDL_SetRenderDrawColor(renderer, 0,255,0,255);// vang
        SDL_RenderFillRect(renderer, &hcn);
    }
    void move(){
        xpos+=huongx;
        ypos+=huongy;
    }
    void moveleft(){
        huongx=-5;
        huongy=0;
    }
    void moveright(){
        huongx=5;
        huongy=0;
    }
    void moveup(){
        huongy=-5;
        huongx=0;
    }
    void movedown(){
        huongy=5;
        huongx=0;
    }
    bool inside(int minx, int miny, int maxx, int maxy){
        return (minx<=xpos&&miny<=ypos&& xpos+size<=maxx&&ypos+size<=maxy);
    }
};

///////////main//////////
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT,WINDOW_TITLE);

    // tao hinh chu nhat
    Box box(20,20);

    SDL_Event e;
    //SDL_SetRenderDrawColor(renderer, 255,255,255,255);// white
    //SDL_RenderClear(renderer);
    while(box.inside(0,0,SCREEN_WIDTH, SCREEN_HEIGHT)){
        box.move();
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);// white
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay( fps);

        if(SDL_PollEvent(&e)==0) continue;
        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
            case SDLK_ESCAPE: break;
            case SDLK_LEFT: box.moveleft(); break;
            case SDLK_RIGHT: box.moveright(); break;
            case SDLK_UP: box.moveup(); break;
            case SDLK_DOWN: box.movedown(); break;
            default: break;
            }
        }

    }

    //waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

//////////main//////////



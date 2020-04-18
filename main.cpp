#include "SDL_utils.h"
using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;
const string title = " chay ngay 9! ";

const int fps=100/70;
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
bool initSDL();
SDL_Texture* load_image(string file_path);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

struct sun {
    int x; int y;
    sun(int _x, int _y){
    x=_x;
    y=_y;
    }
    sun(){}
    void move(){
        x-=5;
        if(x<=0){
            x=350;
            int a=0;
            while(a<=70||a>=500){
                a=rand()%SCREEN_HEIGHT;
            }
            y=a;
            cout<<a<<endl;
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/mario.png");
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=50;
        su.h=50;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
    }
};

struct Box{
    int x;
    double y;
    Box (){};
    Box (int _x,double _y)
    {
        x = _x;
        y = _y;
    }
    int way=5;
    void render(SDL_Renderer* renderer)
    {
        SDL_Texture* player = load_image("assets/player.png");
        //if (player != NULL) cout <<"yes";
        SDL_Rect hcn;
        hcn.x = x;
        hcn.y = y;
        hcn.h = 40;
        hcn.w = 40;

        SDL_RenderCopy(renderer , player, NULL, &hcn);
    }
    bool inside(int minx, int miny, int maxx, int maxy){
        return (minx<=x&&miny<=y&& x+40<=maxx&&y+40<=maxy);
    }
    void move()
    {
        y += way;
    }
    void jump(){
        way*=-1;
    }

};


// main //


int main(int argc, char* argv[])
{

    if (initSDL() == false) return 0;

    SDL_RenderClear(renderer);
    SDL_Texture* texture = NULL;
    texture = load_image("assets/bg.png");
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    SDL_Event e;
    // khai báo biến

    Box box(100,SCREEN_HEIGHT/2-15);

//    sun su(350,100);

    // game chạy

    while (box.inside(0,0,SCREEN_WIDTH, SCREEN_HEIGHT))
    {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);// white
    SDL_RenderClear(renderer);

    SDL_Texture* tex = NULL;
    tex = load_image("assets/bg.png");
    SDL_RenderCopy(renderer , tex, NULL, NULL);
    SDL_DestroyTexture(tex);
    // render


     box.render(renderer);
//     su.render(renderer);
//     si.render(renderer);
 //    ray.render(renderer);




    // move
//    ray.move();
    box.move();
//    su.move();
//    si.move();
    SDL_RenderPresent(renderer);
    SDL_Delay(fps);
    if(SDL_PollEvent(&e)==0) continue;
        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
            case SDLK_ESCAPE:   quitSDL(window, renderer); break;
            case SDLK_SPACE:    box.jump() ; break;
            default: break;
            }

        }
    }

    quitSDL(window, renderer);
    return 0;
}







SDL_Texture* load_image(string file_path)

{
    SDL_Surface* loadImage = NULL;
    SDL_Texture* tex = NULL;
    loadImage = IMG_Load(file_path.c_str());
    if(loadImage != NULL)
    {
        tex = SDL_CreateTextureFromSurface(renderer, loadImage);
        SDL_FreeSurface(loadImage);

    }
    return tex;
}
bool initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Error Init";
        return false;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        cout << "Error Create window";
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        cout << "Error Create renderer";
        return false;
    }

    return true;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

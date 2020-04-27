#include "SDL_utils.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const string title = " chay ngay 13! ";



SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
bool initSDL();
SDL_Texture* load_image(string file_path);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
// cột dọc nửa trên màn hình
struct Sun1 {
    int x; int y;
    Sun1(int _x, int _y){
    x=_x;
    y=_y;
    }
    Sun1(){}
    void move(){
        x-=5;
        if(x<=-65){
            x=900;
            int b=200;
            while(b>=200){
                b=rand()%200;
            }
            y=b;
          //  cout<<"1: "<<b<<" ";
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot1.png");
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=40;
        su.h=90;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
    }
};
// cột ngang
struct Sun2 {
    int x; int y;
    Sun2(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move(){
        x-=5;
        if(x<=-200){
            x=1200;
            int a=0;
            while(a<=50){
                a=rand()%350 ;
            }
            y=a;
         //   cout<<"2: "<<a<<" ";
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot2.png");
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=200;
        su.h=50;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
    }
};
// cột dọc nửa dưới màn hình
struct Sun3 {
    int x; int y;
    Sun3(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move(){
        x-=5;
        if (x<=-40){
            x=1000;
            int a=0;
            while (a<=200){
                a=rand()% 300;
            }
            y=a;
           // cout<<"3: "<<a<<endl;
        }

    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot1.png");
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=40;
        su.h=90;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
    }
};
struct Box{
    int x;
    int y;

    Box (int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    int huong=-5;
    void render(SDL_Renderer* renderer)
    {
        SDL_Texture* player = load_image("assets/player.png");
        //if (player != NULL) cout <<"yes";
        SDL_Rect hcn;
        hcn.x = x;
        hcn.y = y;
        hcn.h = 30;
        hcn.w = 30;

        SDL_RenderCopy(renderer , player, NULL, &hcn);
    }

    bool inside(int minx, int miny, int maxx, int maxy){
        return (minx<=x&&miny<=y&& x+30<=maxx&&y+30<=maxy);
    }
    // kiểm tra xem có cham Sun hay không
    bool cham (int min_x, int min_y, int max_x, int max_y){
        if (x>=min_x&&x<=max_x&&y>=min_y&&y<=max_y){
                return false;
        }
        else return true;
    }
    void move()
    {
        y += huong;
    }
    void change(){
       huong=huong*-1;
    }

};


// main //


int main(int argc, char* argv[])
{

    if (initSDL() == false) return 0;

    SDL_RenderClear(renderer);
    SDL_Texture* texture = NULL;
    texture = load_image("assets/backg.png");
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    SDL_Event e;
    // khai báo biến

    Box box(70,200);
    Sun1 cot1(600, 200);
    Sun3 cot3(800, 350);
    Sun2 cot2(900, 260);

    // game chạy
    int score=0;
//    int fps=10;
    while (box.inside(0,0,SCREEN_WIDTH, SCREEN_HEIGHT))
    {
    score+=1; cout<<score<<endl;
    // dieu kien cham cot1
    if(box.cham(cot1.x, cot1.y, cot1.x+34, cot1.y+80)==false){
        break;
    }

// dieu kien cham cot2

    if(box.cham(cot2.x, cot2.y, cot2.x+200, cot2.y+42)==false){
        break;
    }
// dieu kien cham cot3
    if(box.cham(cot3.x, cot3.y, cot3.x+34, cot3.y+80)==false){
        break;
    }

    SDL_RenderClear(renderer);
    SDL_Texture* tex = NULL;
    tex = load_image("assets/backg.png");
    SDL_RenderCopy(renderer , tex, NULL, NULL);
    SDL_DestroyTexture(tex);
    // render


     box.render(renderer);
     cot1.render(renderer);
     cot2.render(renderer);
     cot3.render(renderer);



    // game play
    box.move();
    cot1.move();
    cot2.move();
    cot3.move();
    SDL_RenderPresent(renderer);


    //SDL_Delay(0);


    if(SDL_PollEvent(&e)==0) continue;
        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
            case SDLK_ESCAPE:   quitSDL(window, renderer); break;
            case SDLK_SPACE:    box.change() ; break;
            default: break;
            }

        }
    }
    SDL_RenderClear(renderer);
    // chay sau khi kết thúc game
    texture = load_image("assets/end.png");
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_Texture * wasted =load_image("assets/wasted.png");
    SDL_Rect wa ;
    wa.x=0; wa.y=0;
    wa.w=800; wa.h=450;
    SDL_RenderCopy(renderer, wasted, NULL, &wa);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();
    SDL_RenderClear(renderer);
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

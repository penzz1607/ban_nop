#include "SDL_utils.h"
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
SDL_Texture* texture = NULL;
TTF_Font *font = NULL;
SDL_Surface* surface = NULL;
// cột dọc nửa trên màn hình
struct Sun1 {
    int x; int y;
    Sun1(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move(){
        x-=10;
        if(x<=-65){
            x=900;
            int b=110;
            while(b>=110){
                b=rand()%110;
            }
            y=b;
          //  cout<<"1: "<<b<<" ";
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot1.png",renderer);
        SDL_Rect sun;
        sun.x=x;
        sun.y=y;
        sun.w=40;
        sun.h=90;
        SDL_RenderCopy(renderer, hinh, NULL, &sun);
        SDL_DestroyTexture(hinh);
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
        x-=13;
        if (x<=-40){
            x=1000;
            int a=0;
            while (a<=200){
                a=rand()% 300;
            }
            y=a;
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot1Red.png",renderer);
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=40;
        su.h=90;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
        SDL_DestroyTexture(hinh);
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
        x-=10;
        if(x<=-200){
            x=1200;
            int a=0;
            while(a<=50){
                a=rand()%400 ;
            }
            y=a;
         //   cout<<"2: "<<a<<" ";
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_Texture* hinh = load_image("assets/cot2.png",renderer);
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=200;
        su.h=50;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
        SDL_DestroyTexture(hinh);
    }
};
// người chơi
struct Box{
    int x;
    int y;
    Box (int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    int huong=-7;
    void render(SDL_Renderer* renderer)
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
        if(y<=0) y=SCREEN_HEIGHT-30;
        else if((y+30)>=SCREEN_HEIGHT) y=0;
    }
    void change(){
       huong=huong*-1;
    }
};
struct Boss
{
    int x; int y;
    Boss(int _x, int _y): x(_x), y(_y) {};
    void run (){
        x-=35;
        if(x<=-1){
            x=30000;
            int a=3;
            while (a>=3){
                a=rand()% 2;
            }
            y=a*250;
        }
    }
    void render(SDL_Renderer *renderer){
        SDL_Texture* hinh = load_image("assets/pow1.png",renderer);
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=200;
        su.h=200;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
        SDL_DestroyTexture(hinh);
    }
};
struct Warn{
    int x; int y;
    Warn(){}
    void see(SDL_Renderer *renderer){
        SDL_Texture* hinh = load_image("assets/warn.png",renderer);
        SDL_Rect su;
        su.x=x;
        su.y=y;
        su.w=60;
        su.h=60;
        SDL_RenderCopy(renderer, hinh, NULL, &su);
        SDL_DestroyTexture(hinh);
    }
};
struct Text{
    string word;
    int x;
    int y;
    int dai;
    Text (int _x, int _y, string _word, int _dai){
        x=_x;
        y=_y;
        word=_word;
        dai=_dai;
    }
    void render (SDL_Renderer* renderer, TTF_Font* font){
       SDL_Color col ={243, 156, 18 ,255};
       SDL_Rect chu;
       chu.x = x;
       chu.y = y;
       chu.w = dai;
       chu.h = 30;
       SDL_Surface *sur = TTF_RenderText_Solid(font, word.c_str(),col);
       SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, sur);
       SDL_RenderCopy(renderer, tex, NULL, &chu);
       SDL_FreeSurface(sur);
       SDL_DestroyTexture(tex);
    }
};
// main //
int main(int argc, char* argv[])
{
    initSDL(window, renderer);
    SDL_Event e;
    // tạo init ttf
    if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return -1;
	}
    font=TTF_OpenFont("assets/font.ttf",500);
    texture = load_image("assets/begin.png",renderer);
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();
    // khai báo biến
    int score =0;
    Box box(97,200);
    Sun1 cot1(600, 200);
    Sun3 cot3(800, 350);
    Sun2 cot2(900, 260);
    Boss pow(1,19000);
    Warn warn;
    // game chạy
    bool running= true;
    while (running)
    {   score ++;
    SDL_DestroyTexture(texture);
    // dieu kien cham cot1
    if(box.cham(cot1.x, cot1.y, cot1.x+36, cot1.y+88)==false){
        break;
    }
//  dieu kien cham cot2
    if(box.cham(cot2.x, cot2.y, cot2.x+200, cot2.y+47)==false){
        break;
    }
// dieu kien cham cot3
    if(box.cham(cot3.x, cot3.y, cot3.x+36, cot3.y+88)==false){
        break;
    }
    if(box.cham(pow.x, pow.y, pow.x+195, pow.y+190)==false){
        break;
    }
// */
    SDL_RenderClear(renderer);
    texture = load_image("assets/bg.png",renderer);
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    // render
    box.render(renderer);
    // render csore
    int diemcnt =score/10;
    string diem=to_string(diemcnt);
    int k=diem.length();
    Text diem_so(705,0,diem,k*15);
    diem_so.render(renderer, font);

    if(pow.x<=3000)
    {
        warn.x=700;
        warn.y=pow.y+50;
        warn.see(renderer);
        pow.render(renderer);
        cot1.x=-30;
        cot2.x=-200;
        cot3.x=-30;

    }
    else{
        cot1.render(renderer);
        cot2.render(renderer);
        cot3.render(renderer);

    }
    // game play
    box.move();
    cot1.move();
    cot2.move();
    cot3.move();
    pow.run();
    SDL_RenderPresent(renderer);
    if(SDL_PollEvent(&e)==0) continue;
        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
            case SDLK_ESCAPE:   running=false; break;
            case SDLK_SPACE:    box.change() ; break;
            default: break;
            }
        }
    SDL_RenderClear(renderer);
    }
    //waitUntilKeyPressed();
    SDL_RenderClear(renderer);
    // chay sau khi kết thúc game
    texture = load_image("assets/end.png",renderer);
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    // hiển thị điểm
    score/=10;
    string word_for_gud_bye=" Your score: ";
    string diem=to_string(score);
    string finaly=word_for_gud_bye+diem;
    int k=finaly.length();
    Text diem_so(455,420,finaly,k*15);
    diem_so.render(renderer, font);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();
    SDL_Delay(1500);
    SDL_RenderClear(renderer);
    quitSDL(window, renderer, texture);
    return 0;
}

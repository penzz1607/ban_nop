#include <SDL_utils.h>
#include <Player.h>
#include <Enemy.h>
#include <Inuse.h>
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
SDL_Texture* texture = NULL;
TTF_Font *font = NULL;
SDL_Surface* surface = NULL;
int main(int argc, char* argv[])
{
    initSDL(window, renderer);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_VolumeMusic(25);
    SDL_Event e;

    // tạo init ttf copy từ trang
    //www.stdio.vn/articles/draw-text-trong-sdl-308
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

    Box box(100,400);
    Sun1 cot1(600, 200);
    Sun3 cot3(800, 350);
    Sun2 cot2(900, 260);
    Boss pow(1,19000);
    Warn warn;
    // game chạy
    int kt=2;
while(true)
{
    bool running= true;
    backgrmusic();
    int score =0;
    while (running)
    {   score ++;

    SDL_DestroyTexture(texture);
    // dieu kien cham cot1
   if(box.cham(cot1.x, cot1.y, cot1.x+36, cot1.y+85)==false){
        Mix_HaltMusic();
       effectmusic("assets/effect_sound.mp3");
        break;
        }
////  dieu kien cham cot2
    if(box.cham(cot2.x, cot2.y, cot2.x+195, cot2.y+38)==false){
        Mix_HaltMusic();
        effectmusic("assets/effect_sound.mp3");
        break;
    }
//// dieu kien cham cot3
    if(box.cham(cot3.x, cot3.y, cot3.x+36, cot3.y+85)==false){
        Mix_HaltMusic();
       effectmusic("assets/effect_sound.mp3");
        break;
    }
    if(box.cham(pow.x, pow.y, pow.x+195, pow.y+195)==false){
        Mix_HaltMusic();
        effectmusic("assets/effect_sound.mp3");
        break;
    }
    SDL_RenderClear(renderer);
    texture = load_image("assets/bg.png",renderer);
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    // render
    box.render(renderer);
    // in điểm trong game
    int diemcnt =score/10;
    string diem=to_string(diemcnt);
    int k=diem.length();
    Text diem_so(705,0,diem,k*15);
    diem_so.render(renderer, font);
    // xuất hiện boss to
    if(pow.x==3050) effectmusic("assets/nani.mp3");
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
            case SDLK_SPACE:    box.change() ; break;
            case SDLK_p: waitUntilKeyPressed(); break; // ấn p để pause game
            default: break;
            }
        }
    SDL_RenderClear(renderer);
    }
    // chay sau khi kết thúc game
    texture = load_image("assets/end.png",renderer);
    SDL_RenderCopy(renderer , texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    // hiển thị điểm
    score/=10;
    string word_for_gud_bye1=" Your score: ";
    string diem=to_string(score);
    string smile=" =)";
    string finaly=word_for_gud_bye1+diem+smile;
    int k=finaly.length();
    Text diem_so(455,420,finaly,k*15);
    diem_so.render(renderer, font);
    SDL_RenderPresent(renderer);
    int a=kt_play(kt);
    if(a!=0) break;
    // set lại cacsi vị chí
        box.y=400;
        box.huong=-7;
        cot1.x=-30;
        cot2.x=-200;
        cot3.x=-30;
        pow.x=-120;
    SDL_Delay(1000);
    SDL_RenderClear(renderer);
}
    quitSDL(window, renderer, texture);
    return 0;
}

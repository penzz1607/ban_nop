#include "Enemy.h"

void Sun1::move(){
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
void Sun1::render(SDL_Renderer* renderer){
    SDL_Texture* hinh = load_image("assets/cot1.png",renderer);
    SDL_Rect sun;
    sun.x=x;
    sun.y=y;
    sun.w=40;
    sun.h=90;
    SDL_RenderCopy(renderer, hinh, NULL, &sun);
    SDL_DestroyTexture(hinh);
}
void Sun3::move(){
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
void Sun3::render(SDL_Renderer* renderer){
    SDL_Texture* hinh = load_image("assets/cot1Red.png",renderer);
    SDL_Rect su;
    su.x=x;
    su.y=y;
    su.w=40;
    su.h=90;
    SDL_RenderCopy(renderer, hinh, NULL, &su);
    SDL_DestroyTexture(hinh);
}
void Sun2::move(){
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
void Sun2::render(SDL_Renderer* renderer){
    SDL_Texture* hinh = load_image("assets/cot2.png",renderer);
    SDL_Rect su;
    su.x=x;
    su.y=y;
    su.w=200;
    su.h=50;
    SDL_RenderCopy(renderer, hinh, NULL, &su);
    SDL_DestroyTexture(hinh);
}
void Boss::run (){
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
void Boss::render(SDL_Renderer *renderer){
    SDL_Texture* hinh = load_image("assets/pow1.png",renderer);
    SDL_Rect su;
    su.x=x;
    su.y=y;
    su.w=200;
    su.h=200;
    SDL_RenderCopy(renderer, hinh, NULL, &su);
    SDL_DestroyTexture(hinh);
}
void Warn::see(SDL_Renderer *renderer){
    SDL_Texture* hinh = load_image("assets/warn.png",renderer);
    SDL_Rect su;
    su.x=x;
    su.y=y;
    su.w=60;
    su.h=60;
    SDL_RenderCopy(renderer, hinh, NULL, &su);
    SDL_DestroyTexture(hinh);
}


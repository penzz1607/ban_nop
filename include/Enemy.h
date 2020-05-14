#ifndef ENEMY_H
#define ENEMY_H
#include <SDL_utils.h>
struct Sun1 {
    int x; int y;
    Sun1(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move();
    void render(SDL_Renderer* renderer);
};
// cột dọc nửa dưới màn hình
struct Sun3 {
    int x; int y;
    Sun3(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move();
    void render(SDL_Renderer* renderer);
};
// cột ngang
struct Sun2 {
    int x; int y;
    Sun2(int _x, int _y){
    x=_x;
    y=_y;
    }
    void move();
    void render(SDL_Renderer* renderer);
};
struct Boss
{
    int x; int y;
    Boss(int _x, int _y): x(_x), y(_y) {};
    void run ();
    void render(SDL_Renderer *renderer);
};
struct Warn{
    int x; int y;
    Warn(){}
    void see(SDL_Renderer *renderer);
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
    void render (SDL_Renderer* renderer, TTF_Font* font);
};
#endif // ENEMY_H

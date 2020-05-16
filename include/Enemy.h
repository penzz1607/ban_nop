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
// người chơi

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


#endif // ENEMY_H

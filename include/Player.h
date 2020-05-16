#ifndef PLAYER_H
#define PLAYER_H
#include <SDL_utils.h>

struct Box
{
    int x;
    int y;
    int huong=-7;
    Box(int _x,int _y):x(_x),y(_y){};
    bool cham(int minx, int miny, int max_x, int maxy);
    void render(SDL_Renderer *renderer);
    void move();
    void change();
};

#endif // PLAYER_H

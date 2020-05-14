#ifndef PLAYER_H
#define PLAYER_H
#include <SDL_utils.h>

struct Box{
    int x;
    int y;
    Box (int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    int huong=-7;
    void render(SDL_Renderer* renderer);
    bool inside(int minx, int miny, int maxx, int maxy);
    // kiểm tra xem có cham Sun hay không như thuật toán cửa cô Châu cho
    bool cham (int min_x, int min_y, int max_x, int max_y);
    void move();
    void change();
};

#endif // PLAYER_H

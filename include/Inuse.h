#include <SDL_utils.h>
void effectmusic(string a);
void backgrmusic();
int kt_play(int kt);
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

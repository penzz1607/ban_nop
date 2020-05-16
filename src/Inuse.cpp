#include <Inuse.h>
int kt_play(int kt1)
{
    int kt= kt1;
    SDL_Event c;
    while(true)
    {
        if(SDL_WaitEvent(&c)!=0)
        {
            if(c.type == SDL_QUIT||c.key.keysym.sym==27) { kt++; break;}// nhấn phím éc để thoát hoặc tắt cửa sổ
            if(c.key.keysym.sym==114) { kt=0; break; }// nhấn phím r để chơi lại
        }
    }
    return kt;
}
void backgrmusic(){
    Mix_Music* backgrmusic = NULL;
    backgrmusic = Mix_LoadMUS( "assets/bgmusic.mp3" );
    Mix_PlayMusic(backgrmusic,-1);
    // chạy nhạc vô tận
}
void effectmusic(string a){
    Mix_Chunk* effect = NULL;
    effect = Mix_LoadWAV( a.c_str() );
    Mix_PlayChannel(-1,effect,0);
}
void Text::render (SDL_Renderer* renderer, TTF_Font* font){
       SDL_Color col ={0,245,200,255};
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

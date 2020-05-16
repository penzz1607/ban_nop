#include <SDL_utils.h>
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

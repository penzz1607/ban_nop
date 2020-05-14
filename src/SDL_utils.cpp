#include "SDL_utils.h"
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
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
void quitSDL(SDL_Window* window, SDL_Renderer* renderer,
             SDL_Texture * texture)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
SDL_Texture* load_image(string file_path, SDL_Renderer* renderer)
{
    SDL_Surface* loadImage= NULL;
    SDL_Texture* tex= NULL;
    loadImage= IMG_Load(file_path.c_str());
    if( loadImage != NULL )
    {
        tex = SDL_CreateTextureFromSurface(renderer, loadImage);
        SDL_FreeSurface(loadImage);
    }
    return tex;
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

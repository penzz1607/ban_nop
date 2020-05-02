#ifndef SDL_UTILS__H
#define SDL_UTILS__H


#include <iostream>
#include <SDL.h>
#include <cmath>
#include <SDL_image.h>
#include <SDL_ttf.h>


using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const string WINDOW_TITLE = " GAME 4 FUN ";
SDL_Texture* load_image(string file_path, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture * texture);

void waitUntilKeyPressed();
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
#endif // SDL_UTILS__H

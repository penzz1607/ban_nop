#ifndef SDL_UTILS__H
#define SDL_UTILS__H


#include <iostream>
#include <SDL.h>

using namespace std;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
             const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const string & WINDOW_TITLE);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
#endif // SDL_UTILS__H

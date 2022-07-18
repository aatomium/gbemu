#include <SDL2/SDL.h>
SDL_Color bgcolor;
SDL_Window* window;
SDL_Renderer* renderer;
int usrQuit(SDL_Event* event);
int create_window();
void drawBmp(char* binary,int x,int y);
void render();

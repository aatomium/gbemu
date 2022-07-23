#include <SDL2/SDL.h>
extern SDL_Color bgcolor;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
int testQuit(SDL_Event* event);
int usrQuit();
int create_window();
void drawBmp(char* binary,int x,int y);
void render();

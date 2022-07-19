#include <SDL2/SDL.h>
extern SDL_Color bgcolor;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
int usrQuit(SDL_Event* event);
int create_window();
void drawBmp(char* binary,int x,int y);
void render();

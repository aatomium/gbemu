#include <SDL2/SDL.h>
#include "gui.h"
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Color bgcolor = {224, 255, 208, 255};
void setIcon(){
	SDL_Surface* iconSurface;
        iconSurface = SDL_LoadBMP("icon.bmp");
        SDL_SetWindowIcon(window, iconSurface);

}
int usrQuit(SDL_Event* event){
        if(SDL_PollEvent(event)){
                if(event->type == SDL_QUIT){
                        return 1;
                }
        }
        return 0;
}


int create_window()
{
    window = SDL_CreateWindow("GBEmulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 576, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    setIcon();
    SDL_SetRenderDrawColor(renderer, 224, 255, 208, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return EXIT_SUCCESS;
}
void drawPixel(int x,int y){
	for(int w=0;w<4;w++){
		for(int q=0;q<4;q++){
			SDL_RenderDrawPoint(renderer, q+x, w+y);
                }
       }


}
void drawBmp(char* binary,int x,int y){
    int z=0;
    for (int i=y; i<y+8*4; i=i+4)
	for(int j=x;j<x+8*4;j=j+4){
		switch(binary[z])
		{
			case '1':
				SDL_SetRenderDrawColor(renderer, 136, 192, 112, 255);
				drawPixel(j,i);
				break;
			case '2':
				SDL_SetRenderDrawColor(renderer, 52, 104, 86, 255);
				drawPixel(j,i);
				break;
			case '3':
				SDL_SetRenderDrawColor(renderer, 8, 24, 32, 255);
				drawPixel(j,i);
				break;
		}
		z++;
    	}
}
void render(){
	SDL_RenderPresent(renderer);
}

#include <SDL2/SDL.h>
#include "gui.h"

SDL_Color bgcolor = {224, 255, 208, 255};

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
    SDL_SetRenderDrawColor(renderer, 224, 255, 208, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    return EXIT_SUCCESS;
}

void drawBmp(char* binary,int x,int y){
    int z=0;
    for (int i=y; i < y+16*4; i=i+4)
	for(int j=x;j<x+16*4;j=j+4){
	        if(binary[z]=='1'){
			for(int w=0;w<4;w++){
				for(int q=0;q<4;q++){
					SDL_RenderDrawPoint(renderer, q+j, w+i);
				}
			}
		}
		z++;
    	}
}
void render(){
	SDL_RenderPresent(renderer);
}

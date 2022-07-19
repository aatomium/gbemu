#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "cpu.h"
#include <SDL2/SDL.h>
#include "gui.h"
#include "utils.h"
int main()
{
    char name[16];
    uint8_t* memory = open_file("pokemon.gb");
    getRomName(memory,name);
    printf("Title of ROM : %s\n",name);
    printf("Content of register A : %i\n",registers.a);
    uint8_t hexChar[16] = {0x3C,0x00,0x42,0x00,0xB9,0x00,0xA5,0x00,0xB9,0x00,0xA5,0x00,0x42,0x00,0x3C,0x00};
    char character[128];
    getBmp(hexChar,character);
    create_window();
    drawBmp(character,35,0);
    drawBmp(character,0,0);
    render();
    SDL_Event quit;
    while(!usrQuit(&quit)){}
    free_rom(memory);
    return 0;
};

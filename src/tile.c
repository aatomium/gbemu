#include "tile.h"
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

void drawTile(uint8_t* memory,int number,int x,int y){
        uint16_t adress = 0x8000+number*16;
        uint8_t array[16];
        get16Bytes(memory,adress,array);
        char tile[64];
        getBmp(array,tile);
        drawBmp(tile,x,y);

}
void drawVram(uint8_t* memory){
    int j=0;
    int k=0;
    for(int i=0x9800;i<0x9A33;i++){
            drawTile(memory,memory[i],j,k);
            j=j+32;
            if(j==1024){
                k=k+32;
                j=0;
            }
    }
}




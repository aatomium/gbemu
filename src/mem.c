#include "mem.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
uint8_t* open_file(char* filename){
    FILE * fp = fopen (filename,"rb");
    uint8_t* memory = NULL;
    if(fp != NULL){
        size_t size = 0x7FFF;
        memory = malloc(0xFFFF);
        if(memory != NULL){
                memset(memory,0,0xFFFF);
                fread(memory, size, 1, fp);
        }
        fclose(fp);
    }
    return memory;
}
void free_rom(uint8_t* rom){
        free(rom);
}
void getRomName(uint8_t* rom,char* name){
    if(rom && name){
        int j=0;
        for(int i=0x134;i<0x143;i++){
           name[j++] = rom[i];
        }
        name[j]=0;
    }
}


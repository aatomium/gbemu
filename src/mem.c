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
void insertData(uint8_t* memory,uint16_t adress,uint8_t data[],int size){
        int k=0;
        for(uint16_t i=adress;i<adress+size;i++){
                memory[i] = data[k];
                k++;

        }

}

void get16Bytes(uint8_t* memory,uint16_t adress,uint8_t array[]){
        for(int i=0;i<16;i++){
                array[i] = memory[adress+i];
        }
}

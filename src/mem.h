#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t* open_file(char* filename);
void free_rom(uint8_t* rom);
void getRomName(uint8_t* rom,char* name);
void insertData(uint8_t* memory,uint16_t adress,uint8_t data[],int size);
void get16Bytes(uint8_t* memory,uint16_t adress,uint8_t array[]);

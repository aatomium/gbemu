#include "utils.h"
bool getBit(uint8_t value,int index){
        index = 7-index;
        return ((value & ( 1 << index )) >> index);
}
void getBinary(uint8_t value,char* finalString){
    for(int k=0;k<=7;k++){
        bool test = getBit(value,k);
        if(test){
            finalString[k] = '1';
        }
        else{
            finalString[k] = '0';
        }
    };
    finalString[8] = 0;
}
void getBmp(uint8_t hex[],char* character){
    char convert[9];
    int k=0;
    for(int i=0;i<16;i=i+2){
        getBinary(hex[i],convert);
        for(int j=0;j<8;j++){
                character[k+j] = convert[j];
	}
        k=k+8;
    }
    character[64]=0;
}

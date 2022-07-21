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
    char image1[9];
    char image2[9];
    int k=0;
    for(int i=0;i<16;i=i+2){
        getBinary(hex[i],image1);
	getBinary(hex[i+1],image2);
        for(int j=0;j<8;j++){
		if(image1[j]=='0' && image2[j]=='0'){
	                character[k+j] = '0';
		}
		else if (image2[j]=='1' && image1[j]=='0'){
			character[k+j]='1';
		}
		else if(image1[j]=='1' && image2[j]=='0'){
			character[k+j]='2';
		}
		else if(image1[j]=='1' && image2[j]=='1'){
			character[k+j]='3';
		}
	}
        k=k+8;
    }
    character[64]=0;
}

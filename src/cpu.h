#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
struct reg {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t h;
        uint8_t l;
        uint16_t sp;
        uint16_t pc;
}; extern struct reg registers;
struct flag {
	bool cy;
	bool h;
	bool nz;
	bool z;
}; extern struct flag flags;

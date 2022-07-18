#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
struct reg {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t h;
        uint8_t l;
        uint8_t sp;
        uint8_t pc;
}; extern struct reg registers;

#include "cpu.h"
struct reg registers = {
	0, //a
	0, //b
	0, //c
	0, //d
	0, //e
	0, //h
	0, //l
	0, //sp
	0  //pc
};
struct flag flags = {
	0, //cy
	0, //h
	0, //nz
	0  //z
};

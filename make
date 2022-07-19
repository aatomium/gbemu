gcc src/main.c src/mem.c src/cpu.c src/gui.c src/utils.c src/tile.c -Wall -g -o emu `sdl2-config --cflags --libs`
./emu

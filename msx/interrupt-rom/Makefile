LIBSRC = ../../libsrc
INCLUDE = -I../../include

# main target objs
MAIN_OBJS = main.o  hocuspocus.o $(LIBSRC)/arkos2_c_stubs_simple.o $(LIBSRC)/asm_arkos2_msx_rom.o

# targets
.PHONY: build clean

build: $(MAIN_OBJS)
	zcc +msx -subtype=rom -compiler=sdcc -vn $(INCLUDE) -m -s --list -create-app -o arkos $(MAIN_OBJS)

%.o: %.c
	zcc +msx  -vn $(INCLUDE) -compiler=sdcc -c -s --list $*.c

%.o: %.asm
	zcc +msx -vn $(INCLUDE) -compiler=sdcc -c -s --list $*.asm

clean:
	@-rm *.lis *.bin *.tap *.o *.sym *.map *.save arkos *.rom 2>/dev/null

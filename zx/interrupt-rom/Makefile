LIBSRC = ../../libsrc
INCLUDE = -I../../include

# main target objs
MAIN_OBJS = main.o  hocuspocus.o $(LIBSRC)/arkos2_c_stubs_simple.o $(LIBSRC)/asm_arkos2_zx_ram.o

# targets
.PHONY: build clean

build: $(MAIN_OBJS)
	zcc +zx -vn $(INCLUDE) -m -s --list -compiler=sdcc -clib=sdcc_iy -create-app -o arkos $(MAIN_OBJS)

%.o: %.c
	zcc +zx -vn $(INCLUDE) -c -s --list -compiler=sdcc -clib=sdcc_iy $*.c

%.o: %.asm
	zcc +zx -vn $(INCLUDE) -c -s --list -compiler=sdcc -clib=sdcc_iy $*.asm

clean:
	@-rm *.lis *.bin *.tap *.o *.sym $(ARKOS_ASM) $(PASMO_ASM) $(Z88DK_ASM) *.map *.save arkos 2>/dev/null

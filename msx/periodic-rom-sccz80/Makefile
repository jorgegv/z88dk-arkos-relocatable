LIBSRC = ../../libsrc

# main target objs
MAIN_OBJS = main.o hocuspocus.o $(LIBSRC)/arkos2_c_stubs_simple.o $(LIBSRC)/asm_arkos2_msx_rom.o

# targets
.PHONY: build clean

build: $(MAIN_OBJS)
	zcc +msx -subtype=rom -vn -m -s --list -create-app -o arkos $(MAIN_OBJS)

%.o: %.c
	zcc +msx -vn -c -s --list $*.c

%.o: %.asm
	zcc +msx -vn -c -s --list $*.asm

clean:
	@-rm *.lis *.bin *.tap *.o *.sym $(ARKOS_ASM) $(PASMO_ASM) $(Z88DK_ASM) *.map *.save arkos *.rom 2>/dev/null

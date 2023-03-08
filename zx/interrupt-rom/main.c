#include <intrinsic.h>
#include <stdint.h>
#include <im2.h>
#include <string.h>
#include <z80.h>

#include <arkos.h>

extern uint8_t song[];

#define IV_ADDR		( ( unsigned char * ) 0xD000 )
#define ISR_ADDR	( ( unsigned char * ) 0xD1D1 )
#define IV_BYTE		( 0xD1 )
#define Z80_OPCODE_JP	( 0xc3 )

IM2_DEFINE_ISR(service_interrupt)
{
        (*(uint8_t *)0x4000)++;	// show something on screen
        ply_akg_play();
}

void init_interrupts( void ) {
    intrinsic_di();
    memset( IV_ADDR, IV_BYTE, 257);
    z80_bpoke( ISR_ADDR, Z80_OPCODE_JP );
    z80_wpoke( ISR_ADDR + 1, (uint16_t) service_interrupt );
    im2_init( IV_ADDR );
    intrinsic_ei();
}


void main( void ) {
    ply_akg_init( song, 0 );
    init_interrupts();
    while ( 1 ) {
        (*(uint8_t *)0x4020)++;	// show something on screen
                                // music playback should happen in interrupt context
    }
}

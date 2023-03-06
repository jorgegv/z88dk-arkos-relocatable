#include <intrinsic.h>
#include <stdint.h>
#include <im2.h>
#include <string.h>
#include <msx.h>

// Arkos C prototypes
void ply_akg_init( void *song, unsigned int subsong ) __z88dk_callee;
void ply_akg_play( void );
void ply_akg_stop( void );
void ply_akg_initsoundeffects( void *effects_table ) __z88dk_fastcall;
void _ply_akg_playsoundeffect( unsigned int effect ) __z88dk_fastcall;

extern uint8_t song[];

#define Z80_OPCODE_JP	0xc3
#define MSX_H_TIMI	0xfd9f

void service_interrupt( void )
{
        (*(uint8_t *)0x4000)++;	// show something on screen
        ply_akg_play();
}

void init_interrupts( void ) {
    intrinsic_di();
    add_raster_int( service_interrupt );
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

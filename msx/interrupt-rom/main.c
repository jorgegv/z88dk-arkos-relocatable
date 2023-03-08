#include <intrinsic.h>
#include <stdint.h>
#include <interrupt.h>
#include <string.h>
#include <msx.h>

#include <arkos.h>

extern uint8_t song[];

void service_interrupt( void )
{
        (*(uint8_t *)0x4000)++;	// show something on screen
        ply_akg_play();
}

void init_interrupts( void ) {
    intrinsic_di();
    im1_init();
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

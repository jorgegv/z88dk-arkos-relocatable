#include <intrinsic.h>
#include <stdint.h>
#include <interrupt.h>
#include <string.h>
#include <msx.h>

// Arkos C prototypes
void ply_akg_init( void *song, unsigned int subsong ) __z88dk_callee;
void ply_akg_play( void );
void ply_akg_stop( void );
void ply_akg_initsoundeffects( void *effects_table ) __z88dk_fastcall;
void _ply_akg_playsoundeffect( unsigned int effect ) __z88dk_fastcall;

extern uint8_t song[];

#define ARKOS_VARS_BUFFER_SIZE 269
uint8_t arkos_var_buffer[ ARKOS_VARS_BUFFER_SIZE ];

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

#ifndef _ARKOS_H
#define _ARKOS_H

// Arkos C prototypes
void ply_akg_init( void *song, unsigned int subsong ) __z88dk_callee __smallc;
void ply_akg_play( void );
void ply_akg_stop( void );
void ply_akg_initsoundeffects( void *effects_table ) __z88dk_fastcall;
void ply_akg_playsoundeffect( unsigned int effect ) __z88dk_fastcall;

#endif // _ARKOS_H

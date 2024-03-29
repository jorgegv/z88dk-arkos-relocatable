;;
;; C stubs for Arkos invocation from zcc
;;

section code_compiler

;; public C symbols
PUBLIC _ply_akg_init
PUBLIC _ply_akg_play
PUBLIC _ply_akg_stop
PUBLIC _ply_akg_initsoundeffects
PUBLIC _ply_akg_playsoundeffect

;; external Arkos 2 entry points
EXTERN PLY_AKG_INIT
EXTERN PLY_AKG_INITSOUNDEFFECTS
EXTERN PLY_AKG_PLAY
EXTERN PLY_AKG_PLAYSOUNDEFFECT
EXTERN PLY_AKG_STOP


;;
;; void ply_akg_init( void *song, uint8_t subsong ) __z88dk_callee __smallc;
;;   (params pushed on the stack left to right, all 16-bit)
;;
_ply_akg_init:
	pop bc		; BC = retaddr
	pop de		; E = subsong number
	pop hl		; HL = song address
	ld a,e		; A = subsong number
	push bc		; restore retaddr
	jp PLY_AKG_INIT

;;
;; void ply_akg_play( void );
;;
defc _ply_akg_play = PLY_AKG_PLAY

;;
;; void ply_akg_stop( void );
;;
defc _ply_akg_stop = PLY_AKG_STOP


;;
;; void ply_akg_initsoundeffects( void *effects_table ) __z88dk_fastcall;
;;   (param in HL)
;;
defc _ply_akg_initsoundeffects = PLY_AKG_INITSOUNDEFFECTS


;;;
;; void ply_akg_playsoundeffect( uint16_t effect, uint16_t channel, uint16_t inv_volume ) __z88dk_callee __smallc;
;;   (params pushed on the stack left to right, all 16-bit)
;;
_ply_akg_playsoundeffect:
        pop hl          ; HL = retaddr

        pop bc
        ld b,c          ; B = inv volume
        pop de
        ld c,e          ; C = num channel
        pop de
        ld a,e          ; A = sound effect number

        push hl         ; restore retaddr
        jp PLY_AKG_PLAYSOUNDEFFECT

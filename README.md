# z88dk-arkos-relocatable

Tests, demo code and tools for running Arkos Tracker 2 from Z88DK code
without using a forced compilation address

* Directory `zx`: test and demo code for ZX spectrum

* Directory `msx`: test and demo code for MSX

* Directory `libsrc`: Z88DK asm sources for ZX and MSX players, C stubs

* Directory `include`: header file with Arkos player C function prototypes

* Directory `support`: special tool and Makefile for creating the
  relocatable Z88DK Arkos Player sources from original player asm sources.

* Directory `tests`: special tests that ensure that the original player
  sources and the ones processed for being relocatable generate exactly the
  same code when compiled, byte by byte.

And inside `zx` and `msx` directories (where applicable):

* Directory `periodic`: relocatable Arkos test without using IM2 mode

* Directory `periodic-rom`: relocatable Arkos test without using IM2 mode
  and player configured in ROM mode (no SMC, with RAM buffer)

* Directory `interrupt`: relocatable Arkos test using IM2 mode

* Directory `interrupt-rom`: relocatable Arkos test using IM2 mode and
  player configured in ROM mode (no SMC, with RAM buffer)

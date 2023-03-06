# z88dk-arkos-relocatable
Tests for running Arkos Tracker 2 from Z88DK code without using a forced compilation address

* Directory `zx`: test and demo code for ZX spectrum
* Directory `msx`: test and demo code for MSX

Inside those:

* Directory `periodic`: relocatable Arkos test without using IM2 mode
* Directory `interrupt`: relocatable Arkos test using IM2 mode
* Directory `interrupt-rom`: relocatable Arkos test using IM2 mode and
  player configured in ROM mode (no SMC, with RAM buffer)

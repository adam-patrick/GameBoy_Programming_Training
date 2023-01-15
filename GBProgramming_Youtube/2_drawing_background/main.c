#include <gb/gb.h>
#include <gb/cgb.h>
#include "LaroldsJubilantJunkyard.h"

void main()
{
    DISPLAY_ON;

    SHOW_BKG;
    // Use HIDE_BKG; to turn background off

    // Load & set our background data
    set_bkg_data(0,178,LaroldsJubilantJunkyard_data);

    // The gameboy screen is 160px wide by 144px tall
    // We deal with tiles that are 8px wide and 8px tall
    // 160/8 = 20, 144/8 = 18
    set_bkg_tiles(0,0,20,18,LaroldsJubilantJunkyard_map_plane0);

    // The "LaroldsJubilantJunkyard_pallette" color palette is defined in LaroldsJubilantJunkyard.c
    set_bkg_palette(0,1,LaroldsJubilantJunkyard_pallette);

    // Switch to bank 1 for writing background tile attributes.
    VBK_REG=1;
    set_bkg_tiles(0,0,20,18,LaroldsJubilantJunkyard_map_plane1);

    // Switch back to bank 0 to prevent accidentally writing to bank 1
    VBK_REG=0;
}
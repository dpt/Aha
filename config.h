/* config.h */

#ifndef CONFIG_H
#define CONFIG_H

#define MAXNEG 0x80000000
#define MAXPOS 0x7FFFFFFF
#define NBSM 31                 // Shift mask.  Use 63 for mod 64
                                // shifts, or 31 for mod 32.
#define TRIAL {1, 0, -1, \
               MAXNEG, MAXPOS, MAXNEG + 1, MAXPOS - 1, \
               0x01234567, 0x89ABCDEF, -2, 2, -3, 3, -64, 64, -5, -31415, \
               0x0000FFFF, 0xFFFF0000, \
               0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000, \
               0x0000000F, 0x000000F0, 0x00000F00, 0x0000F000, \
               0x000F0000, 0x00F00000, 0x0F000000, 0xF0000000}

// First three values of IMMEDS must be 0, -1, and 1.
#define IMMEDS 0, -1, 1, -2, 2, MAXNEG
#define SHIMMEDS 1, 2, 3, 30, 31

#endif /* CONFIG_H */


/* avg.frag.c */

#define NARGS 2                 // Number of args in userfun, 1 or 2.

#include "aha.h"

int userfun(int x, int y) {     // To find Dietz's formula for
                                // the floor-average of two
                                // unsigned integers.
   return ((unsigned long long)x + (unsigned long long)y) >> 1;
}

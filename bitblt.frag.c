/* bitblt.frag.c */
/* bitmap plotting type ops: (dst & ~mask) | (src & mask) */

#define NARGS 3

#include "aha.h"

int userfun(int dst, int src, int mask)
{
  return (dst & ~mask) | (src & mask);
}

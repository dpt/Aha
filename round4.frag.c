/* round4.frag.c */
/* ops to yield (x + 2) & ~3 */

#include "aha.h"

int userfun(int x)
{
  return (x + 2) & ~3;
}

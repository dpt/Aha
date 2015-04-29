// artificial.frag.c
//
// Artificial example input for Aha! from my blog post
// http://www.davespace.co.uk/blog/20150131-branchless-sequences.html

#include "aha.h"

int userfun(int x)
{
  if (x == 0)
      return 1;
  else if (x == 1)
      return 2;
  else
      return 0;
}

/* simulator.c */

/* Collection of simulator routines for the instructions in the isa. */

#include "config.h"

#include "simulator.h"

extern int unacceptable;

int neg(int x, int y, int z) {return -x;}
int _not(int x, int y, int z) {return ~x;}
int pop(int xx, int y, int z) {
   unsigned x = xx;
   x = x - ((x >> 1) & 0x55555555);
   x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
   x = (x + (x >> 4)) & 0x0F0F0F0F;
   x = x + (x << 8);
   x = x + (x << 16);
   return x >> 24;
}

int nlz(int xx, int y, int z) {
   unsigned x = xx;
   int n;

   if (x == 0) return(32);
   n = 0;
   if (x <= 0x0000FFFF) {n = n +16; x = x <<16;}
   if (x <= 0x00FFFFFF) {n = n + 8; x = x << 8;}
   if (x <= 0x0FFFFFFF) {n = n + 4; x = x << 4;}
   if (x <= 0x3FFFFFFF) {n = n + 2; x = x << 2;}
   if (x <= 0x7FFFFFFF) {n = n + 1;}
   return n;
}

int rev(int xi, int y, int z) {
   unsigned x = xi;
   x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
   x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
   x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
   x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
   return x;
}

int revb(int xi, int y, int z) {
   unsigned x = xi;
   return ((x & 0x000000FF) << 24) | ((x >> 24) & 0x000000FF) |
          ((x & 0x0000FF00) <<  8) | ((x >>  8) & 0x0000FF00);
}


int add (int x, int y, int z) {return x + y;}
int sub (int x, int y, int z) {return x - y;}
int rsb (int x, int y, int z) {return y - x;}
int mul (int x, int y, int z) {return x * y;}
/* For division overflow we return arbitrary values, hoping they fail
to be part of a solution.  (User must check solutions, in general.) */
int _div (int x, int y, int z) {
   if (y == 0 || (y == -1 && x == (int)0x80000000))
      {unacceptable = 1; return 0;}
   else return x/y;}
int _divu(int x, int y, int z) {
   if (y == 0) {unacceptable = 1; return 0;}
   else return (unsigned)x/(unsigned)y;}
int _mod (int x, int y, int z) {
   if (y == 0 || (y == -1 && x == (int)0x80000000))
      {unacceptable = 1; return 0;}
   else return x%y;}
int _modu(int x, int y, int z) {
   if (y == 0) {unacceptable = 1; return 0;}
   else return (unsigned)x%(unsigned)y;}
int _and(int x, int y, int z) {return x & y;}
int _or (int x, int y, int z) {return x | y;}
int _xor(int x, int y, int z) {return x ^ y;}
int _bic(int x, int y, int z) {return x & ~y;}
int rotl(int x, int y, int z) {int s = y & NBSM;
   return x << s | (unsigned)x >> (32 - s);}
int rotr(int x, int y, int z) {int s = y & NBSM;
   return x << (32 - s) | (unsigned)x >> s;}
int shl(int x, int y, int z) {int s = y & NBSM;
   if (s >= 32) return 0; else return x << s;}
int shr(int x, int y, int z) {int s = y & NBSM;
   if (s >= 32) return 0; else return (unsigned)x >> s;}
int shrs(int x, int y, int z) {int s = y & NBSM;
   if (s >= 32) return x >> 31; else return x >> s;}
int cmpeq(int x, int y, int z) {return x == y;}
int cmplt(int x, int y, int z) {return x < y;}
int cmpltu(int x, int y, int z) {return (unsigned)(x) < (unsigned)(y);}
int seleq(int x, int y, int z) {return x == 0 ? y : z;}
int sellt(int x, int y, int z) {return x < 0 ? y : z;}
int selle(int x, int y, int z) {return x <= 0 ? y : z;}


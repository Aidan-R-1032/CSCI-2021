/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

int test_minusOne(void) {
  return -1;
}

int test_thirdBits(void) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i+=3)
    result |= 1<<i;
  return result;
}

int test_byteSwap(int x, int n, int m) {
    /* little endiamachine */
    /* least significant byte stored first */
    unsigned int nmask, mmask;
    switch(n) {
    case 0:
      nmask = x & 0xFF;
      x &= 0xFFFFFF00;
      break;
    case 1:
      nmask = (x & 0xFF00) >> 8;
      x &= 0xFFFF00FF;
      break;
    case 2:
      nmask = (x & 0xFF0000) >> 16;
      x &= 0xFF00FFFF;
      break;
    default:
      nmask = ((unsigned int)(x & 0xFF000000)) >> 24;
      x &= 0x00FFFFFF;
      break;
    }
    switch(m) {
    case 0:
      mmask = x & 0xFF;
      x &= 0xFFFFFF00;
      break;
    case 1:
      mmask = (x & 0xFF00) >> 8;
      x &= 0xFFFF00FF;
      break;
    case 2:
      mmask = (x & 0xFF0000) >> 16;
      x &= 0xFF00FFFF;
      break;
    default:
      mmask = ((unsigned int)(x & 0xFF000000)) >> 24;
      x &= 0x00FFFFFF;
      break;
    }
    nmask <<= 8*m;
    mmask <<= 8*n;
    return x | nmask | mmask;
}

int test_copyLSB(int x) {
  return (x & 0x1) ? -1 : 0;
}

int test_isPositive(int x) {
  return x > 0;
}

unsigned test_floatNegate(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}

int test_anyEvenBit(int x) {
  int i;
  for (i = 0; i < 32; i+=2)
      if (x & (1<<i))
   return 1;
  return 0;
}

int test_isAsciiDigit(int x) {
  return (0x30 <= x) && (x <= 0x39);
}

int test_floatIsLess(unsigned uf, unsigned ug) {
    float f = u2f(uf);
    float g = u2f(ug);
    return f < g;
}

int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}

int test_greatestBitPos(int x) {
    unsigned mask = 1<<31;
    if (x == 0)
 return 0;
    while (!(mask & x)) {
 mask = mask >> 1;
    }
    return mask;
}

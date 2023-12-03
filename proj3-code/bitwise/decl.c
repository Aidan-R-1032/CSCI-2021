// DO NOT MODIFY THIS FILE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits_test.h"
#include "message_tags.h"

test_rec test_set[] = {
 {"minusOne", (funct_t) test_minusOne, MINUS_ONE_TAG, 0,
    "! ~ & ^ | + << >>", 2, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"thirdBits", (funct_t) test_thirdBits, THIRD_BITS_TAG, 0,
    "! ~ & ^ | + << >>", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{"byteSwap", (funct_t) test_byteSwap, BYTE_SWAP_TAG, 3,
     "! ~ & ^ | + << >>", 25, 2,
    {{TMin, TMax},{0,3},{0,3}}},
 {"copyLSB", (funct_t) test_copyLSB, COPY_LSB_TAG, 1,
    "! ~ & ^ | + << >>", 5, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isPositive", (funct_t) test_isPositive, IS_POSITIVE_TAG,1,
    "! ~ & ^ | + << >>", 8, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"floatNegate", (funct_t) test_floatNegate, FLOAT_NEGATE_TAG,1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"anyEvenBit", (funct_t) test_anyEvenBit, ANY_EVEN_BIT_TAG,1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isAsciiDigit", (funct_t) test_isAsciiDigit, IS_ASCII_DIGIT_TAG, 1,
    "! ~ & ^ | + << >>", 15, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"floatIsLess", (funct_t) test_floatIsLess, FLOAT_IS_LESS_TAG, 2,
    "$", 30, 3,
     {{-1, -1},{-1,-1},{-1,-1}}},
 {"logicalShift", (funct_t) test_logicalShift, LOGICAL_SHIFT_TAG,
   2, "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{0,31},{TMin,TMax}}},
 {"greatestBitPos", (funct_t) test_greatestBitPos, GREATEST_BIT_POS_TAG, 1,
 "! ~ & ^ | + << >>", 70, 4, {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"", NULL, 0, 0, "", 0, 0, {{0,0}, {0,0}, {0,0}}} // Apparently we need this as a sentinel value
};
// DO NOT MODIFY THIS FILE

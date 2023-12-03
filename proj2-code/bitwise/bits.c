/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this part of the project by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;

    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting if the shift amount
is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the spec) to
check the legality of your solutions.
2. Each function has a maximum number of operations (integer, logical,
or comparison) that you are allowed to use for your implementation
of the function.  The max operator count is checked by dlc.
Note that assignment ('=') is not counted; you may use as many of
these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to verify that your solutions produce
 *      the correct answers.
 */
#endif

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2 
 *   Rating: 1
 */
int minusOne(void) {
    return ~0;
}

/*
 * thirdBits - return int with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {//0x49249249
    return (0x49 << 24) | (0x24 << 16) | (0x92 << 8) | 0x49;
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int n_mask = (0xFF << (n << 3) & x);//gets the nth byte of x (location remains the same)
    int m_mask = (0xFF << (m << 3) & x);//^
    int open = x & (~(n_mask | m_mask));//clears the nth and mth bytes of x
    n_mask = (n_mask>>(n<<3))<<(m<<3);//shifts the location to where it needs to be
    m_mask = (m_mask >>(m<<3))<<(n<<3);//^
    n_mask = n_mask & (0xFF << (m << 3));//sets the bytes infront of the nth one to 0
    m_mask = m_mask & (0xFF << (n << 3));//^
    return (open | n_mask | m_mask); 
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    int least_sig_bit = 0x01 & x;//gets least signigicant bits
    return ((least_sig_bit<<31) >> 31);//shifts left then performs an arithmetic right shift (sets all bits to 0's or 1's)
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
    int most_sig = (x & (1<<31));//gets the most significant bit- indicator of positive/zero or negative
    int indicator = most_sig | !x; // 0 if x is positive, or 0x10000000 if x is negative, and 0x00000001 if x is zero   
    return !indicator;//only returns 1 if indicator is 0; otherwise returns 1
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    int firstbit = (0x80000000 & uf);
    int mask = uf - firstbit;
    int exponent = (0x7F800000 & uf);
    int mantissa = mask - exponent;
    if(((exponent == 0x7F800000) && (mantissa != 0)))
    {
        return uf;
    }
    if(firstbit == 0x80000000){
        firstbit = 0;
    }
    else{
        firstbit = 0x80000000;
    }
    return mask | firstbit;
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in input set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    int check_evens =   (((0x55) << 24)|((0x55) << 16)| ((0x55) <<8) | (0x55)) & x;//0 if none of the even bits are set to 1
    int no_evens = !check_evens;//1 there are no evens set, and 0 otherwise
    return !no_evens;//"reverses" check_evens
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {// 16 operations
    int zeroth_byte = x & 0xF;
    
    int less_than_7 = x & 0x8; //results in 0 if the last byte is less than 7
    int eight_or_nine = (x & 0x6) | !(zeroth_byte>>1)  ;//results in 0 if value is 8 or 9

    int compare_0th_byte = !less_than_7 + !eight_or_nine;//reults in 1 if the values is nine or under- one test fails and the other passes
    int compare_1st_byte = !(0x30 ^ ((x ^ zeroth_byte)));//returns 1 if the 1st byte is 0x3 and the leading bytes are all 0's
    
    return !((compare_1st_byte & compare_0th_byte) ^ 1);//returns 1 if the 0th byte is less than 9 and the leading bytes are 0's with a 3 as the first
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    int f_sign = uf & 0x80000000;
    int f_mag = uf & 0x7FFFFFFF;

    int g_sign = ug & 0x80000000;
    int g_mag = ug & 0x7FFFFFFF;//need just sign and magnitude

    if((f_mag > 0x7F800000)|| (g_mag > 0x7F800000)){//NaN values
        return 0;
    }
    if((f_mag == g_mag) && (f_mag == 0)){//handles +0 and -0
        return 0;
    }
    if(f_sign == g_sign){
        if(f_sign == 0){//both are positive
            return f_mag < g_mag;//f magnitude must be smaller
        }
        else{//both are negative
            return f_mag > g_mag;//f magnitude must be larger
        }
    }
    else{
        return f_sign < g_sign;//f sign must be negative and g sign positive
    }
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);//creates a mask for x that has the first n bits set to 0 and the remaining are set to 1
    return mask & (x>>n);//if you shift x n-bits to the right, the mask should set the first n bits to zero
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x){
    /*
        This code implements a binary search so there are a lot of repeated variables and
        operations used; I explained their reasoning in the first few iterations and that
        reasoning is kept consistent throughout; just know that I took a 32 bit sequence,
        broke it up into two section, determined if there was a 1 present in the first section,
        either kept or deleted the second section depending if the first had a 1 or not,
        put them together again but as a bit sequence that is half the length of the first, and
        repeat until there is only a single bit left. The variables i, j, k, l, and m keep track
        of final shifts that are needed to create a mask.
    */
    int var1 = (0xFF << 8);//just a mask labeled as a variable to reduce redundancy
    int Sec1 = ((((0xFF << 24) | (0xFF << 16)) & x) >> 16) & (var1 | 0xFF);//the upper 16 bits of x
    int Sec2 = ((0xFF << 8) | 0xFF) & x;//the lower 16 bits of x

    int i,j,k,l,m = 0;//variables i,j,k,l, and m keep track on how far to the left we need to shift at the end

    int DeleteOrKeep = !Sec1;//if Sec1 has at least one bit set then 0, else 1; Keep Sec2 = 1, Delete Sec2 = 0
    int Operation = (!DeleteOrKeep << 31) >> 31;//Keep = 0x00000000; Delete = 0xFFFFFFFF

    int NewX;//New X will be half as many bits as it was originally, at first it will start at 16 -> 8 -> 4 -> 2 -> 1
    
    i = (16 & Operation);//if we 'Keep' Sec2, then we don't shift, otherwise we would need to shift
    Sec2 = ~Operation & Sec2;//clears or saves Sec2
    NewX = Sec1 | Sec2;//go from 32 -> 16 bits

    Sec1 = (((var1 & NewX) >> 8));//redefines Sec1 according to NewX
    Sec2 = 0xFF & NewX;//redefines Sec2 according to NewX

    DeleteOrKeep = !Sec1;//need to check for a one in Sec1 again
    Operation = (!DeleteOrKeep << 31) >> 31;//Delete or Keep

    j = (8 & Operation);//if wee Keep Sec2, then don't shift, otherwise shift
    Sec2 = ~Operation & Sec2;
    NewX = Sec1 | Sec2;//go from 16 -> 8 bits

    Sec1 = (((0xF << 4) & NewX) >> 4);
    Sec2 = 0xF & NewX;

    DeleteOrKeep = !Sec1;
    Operation = (!DeleteOrKeep << 31) >> 31;

    k = (4 & Operation);
    Sec2 = ~Operation & Sec2;
    NewX = Sec1 | Sec2;//go from 8 -> 4 bits

    Sec1 = ((0xC & NewX) >> 2);
    Sec2 = 0x3 & NewX;
    
    DeleteOrKeep = !Sec1;
    Operation = (!DeleteOrKeep << 31) >> 31;

    l = (2 & Operation);
    Sec2 = ~Operation & Sec2;
    NewX = Sec1 | Sec2;//go from 4 -> 2 bits

    Sec1 = ((0x2 & NewX) >> 1);
    Sec2 = 0x1 & NewX;

    DeleteOrKeep = !Sec1;
    Operation = (!DeleteOrKeep << 31) >> 31;

    m = (1 & Operation);
    Sec2 = ~Operation & Sec2;
    NewX = Sec1 | Sec2;//go from 2 -> 1 bit

    NewX = (((((NewX << m) << l) << k) << j) << i);//shift the single bit by however many it needs

    return NewX;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 *  THIS IS NOW EXTRA CREDIT
 */
unsigned floatScale1d2(unsigned uf) {
    return 2;
}

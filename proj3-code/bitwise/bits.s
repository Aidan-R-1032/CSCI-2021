# Read the following instructions carefully
# You will complete your solution to the bitwise portion of the project by
# editing the collection of functions in this source file.
#
# Some rules from Project 2 are still in effect for your assembly code here:
#  1. No global variables are allowed
#  2. You may not define or call any additional functions in this file.
#  3. You may not use any floating-point assembly operations.
#
# You may assume that your machine:
#  1. Uses two's complement, 32-bit representations of integers

# Use the 'btest_driver' program to check your functions for correctness

.text

# minusOne - return a value of -1
#   Rating: 1
.global minusOne
minusOne:
    movl $(~0), %eax
    ret

# thirdBits - return int with every third bit (starting from the LSB) set to 1
#   Rating: 1
.global thirdBits
thirdBits:
    movl $0x49249249, %eax
    ret

# byteSwap - swaps the nth byte and the mth byte
#  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
#            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
#  You may assume that 0 <= n <= 3, 0 <= m <= 3
#  Rating: 2
.global byteSwap
byteSwap:
    #%edi holds first arg x, %esi holds second arg n, %edx holds third arg m
    shll $3, %esi #esi = n << 3
    movl %esi, %ecx # ecx = n << 3
    movl $255, %r8d # r8d = 0xFF
    shll %ecx, %r8d #r8d = 0xFF << (n << 3)
    movl %r8d, %r9d #r9d = 0xFF << (n << 3)
    
    shll $3, %edx #edx = m << 3
    movl %edx, %ecx # ecx = m << 3
    shll %ecx, %r8d # r8d = 0xFF << (m << 3)

    andl %edi, %r9d # r9d = x & (0xFF << (n << 3)) - nth mask
    andl %edi, %r8d # r8d = x & (0xFF << (m << 3)) - mth mask

    #the code above creates masks for the nth and mth bytes - %r9d and %r8d
    #now we need to clear the nth and mth bytes:
    movl %r9d, %r10d #r10d = x & (0xFF << (n << 3))
    movl %r8d, %r11d #r11d = x & (0xFF << (m << 3))
    orl %r10d, %r11d #r11d = %r10d | %r11d
    notl %r11d #r11d = ~(%r10d | %r11d)
    andl %r11d, %edi #edi = x & (~(%r10d | %r11d)) - open

    #the nth and mth bytes have now been cleared - %r9d holds the result of that
    #now we need to shift the nth and mth bytes into their new positions
    movl %esi, %ecx # ecx = n << 3
    shrl %ecx, %r9d # r9d = (x & (0xFF << (n << 3))) >> (n >> 3)
    movl %edx, %ecx # ecx = m << 3
    shll %ecx, %r9d # r9d = ((x & (0xFF << (n << 3))) >> (n << 3)) << (m << 3)

    shrl %ecx, %r8d # r8d = (x & (0xFF << (m << 3))) >> (m << 3)
    movl %esi, %ecx # ecx = n << 3
    shll %ecx, %r8d # r8d = ((x & (0xFF << (m << 3))) >> (m << 3)) << (n << 3)

    #now the bytes are in their appropriate places, finally we can 'or' them all together
    movl %r11d, %eax # eax = open
    orl %r9d, %eax # eax = open | n mask
    orl %r8d, %eax # eax = open | n mask | m mask
    ret

# copyLSB - set all bits of result to least significant bit of x
#   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
#   Rating: 2
#/
.global copyLSB
copyLSB:
    movl $2, %eax
    ret

# isPositive - return 1 if x > 0, return 0 otherwise
#   Example: isPositive(-1) = 0.
#   Rating: 2
.global isPositive
isPositive:
    movl $2, %eax
    ret

# floatNegate - Return bit-level equivalent of expression -f for
#   floating point argument f.
#   Both the argument and result are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representations of
#   single-precision floating point values.
#   When argument is NaN, return argument.
#   Rating: 2
.global floatNegate
floatNegate:
    movl $2, %eax
    ret

# anyEvenBit - return 1 if any even-numbered bit in input set to 1
#   where bits are numbered from 0 (least significant) to 31 (most significant)
#   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
#   Rating: 2
.global anyEvenBit
anyEvenBit:
    movl $2, %eax
    ret

# isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
#   Example: isAsciiDigit(0x35) = 1.
#            isAsciiDigit(0x3a) = 0.
#            isAsciiDigit(0x05) = 0.
#   Rating: 3
.global isAsciiDigit
isAsciiDigit:
    movl $2, %eax
    ret

# floatIsLess - Compute f < g for floating point arguments f and g.
#   Both the arguments are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representations of
#   single-precision floating point values.
#   If either argument is NaN, return 0.
#   +0 and -0 are considered equal.
#   Rating: 3
.global floatIsLess
floatIsLess:
    movl $2, %eax
    ret


# logicalShift - shift x to the right by n, using a logical shift
#   Can assume that 0 <= n <= 31
#   Examples: logicalShift(0x87654321,4) = 0x08765432
#   Rating: 3
.global logicalShift
logicalShift:
    movl $2, %eax
    ret

# greatestBitPos - return a mask that marks the position of the
#               most significant 1 bit. If x == 0, return 0
#   Example: greatestBitPos(96) = 0x40
#   Rating: 4
.global greatestBitPos
greatestBitPos:
    movl $2, %eax
    ret

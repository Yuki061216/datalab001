/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return (~(x&y))&(~(~x&~y));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int x0=x >> 31;
    int y0=y >> 31;
    if (x0^y0) return 0;
    if (!x) {
        return !y;
    }
    if (!y) {
        return 0;
    }
    return 1;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int ans = 0;
    int t;

    t = (v > 0xFFFF) << 4;
    ans = ans | t;
    v = v >> t;

    t = (v > 0xFF) << 3;
    ans = ans | t;
    v = v >> t;

    t = (v > 0xF) << 2;
    ans = ans | t;
    v = v >> t;

    t = (v > 0x3) << 1;
    ans = ans | t;
    v = v >> t;

    t = (v > 0x1);
    ans = ans | t;

    return ans;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int shift_n = n << 3;
    int shift_m = m << 3;
    int byte_n = (x >> shift_n) & 0xFF;
    int byte_m = (x >> shift_m) & 0xFF;

    x = x & ~(0xFF << shift_n);
    x = x & ~(0xFF << shift_m);

    x = x | (byte_m << shift_n);
    x = x | (byte_n << shift_m);
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v = ((v & 0x55555555) << 1) | ((v >> 1) & 0x55555555);

    v = ((v & 0x33333333) << 2) | ((v >> 2) & 0x33333333);

    v = ((v & 0x0F0F0F0F) << 4) | ((v >> 4) & 0x0F0F0F0F);

    v = ((v & 0x00FF00FF) << 8) | ((v >> 8) & 0x00FF00FF);

    v = (v << 16) | (v >> 16);

    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int temp = x >> n;
    int mask = ~(1 << 31 >> n << 1);
    return temp & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int v = ~x;
    int ans = 0;
    int t;

    t = (!(v >> 16)) << 4;
    ans += t;
    v <<= t;

    t = (!(v >> 24)) << 3;
    ans += t;
    v <<= t;

    t = (!(v >> 28)) << 2;
    ans += t;
    v <<= t;

    t = (!(v >> 30)) << 1;
    ans += t;
    v <<= t;

    t = !(v >> 31);
    ans += t;

    ans += !v;

    return ans;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned int sign = 0;
    unsigned int exp = 0;
    unsigned int frac = 0;
    unsigned int abs_x = x;
    int shift = 0;
    int round_bit = 0;
    int sticky_bit = 0;
    int lsb = 0;

    if (x == 0) {
        return 0;
    }

    if (x < 0) {
        sign = 0x80000000;
        abs_x = -x;
    }

    unsigned int temp = abs_x;
    while (!(temp & 0x80000000)) {
        abs_x = abs_x << 1;
        shift = shift + 1;
        temp = abs_x;
    }

    exp = 158 - shift;

    frac = (abs_x >> 8) & 0x007FFFFF;

    round_bit = (abs_x >> 7) & 1;
    sticky_bit = (abs_x & 0x7F) != 0;
    lsb = (abs_x >> 8) & 1;

    // 将 && 改为 &，|| 改为 |
    if (round_bit & (sticky_bit | lsb)) {
        frac = frac + 1;
        if (frac & 0x00800000) {
            frac = 0;
            exp = exp + 1;
        }
    }

    return sign | (exp << 23) | frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned int s = uf & 0x80000000;
    unsigned int exp = (uf >> 23) & 0xFF;
    unsigned int frac = uf & 0x007FFFFF;

    if (exp == 0xFF) {
        return uf;
    }

    if (exp == 0) {
        return s | ((uf & 0x7FFFFFFF) << 1);
    }

    exp = exp + 1;

    if (exp == 0xFF) {
        return s | 0x7F800000;
    }

    return s | (exp << 23) | frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int sign = uf2 >> 31;
    int exp = ((uf2 >> 20) & 0x7FF) - 1023;
    unsigned int frac_high = uf2 & 0xFFFFF;

    if (exp < 0) {
        return 0;
    }
    if (exp >= 31) {
        return 0x80000000;
    }

    unsigned int res = 0;

    // 纯用 32 位无符号整数进行分段移位对齐
    if (exp >= 20) {
        res = (1 << 20 | frac_high) << (exp - 20);
        res = res | (uf1 >> (52 - exp));
    } else {
        unsigned int combined = (1 << 20) | frac_high;
        res = combined >> (20 - exp);
    }

    if (sign) {
        res = -res;
    }

    return res;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x > 127) {
        return 0x7F800000;
    }

    if (x < -149) {
        return 0;
    }

    if (x >= -126) {
        int exp = x + 127;
        return exp << 23;
    }
    else {
        int shift = 149 + x;
        return 1 << shift;
    }
}

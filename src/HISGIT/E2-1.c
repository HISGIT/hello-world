#include <stdio.h>
#include <limits.h>
#include <float.h>
/* Write a program to determine the range of char, short, int, and long variables, both signed and unsigned, by printing appropriate values
 from standard headers and by direct computation. Harder if you compute them: determine the ranges of various floating-point types*/
int main(){
    printf("bits in a char: %d\n",CHAR_BIT);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("unsigned CHAR_MAX: %d\n", UCHAR_MAX);
    printf("short max: %d\n", SHRT_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("unsigned short max: %d\n", USHRT_MAX);
    printf("int max: %d\n", INT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("long max: %ld\n", LONG_MAX);
    printf("long min: %ld\n", LONG_MIN);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("decimal digits of precesion: %d\n", FLT_DIG);
    printf("FLT_RADIX: %d\n", FLT_RADIX);
    printf("FLT_EPSILON: %e\n", FLT_EPSILON);
    printf("FLT_MANT_DIG: %d\n", FLT_MANT_DIG);
    printf("FLT_MAX: %.2e\n", FLT_MAX);
    printf("FLT_MAX_EXP: %d\n", FLT_MAX_EXP);
    printf("FLT_MIN: %e\n", FLT_MIN);
    printf("FLT_MIN_EXP: %e\n", FLT_MIN_EXP);
    printf("DBL_DIG: %d\n", DBL_DIG);
    printf("DBL_MAX: %e\n", DBL_MAX);
    long lmx = LONG_MAX;
    int bitcnt = 1;
    while(lmx > 0){
        lmx >>= 1;
        bitcnt++;
    }
    printf("LONG_BIT:%d\n",bitcnt);
    return 0;
}

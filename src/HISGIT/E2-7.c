/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the
  n bits that begins at position p inverted (i.e.,1 changed into 0 and
  vice versa), the others unchanged. */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
int main(){
    int x = 177;
    int p =5, n=3;
    int y = 0xA;
    printf("%d\n", invert(x,p,n));
}

unsigned invert(unsigned x, int p, int n){
    return x ^ ( ~(~0 << n) << (p+1-n) );
}

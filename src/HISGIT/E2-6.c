/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with
 the n bits that begins at position p set to the rigthmost n bits of 
 y,leaving the others unchanging. */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned int y);
int main(){
    int x,p,y,n;
    y = 1000;
    for(x = 0;x <= 3000 ; x += 100){
        for(p = 0; p < sizeof(y) && p < sizeof(x); p++){
            for(n = 1; n <= p+1; n++){
                printf("setbits(%d, %d, %d,%d) is %d\n",x ,p ,n ,y, 
                        setbits(x,p,n,y));
            }
        }
    }
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned int y){
    int y_nb = (~y & ~(~0 << n)) << (p+1-n);
    int x_nonb = ~x & ~(~(~0<<n)<<(p+1-n));
    int res = ~x_nonb & ~y_nb;
    return res;
}

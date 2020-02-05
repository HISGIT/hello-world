#include <stdio.h>
/*Excercise 2.9. In a two's complement number system,
  x &= (x-1) deletes the rightmost 1-bit in x. Expla-
  in why. Use this observation to write a faster ver-
  sion of bitcount.*/

int bitcount(int x){
    int nx = x;
    int cnt = 0;
    while(nx > 0){
        nx &= (nx-1);
        cnt += 1;
    }
    return cnt;
}

int main(){
    printf("%d\n",bitcount(4902785));
}

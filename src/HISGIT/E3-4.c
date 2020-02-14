/*Exercise 3-4. In a two's complement number presentation, our version of itoa 
 * does not handle the lagrest negative  number , that is, the value of n equal 
 * to -(2^(wordsize-1)). Explain why not. Modify it to print that value 
 * correctly regardless of the machine on which is runs. */
#include <stdio.h>
#include <string.h>
int main(){
    char s1[] = "4804673123";
    long int t1 = 0;
    char sg;
    for(int i = 0; i < strlen(s1); i++){
        if(s1[i] >= '0' && s1[i] <= '9')
            t1 = t1*10 + s1[i] - '0';
        else if(s1[i] == '-')
            sg = s1[i];
        else
            return -1;
    }
    if(sg == '-')
        t1 = 0 - t1;
    printf("%ld\n", t1);
    return t1;
}

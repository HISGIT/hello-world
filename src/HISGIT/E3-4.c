/*Exercise 3-4. In a two's complement number presentation, our version of itoa 
 * does not handle the lagrest negative  number , that is, the value of n equal 
 * to -(2^(wordsize-1)). Explain why not. Modify it to print that value 
 * correctly regardless of the machine on which is runs. */
#include <stdio.h>
#include <string.h>
void reverse(char s[]);
int main(){
    char s1[1000];
    long int t1 = -480467000;
    char sg;
    if(t1 < 0){
        sg = '-';
        t1 = -t1;
    }
    int i = 0;
    do{
        s1[i++] = t1 % 10 + '0';
    }while((t1 /= 10)> 0);
    if(sg == '-')
        s1[i++] = sg;
    s1[i] = '\0';
    printf("s1:%s\n",s1);
    reverse(s1);
    printf("s1:%s\n",s1);
    return t1;
}

void reverse(char s[]){
    int i, j, temp;
    for(i = 0, j = strlen(s) - 1; i < j; i++,j--){
        temp = s[i], s[i] = s[j], s[j] = temp;
    }
}

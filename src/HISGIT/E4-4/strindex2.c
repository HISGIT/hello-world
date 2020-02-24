/*Exercise 4-1. Write the function strindex(s,t), which returns the position of 
 * the rightmost occurence of t in s, or -1 if there is none. */
#include <string.h>

int strindex2(char s[], char t[]){
    int i, j, k;
    int slen = strlen(s);
    int tlen = strlen(t);

    for(i = slen - 1; i >= 0; i--){
        for(j=i, k= tlen - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if(k == -1 )
            return j+1;
    }
    return -1;
}

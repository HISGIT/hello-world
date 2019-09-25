#include <stdio.h>
/* equvialient to the expression without using || or &&:
   for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
   s[i] = c;
   */
#define MAX_LEN 100
int main(void){
    char c;
    char line[MAX_LEN];
    int idx = 0;
    while(idx < MAX_LEN-1 ){
        c = getchar();
        if(c == '\n')
            break;
        if(c == EOF)
            break;
        line[idx] = c;
        idx++;
    }
    if(c == '\n'){
        line[idx] = c;
        idx++;
    }
    line[idx] = '\0';
    printf("%s",line);
    return 0;
}

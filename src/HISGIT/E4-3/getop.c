#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);
/* getop: get operator or numeric operand*/
int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')    /*not a number */
        return c;
    i = 0;
    if(c == '-' ){
        if( isdigit(s[++i] = c = getch()) )
            s[0] = '-';
        else
            return '-';
    }
    if(isdigit(c)) /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')    /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

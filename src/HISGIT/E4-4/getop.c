#include <ctype.h>
#include <string.h>
#include <stdio.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);
int strindex2(char [], char []);

/* getop: get operator or numeric operand*/
int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    i = 0;
    if(isalpha(c)){
        while( !isspace( (s[++i] = c = getch()) ) )
            ;
        s[i] = '\0';
        char top[] = "top";
        char clear[] = "clear";
        char swap[] = "swap";
        if(strindex2(top, s) == 0)  /* match the print top command*/
            return 't';
        else if(strindex2(clear, s) == 0)   /* match the clear command*/
            return 'c';
        else if(strindex2(swap, s) == 0)    /* match the swap command*/
            return 's';
        else
            return 'u';
    }
    if(!isdigit(c) && c != '.' && c != '-')    /*not a number */
        return c;
    if(c == '-' ){
        if( isdigit(s[++i] = c = getch()) )
            s[0] = '-';
        else if(isspace(c))
            return '-';
        else 
            return 'u';
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

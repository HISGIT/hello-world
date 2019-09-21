#include <stdio.h>
#define MAX_BUFFER 1024
//remove comment version 2.0
/* write a program to remove  all comments from a C program. Don't forget to handle quoted strings and character constants properly */
#define TT 2
#define T 1
#define F 0
int getlines(char line[], int maxlen){
    int c,i;
    for(i = 0; i < maxlen - 1 && (c = getchar() ) != EOF && c != '\n'; i++)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int main(void){
    int COMMENT = F;
    int QUOTED = F;
    char line[MAX_BUFFER];
    int len = 0;
    while( (len = getlines(line,MAX_BUFFER)) > 0){
        int k = 0;
        for(; k < len+1; k++){
            if(COMMENT > F){
                if(line[k] == '\n' && COMMENT == TT)
                    COMMENT = F;
                if(line[k-2] == '*' && line[k-1] == '/' && COMMENT == T)
                    COMMENT = F;
            }else {
               if(line[k-1] != '\'' || line[k-1] != '"'){ 
                    if(line[k] == '/' && line[k + 1] == '/')
                        COMMENT = TT;
                    if(line[k] == '/' && line[k + 1] == '*')
                        COMMENT = T;
               }
            }
            if(COMMENT == F)
                printf("%c",line[k]);
        }
    }
}

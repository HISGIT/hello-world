/*Excercise 3-2. Write a function escape(s,t) that converts characters like 
 * newline and tab into visiable excape sequences like \n and \t as it copies 
 * the string t to s. Use a switch . Write a function for the other direction 
 * as well, converting escape sequences into the real chracters. */
#include <stdio.h>
#define MAXLINE 1000

int escape(char s[], char t[]){
    int i, j;
    for(i = 0, j = 0; s[i] != '\0' ; i++){
       switch(s[i]){
           case '\n':
               t[j++] = '\\';
               t[j++] = 'n';
               break;
           case '\t':
               t[j++] = '\\';
               t[j++] = 't';
               break;
           default:
               t[j++] = s[i];
       }
    }
    t[j] = '\0';
    return 0;
}
int rvrescape(char s[], char t[]){
    int i, j;
    for(i = 0, j = 0; s[i] != '\0' ; i++){
       switch(s[i]){
           case '\\':
               switch(s[++i]){
                case 'n':
                    t[j++] = '\n';
                    break;
                case 't':
                    t[j++] = '\t';
                    break;
               }
               break;
           default:
               t[j++] = s[i];
               break;
       }
    }
    t[j] = '\0';
    return 0;
}
int getlines(char line[], int len){
    int i,c;
    for(i = 0; (c = getchar()) != EOF && i < len -1 && c != '\n';i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
int main(){
    char s[MAXLINE], t[MAXLINE];
    getlines(s, MAXLINE);
    rvrescape(s, t);
    printf("%s",t);
    return 0;
}

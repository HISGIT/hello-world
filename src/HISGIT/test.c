/*shell sort*/
#include <stdio.h>
#define MAXLINE 1000
int getlines(char line[], int max);
int strindex(char source[], char search[]);
char pattern[] = "ould";
int main(void){
    char line[MAXLINE];
    int found = 0;

    while(getlines(line, MAXLINE) > 0){
        if(strindex(line, pattern) >= 0){
            printf("%s",line);
            found++;
        }
    }
    return found;
}


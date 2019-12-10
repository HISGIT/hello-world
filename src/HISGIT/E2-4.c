/* Exercise 2-4. Write an alternate version of squeeze(s1, s2) that 
 delete each character in s1 that matches any character in the s2.*/

#include <stdio.h>
#define MAXLEN 100
int squeeze(char s1[],char s2[]);
int getlines(char line[], int len);
int main(void){
    char s1[MAXLEN], s2[MAXLEN];
    printf("please input string 1:\n");
    getlines(s1, MAXLEN);
    printf("please input string 2:\n");
    getlines(s2, MAXLEN);
    squeeze(s1,s2);
    printf("s1:%s\ns2:%s\n",s1,s2);
    
}
int squeeze(char s1[], char s2[]){
    int i, j;
    for(j = 0;s2[j] != '\0'; j++){
        for(int k = i = 0; s1[k] != '\0';k++){
            if(s1[k] != s2[j])
                s1[i++] = s1[k];
        }
        s1[i] = '\0';
    }
}
int getlines(char line[],int len){
    int i,c;
    for(i = 0; (c=getchar()) != EOF && c != '\n' && i < len -1; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = '\0';
        i++;
        return i;
    }
    line[i] = '\0';
    return i;
}

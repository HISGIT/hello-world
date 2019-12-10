 /* Exercise 2-5. Write the function any(s1,s2), which returns the fi-
    rst location in the string s1 where any character from the string 
    s2 occurs, or -1 if s1 contains no characters from s2. The standa-
    rd library function strpbrk does the same job but returns a point-
    er to the location. */

#include <stdio.h>
#define MAXLEN 100
int any(char s1[],char s2[]);
int getlines(char line[], int len);
int main(void){
    char s1[MAXLEN], s2[MAXLEN];
    printf("please input string 1:\n");
    getlines(s1, MAXLEN);
    printf("please input string 2:\n");
    getlines(s2, MAXLEN);
    int first_l = any(s1,s2);
    printf("first: %c is the %dth character of %s\n",
            s1[first_l], first_l,s1);
}
int any(char s1[], char s2[]){
    int i, j;
    int location = -1;
    for(j = 0;s2[j] != '\0'; j++){
        int s2locate = -1;
        for(int i = 0; s1[i] != '\0';i++){
            if(s1[i] == s2[j]){
                printf("%c is the %dth character of %s\n",s2[j],i,s1);
                s2locate = i;
                break;
            }
        }
        if(s2locate > -1 && s2locate < location)
            location = s2locate;
        if(s2locate > -1 && location == -1)
            location = s2locate;
    }
    return location;
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

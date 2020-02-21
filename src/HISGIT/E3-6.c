/*Exercise 3-6. Write a version of itoa that accepts three arguments instead 
 * of two. The third argument is a minimum field width; the converted number 
 * must padded with blanks on the left if necessary to make it wide enough. */
#include <stdio.h>
#include <string.h>
void itoa(int n, char s[], int str_len);
void reverse(char s[]){
    int i, j, temp;
    for(i = 0, j = strlen(s)-1 ;i < j; i++, j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}
main(){
    int n = -9834;
    int str_len = 10;
    char s1[1001];
    itoa(n, s1, str_len);
    reverse(s1);
    printf("s1:%s\n", s1);
}
void itoa(int n, char s[], int str_len){
    int i, sign;
    if((sign = n) < 0)
        n = -n;
    i = 0;
    do{
    s[i++] = n % 10 + '0';
    }
    while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    while(i < str_len){
        s[i++] = ' ';
    }
    s[i] = '\0';
}

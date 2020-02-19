/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into 
 * a base b chracter representation in the string s. In particular, 
 * itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>
void itoa(int n, char s[], int str_len);
void reverse(char s[]);
void itohex(int n, char s[]);
int main(){
    long int quotient, remainder, b, sign;
    quotient = 52242084;
    b = 32;
    printf("%ld(base 10)\n",quotient);
    if( quotient < 0){
        sign = -1;
        quotient = quotient * sign;
    }
    else 
        sign = 1;
    int bt = b,
        cnt = 0;
    while( bt > 0){
        cnt++;
        bt /= 10;
    }
    cnt++;
    int take_width = cnt;
    char temp[cnt];
    char s1[1024];
    cnt = 0;
    while(quotient > 0){
        remainder = quotient % b;
        quotient = quotient / b;
        if(b == 16)
            itohex(remainder, temp);
        else
            itoa(remainder, temp, take_width);
        for(int i = 0; temp[i] != '\0'; i++){
            s1[cnt] = temp[i];
            cnt++;
        }
        s1[cnt++] = '_';
    }
    s1[cnt] = '\0';
    reverse(s1);
    if(b == 16){
        if(sign < 0)
            printf("-");
        printf("0x");
        for(int i = 0; s1[i] != '\0';){
            if(s1[i] == '_')
                i++;
            else
                printf("%c", s1[i++]);
        }
    }else
        printf("s1:%c%s", (sign >= 0)?' ':'-', s1);
    printf("(base %d)\n", b);
}

void itohex(int n, char s[]){
    if(n > 9){
        s[0] = n - 10 + 'A';
    }else
        s[0] = n + '0';
    s[1] = '\0';
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

void reverse(char s[]){
    int i, j, temp;
   for(i = 0, j = strlen(s) - 1;i < j; i++,j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
   } 
}


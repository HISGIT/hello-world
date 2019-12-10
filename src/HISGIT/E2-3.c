/*Write the function htoi(s), which coverts a string of hexa-decimal 
  digits (including an optional 0x or 0X) into equivalent integer val-
  ue. The allowable digits are 0 through 9, a through f, and F through
  F. )*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 100
int getlines(char line[], int len);
int htoi(char str[]){
    int res = 0;
    if (str[0] == '0' && toupper(str[1]) == 'X'){
        int idx = 2;
        int num_idx;
        while(str[idx] != '\0' && str[idx] != '\n'){
            if(str[idx] >= '0' && str[idx] <= '9'){
                num_idx = str[idx] - '0';
            }
            else if(toupper(str[idx]) >= 'A' 
            && toupper(str[idx]) <= 'F'){
                num_idx = toupper(str[idx]) - 'A' + 10;
            }else
                return -1;
            res = res * 16 + num_idx;
            idx++;
        }
    }
    else
        return -1;
    return res;
}

int main(void){
    char str[LENGTH];
    while(1){
        getlines(str,LENGTH);
        int out_decimal = htoi(str);
        if(out_decimal >= 0)
            printf("hexadecimal formate: %sdecimal form: %d\n", str,
            out_decimal);
        else
            printf("bad formate");
    }
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

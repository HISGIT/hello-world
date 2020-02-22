/*Exercise 4-2. Extend atof to handle scentific notation of the form
    123.45e-6
 where a floating-point number may be followed by e or E and an optionally 
 signed exponent. */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLEN 1000

float atof(char s[]);
int main(){
    char s[] = "     1414.23e-6";
    printf("%f",atof(s));
}

float atof(char s[]){
    float val, power;
    int i, sign, psign, atoi(char s[]);
    char e[MAXLEN];
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 :1 ;
    if(s[i] == '-' || s[i] == '+')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0+ s[i] - '0';
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e' || s[i] == 'E'){
        i++;
        psign = (s[i] == '-')? -1 : 1;
        i++;
    }
    for(int j = 0; isdigit(s[i]) && j < MAXLEN; j++, i++){
        e[j] = s[i];
    }
    float epower = pow(10.0, atoi(e));
    power = (psign == 1) ? (power/epower) : (power * epower);
    return sign * val / power;
}

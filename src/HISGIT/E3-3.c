/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations 
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
 * Allow for letters of either case and digits, and be prepared to handle cases 
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is 
 * taken literally.*/

#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000
int main(){
    char s1[MAXLENGTH] = "-a-z0-9----";
    char lf, rt;
    for(int idx =0; idx < strlen(s1); idx++){
        if(s1[idx] == '-' && s1[idx-1] > 0 && s1[idx+1] > 0){
            lf = s1[idx-1];
            rt = s1[idx+1];
            int j,k;
            if(lf >= 'a' && lf <= 'z' && rt >= 'a' && rt <= 'z'){
                j = lf;
                k = rt;
            }
            else if(lf >= 'A' && lf <= 'Z' && rt >= 'A' && rt <= 'Z'){
                j = lf;
                k = rt;
            }
            else if(lf >= '0' && lf <= '9' && rt >= '0' && rt <= '9'){
                j = lf;
                k = rt;
            }
            else{
                printf("%c",s1[idx]);
                j = k = 0;
            }
            for(int i = j + 1; i > 0 && i < k; i++){
                printf("%c",i);
            }
        }else
            printf("%c",s1[idx]);
    }
    return 0;
}

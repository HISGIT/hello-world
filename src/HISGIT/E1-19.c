#include <stdio.h>
#define MAXLEN 1000
/*Write a function reverse(s) that reverses the character string s . Use it to write a program that reverses its input a line at a time.*/
void reverse(char str[]);
main(){
	int i,k,c;
	char str[MAXLEN];
	i = 0;str[0] = 0;
	while( (c = getchar()) != EOF){
		if(c == '\n' && str[0] > 0){
			i++;
			str[i] = c;
			str[0] = i;
			reverse(str);
			for(k = 1; k <= i; k++)
				printf("%c",str[k]);
			i = 0;
			str[0] = 0;
		}else if(c == '\n' && str[0] == 0){
			putchar('\n');
		}else if(c != '\n' && i < MAXLEN ){
			i++;
			str[i] = c;
		/*	printf("%c",str[i]);*/
			str[0] = i;
		}
	}
	
	if(str[0] != 0 ) {
		reverse(str);
		for(k = 1; k <= i; k++)
			putchar(str[k]);
	}
}

void reverse(char s[]){
	int tmpChar,m,n;
	for(m = 1,n = s[0]-1; n >= m; m++,n--){
/*		printf("sm[%d]:%c,sn[%d]%c;",m,s[m],n,s[n]);*/
		tmpChar = s[m],
		s[m] = s[n];
		s[n] = tmpChar;
	}
}

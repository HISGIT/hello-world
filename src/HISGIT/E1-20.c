/* Write a program detab that replaces tabs in the input with the proper number blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter ?*/
#include <stdio.h>
#define MAXLEN 1000
#define SPACE ' '
#define TAB	'\t'
//glance through the soultion, become a imitation of the solution. 
int replaceTabNumber(int m,int n);
int getlines(char line[],int l);

int main(){
	int c,k,l,i;
	int tablank = 5;
	char line[MAXLEN];
	while(getlines(line,MAXLEN) > 0){
		for(k = 0, l = 0; line[k] != '\0'; k++){
			if(line[k] == TAB){
				for(i = 0; i < replaceTabNumber(tablank,l); i++){
					putchar(SPACE);
					l++;
				}
			}else{
				putchar(line[k]);
				l++;
			}
		}
	}
	return 0;
}
int getlines(char line[],int lim){
	int i,c;
	for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if( c == '\n'){
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

int replaceTabNumber(int m,int n){
	return m - n%m;
}

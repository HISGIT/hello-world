#include <stdio.h>
#define SPACE ' '
#define TAB '\t'
#define MAX_BUFFER 1024
/*write a program entab that replaces strings of blanks with the minium number of tabs and blanks to achieve the same spacing. Use the same stops as for detab. When either a tab or a single blank suffice to reach a tab stop, which
should be given preference?*/
int getlines(char s[],int lim);
int calculateNumberOfSpaces(int Offset, int Ts)
{
	return Ts - Offset % Ts;
}
int main(void)
{
	int c,i,l,k,blanks;
	char line[MAX_BUFFER];
	int TabSize = 4;
	while( getlines(line,MAX_BUFFER) > 0){
		for(i = 0, l = 0, blanks = 0; line[i] != '\0'; i++){
			if(line[i] == SPACE){
				blanks++;
				if(blanks == TabSize){
					putchar(TAB);
					//printf("blanks=%d,line[%d]:%c\n",blanks,i,'T');
					blanks = 0;
					l = l+TabSize;
				}else if(calculateNumberOfSpaces(l + blanks,TabSize) == TabSize){
					for(k = 0; k < blanks; k++){
						putchar(SPACE);
						//printf("blanks=%d,line[%d]:%c\n",blanks,i-blanks+k+1,'S');
						l++;
					}
					blanks = 0;
				}
			}else{
				if(blanks > 0){
					for(k = 0; k < blanks; k++){
						putchar(SPACE);
						//printf("blanks=%d,line[%d]:%c\n",blanks,i-blanks+k,'S');
						l++;
					}
				blanks = 0;
				}
				if(line[i] == TAB){
					putchar(TAB);
					//printf("blanks=%d,line[%d]:%c\n",blanks,i,'T');
				}
				else{
					putchar(line[i]);
					//printf("blanks=%d,line[%d]:%c\n",blanks,i,line[i]);
					l++;
				}
			}
		}
	}	
	return 0;
}

int getlines(char s[], int lim)
{
	int m,n;
	for(m = 0; m < lim -1 && (n = getchar()) != EOF && n != '\n'; m++)
		s[m] = n;
	if(n == '\n'){
		s[m] = n;
		++m;
	}
	s[m] = '\0';
	return m;
}

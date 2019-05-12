#include <stdio.h>
#define SPACE ' '
#define TAB '\t'
#define MAX_BUFFER 1024
int TabSize ;
char line[MAX_BUFFER];
/*write a program entab that replaces strings of blanks with the minium number of tabs and blanks to achieve the same spacing. Use the same stops as for detab. When either a tab or a single blank suffice to reach a tab stop, which
should be given preference?*/
int getlines();
int calculateNumberOfSpaces(int Offset)
{
	extern int TabSize;
	return TabSize - Offset % TabSize;
}
int main(void)
{
	int c,i,l,k,blanks;
	extern int TabSize;
	extern char line[];
	TabSize = 4;
	while( getlines() > 0){
		for(i = 0, l = 0, blanks = 0; line[i] != '\0'; i++){
			if(line[i] == SPACE){
				blanks++;
				if(blanks == TabSize){
					putchar(TAB);
					//printf("blanks=%d,line[%d]:%c\n",blanks,i,'T');
					blanks = 0;
					l = l+TabSize;
				}else if(calculateNumberOfSpaces(l + blanks) == TabSize){
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

int getlines()
{
	int m,n;
	extern char line[];
	for(m = 0; m < MAX_BUFFER -1 && (n = getchar()) != EOF && n != '\n'; m++)
		line[m] = n;
	if(n == '\n'){
		line[m] = n;
		++m;
	}
	line[m] = '\0';
	return m;
}

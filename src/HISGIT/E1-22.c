#include <stdio.h>
#define MAX_BUFFER 1024
#define TAB '\t'
#define SPACE ' '
/* write a program to "fold" long input into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent
with very long lines, and if there are no blanks or tabs before the specified column. */
//不用MAX_BUFFER做fold length，增加处理长度大于fold length 的语句
int getlines(char s[], int lim);
int blankLocationAfter(char s[],int cur, int length);

int main(void)
{
	int c;
	char line[MAX_BUFFER];
	int foldlength = 100;
	int i_m,i_n,location,blank_i;i_m = i_n = blank_i = location = 0;
	while( (c = getlines(line,MAX_BUFFER)) > 0){
		if(c < foldlength)
			printf("%s",line);
		else{
			while(i_m < c){
				if(line[i_m] == SPACE || line[i_m] == TAB){
								blank_i = i_m;
				}
				if(i_m == foldlength){
					if( (i_n = blankLocationAfter(line, i_m, foldlength)) >= 0 && i_m+1+i_n < blank_i)
									blank_i = i_m+1+i_n;
					line[blank_i] = '\n';
					location = 0;
					i_n = 0;
				}
				i_m++;
				location++;
			}
			printf("%s",line);
		}	
	}
	return 0;
}
int getlines(char line[], int lim)
{
	int m,n;
	for(m = 0; m < lim -1 && (n = getchar()) != EOF && n != '\n'; m++)
	line[m] = n;
	if(n == '\n')
	{
		line[m] = n;
		m++;
	}
	line[m] = '\0';
	return m;
}
int blankLocationAfter(char s[],int cur, int length)
{//返回后foldlength第一个空白字符的位置
	int i = 0;
	while( i < length && s[ i+cur+1 ] != SPACE && s[ i + cur+1 ] != TAB)
		i++;
	return i;
}

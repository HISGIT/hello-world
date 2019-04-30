#include <stdio.h>
#define MAXLEN 20
/*version 1.1
 write a program to remove  trailing blanks and tabs from each line of input, and to delete entirely blanks lines*/
void removeBnkLine(char inchar[],int outputLen);
main()
{	int c,k;
	c = 0;
	char line[MAXLEN];
	
	while( (k = getchar()) != EOF )
	{
		if(k != ' ' && k != '\t')
		{
			line[c] = k;
		/*	printf("line[%d]:%d\n",c,line[c]);*/
			c++;
		}
		if(c == MAXLEN )
		{
			removeBnkLine(line,MAXLEN);
			c = 0;
		}
	}
	removeBnkLine(line,c);/*output the last cycle*/
	return 0;	
}


void removeBnkLine(char inchar[],int outputLen)
{
	int i;i = 0;
	while(i < outputLen )
	{	
		if(inchar[i - 1] != '\n' || inchar[i] != '\n')
		printf("%c",inchar[i]);
		i++;
	}
}

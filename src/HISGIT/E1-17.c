#include <stdio.h>
#define MAXLEN 1000  /*maximum input size */
#define MINLEN 80
int getlines(char line[],int maxline);
void copy(char to[], char from[]);

/* Write a program to print all input lines that are longer than 80 characters */
main()
{
	int len ;	/* current line length*/
	int max ;	/* maximum length seen so far*/
	char line[MAXLEN];	/* current input line*/
	char longest[MAXLEN];	/* longest line saved here*/

	max= 0;
	
	while( (len = getlines(line,MAXLEN)) > 0)
	{	if(len > max){
			max = len;
			copy(longest,line);
		}
	if(len > MINLEN )
		printf("current line %d characters:\n %s\n",len,line);	
	}
	if(max > 0 )
		printf("%s",longest);
	return 0;
}

/*getlines: read a line into s, return length */
int getlines(char s[],int lim)
{
	int c,i;

	for(i = 0;i <  lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*copy : copy "from" into 'to'; assume to is big enough iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii*/
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while ( (to[i]=from[i]) != '\0')
	++i;
}

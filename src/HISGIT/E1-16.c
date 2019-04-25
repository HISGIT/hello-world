#include <stdio.h>
#define MAXLEN 1000  /*maximum input size */

int getlines(char line[],int maxline);
void copy(char to[], char from[]);

/* print longest input line 
   revise the main routine of longest-line program so it will correctly print the length of arbitrarily long input lines, and as mush as possible of the text*/
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

/*copy : copy "from" into 'to'; assume to is big enough */
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while ( (to[i]=from[i]) != '\0')
	++i;
}

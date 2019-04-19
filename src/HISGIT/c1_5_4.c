#include <stdio.h>
#define IN 1 /* inside a word*/
#define OUT 0 /* outside a word*/
/*count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;
	nl = nw = nc = 0;
	state = OUT;
	while ( (c = getchar()) != EOF )
	{
		++nc;
		if (c == ' ' || c == '\n' || c == '\t' )
			state = OUT;
		else if (state == OUT)
		{	++nw;
	   		state = IN;	
		}
		if (c == '\n')
			nl++;
	}
	printf("%d %d %d", nl, nw, nc);
}

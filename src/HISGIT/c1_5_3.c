#include <stdio.h>
/*count newlines, blanks, tabs */
main()
{
	int c, nl,blk,tab;
	nl = 0, blk = 0, tab = 0;
	while ( (c = getchar()) != EOF )
	{
			if (c == '\n')
				nl++;
			else if (c == ' ')
				blk++;
			else if (c == '\t')
				tab++;
			else ;
	}
	printf("\n newlines:%d,\n blankds:%d,\n tabs:%d\n", nl, blk, tab);
}

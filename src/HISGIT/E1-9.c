#include <stdio.h>
main()
{
	int c, blk;
	blk = 0;
	while ( (c = getchar()) != EOF )
	{
		if (c == ' ')
		{
			if (blk ==0)
			putchar(c);
			++blk;
		}
		else
		{
			putchar(c);
			blk = 0;
		}
	}
}

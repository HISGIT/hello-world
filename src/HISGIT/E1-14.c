#include <stdio.h>
/*print a histogram of the frenquencies of different characters in its input*/
main()
{
	int i,j,c;
	int nc[128];
	for(i = 0; i < 128; i++)
		nc[i] = 0;
	while((c = getchar()) != EOF)
	{
		if(c >= 0 && c < 128)
			{
				i = c;
				nc[i]++;
			}
	}
	for(i = 0; i < 128; i++)
		printf("nc[%d]:%d\n",i,nc[i]);
	for(i = 0; i < 128; i++)
	{
		printf("--|%c|",i);
		j = nc[i];
		while(j > 0)
		{
			printf("|");
			j--;
		}
		printf("%d\n",nc[i]);
	}
}

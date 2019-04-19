#include <stdio.h>
/*Exercise 1-13 print a histogram of the length of words in its input. horizontal one and vertical one*/
#define IN 1 /*inside a word*/
#define OUT 0 /*outside  a word*/
#define ARR_LEN 30
main()
{
	int i,j,c,state,cnt,x;
	int nw[ARR_LEN];
	state  = OUT;cnt = 0;
	for (i = 0;i < ARR_LEN; i++)
		nw[i] = 0;
	while ( (c = getchar()) != EOF)
	{	
		if (c != ' ' &&  c != '\n' && c != '\t')
		{ state = IN;
		  cnt++;
		}else if ( state == IN)
			{ state = OUT;
			  if ( cnt < ARR_LEN )
			  nw[cnt]++;
			  nw[0]++;
			  cnt = 0;
			}
	}
	for (i = 0;i < ARR_LEN; i++)
		printf("nw[%d]:%d\n",i,nw[i]);

	/*for (i = 0; i < ARR_LEN;i++ )
		printf("len %d,cnt %d;\n",i,nw[i]);*/
/*horizontal display*/
	for (i = ARR_LEN;i > 0; i--)
	{
		printf("%2d",i - 1);
		printf("  |");
		for(j = nw[i-1]; j >= 0; j--)
		{
		 if(j == 0)
		 printf("\n");
		 else
		 printf("|");
		}
		if (i-1 == 0)
		{ printf("    ");
		  for(x = 0;x <45 ; x++)
				printf("_");
		}
	}
	printf("\n\n\n\n");
/*vertical display*/
	for (i = 0;i < ARR_LEN; i++)
		printf("nw[%2d]:%4d\n",i,nw[i]);

	for(i = nw[0];i >= 0; i--)
		{	printf("\n");
		 	printf("%4d  ",i);
			j = 0;
			while (j < ARR_LEN)
			{	if( nw[j] >= i )
					printf("* ");
				else
					printf("  ");
				j++;
			}
		}
	printf("\n");
}

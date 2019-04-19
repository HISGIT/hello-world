#include <stdio.h>
/*Exercise 1-13 print a histogram of the length of words in its input. horizontal one and vertical one*/
#define IN 1 /*inside a word*/
#define OUT 0 /*outside  a word*/
main()
{
	int i,j,c,state,cnt,x;
	int nw[30];
	state  = OUT;cnt = 0;
	for (i = 0;i < 30; i++)
		nw[i] = 0;
	while ( (c = getchar()) != EOF)
	{	
		if (c != ' ' &&  c != '\n' && c != '\t')
		{ state = IN;
		  cnt++;
		}else if ( state == IN)
			{ state = OUT;
			  if ( cnt < 30 )
			  nw[cnt]++;
			  nw[0]++;
			  cnt = 0;
			}
	}
	for (i = 0;i < 30; i++)
		printf("nw[%d]:%d\n",i,nw[i]);

	/*for (i = 0; i < 30;i++ )
		printf("len %d,cnt %d;\n",i,nw[i]);*/
/*horizontal display*/
	for (i = 30;i > 0; i--)
	{
		printf("%d",i - 1);
		if(i-1 > 9)
		 printf("  |");
		else
		 printf("   |");
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
	for (i = 0;i < 30; i++)
		printf("nw[%d]:%d\n",i,nw[i]);

	for(i = nw[0];i >= 0; i--)
		{	printf("\n");
			if(i > 9)
		 		printf("%d   -",i);
			else
		 		printf("%d    -",i);
			j = 0;
			while (j < 30)
			{	if( nw[j] >= i )
					printf("%d ",j);
				else
					printf("0 ");
				j++;
			}
		}
	printf("\n");
}

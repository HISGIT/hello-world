#include <stdio.h>
/*Excercise E1-12 write a program that prints its input one word perline*/
main()
{
	int c;
	while ( (c = getchar()) )
	{
		if (c != ' ' &&  c != '\n' && c != '\t')
		{
			putchar(c);
			putchar('\n');
		}
	}
}

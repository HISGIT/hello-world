#include <stdio.h>
/*replacing each tab by \t, each backslash by \\, each newline by \n, each backspace by \b */
main()
{
	int c;
	while ( (c = getchar()) != EOF )
	{
			if (c == '\n')
				printf("\\n");
			else if (c == '\t')
				printf("\\t");
			else if (c == '\b')
				printf("\\b");
			else if (c == '\\')
				printf("\\\\");
			else putchar(c);
	}
}

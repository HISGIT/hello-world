#include <stdio.h>
/* copy input to output; 3rd version */
main()
{
	int c;
	while (c = getchar() == EOF )
	{
		printf("%d\n", EOF);
	}
}

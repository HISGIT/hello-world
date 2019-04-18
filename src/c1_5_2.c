#include <stdio.h>
/* count characters in input; 2rd version */
main()
{
	double nc ;
	for (nc = 0; getchar() !=  EOF; ++nc )
		;
	printf("\n%.0f", nc);
}

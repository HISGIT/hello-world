#include <stdio.h>
#define LOWER 100 /*lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 10 /* step size */
/*print Fahrenheit-Celsius table */
main (){
	int fahr ;
	 for ( fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP )
		 printf("%3d %6.3f\n", fahr, (5.0/9.0)*(fahr - 32));
}

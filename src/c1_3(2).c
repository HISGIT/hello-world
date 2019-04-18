#include <stdio.h>
/* print Fahrenheit-Celsius table */
main(){
	int fahr;
	for	(fahr = 300;fahr >= 0;fahr = fahr - 10)
		printf("%3d %6.3f\n", fahr, (5.0/9.0)*(fahr-32));
}

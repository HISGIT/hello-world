#include <stdio.h>
float conv_FtoC(float);
/*rewrite the temperature conversion program of session 1.2 to use a function for conversion*/
main()
{
	float i,lower,upper,step;
	step = 10;lower = 0;upper = 300;
	for(i = lower; i <= upper; i = i + step)
	printf("Celsius:%6.2f ,Fahrenheit:%6.2f\n",i,conv_FtoC(i));
	return 0;
}

float conv_FtoC(float Fahr)
{
	float C;
	C = (5.0/9.0)*(Fahr - 32);
	return C;
}

#include <stdio.h>
#define MAXLEN 1000

/*write a program to remove  trailing blanks and tabs from each line of input, and to delete entirely blanks lines*/
main()
{	int c,k,i,prenewline,nonspace;
	nonspace = c = prenewline = 0; k =-1;
	char blankline[MAXLEN];
	while( (c = getchar()) != EOF ){
		if(c == '\n'){
				if(prenewline == 0 && nonspace == 1) putchar('\n');
				prenewline = 1;/*false:printed a new line*/
				k = -1;/*reset pointer*/
				nonspace = 0;
		}else if (c == ' ' || c == '\t'){
			k++;
			if(k < MAXLEN) blankline[k] = c;
			prenewline = 0;/*false:printed a new line*/
		}else{
			if(k >= 0) 
				for(i = 0; i <= k; i++) putchar(blankline[i]);
			k = -1;/*reset pointer*/
			nonspace = 1;
			putchar(c);
			prenewline = 0;/*false:printed a new line*/
		}
	}
}


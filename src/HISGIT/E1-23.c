#include <stdio.h>
#define MAX_BUFFER 1024
/* write a program to remove  all comments from a C program. Don't forget to handle quoted strings and character constants properly */
/* comment "test comment" */
int comment_boundry = -1;
int quote_boundry = -1;
int in_comment = 0;
int getlines(char s[], int lim);
int outputOrNot(char line[], int i);
int main(void){
	extern int comment_boundry;
	int l,k;
	char line[MAX_BUFFER];
	while( (l=getlines(line, MAX_BUFFER)) > 0){
		for(k = 0; k < l; k++){
			if( outputOrNot(line, k) == 1)
							//printf("comment_boundry=%d,quote_boundry=%d,line[%d]:%c\n",comment_boundry,quote_boundry,k,line[k]);
							printf("%c",line[k]);
		}
		comment_boundry = quote_boundry = -1;
		in_comment = 0;
	}
	printf("comment /*test comment*/");
	return 0;
}
int getlines(char s[], int lim){
	int i,c;
	for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
		if( c == '\n'){
			s[i] = c;
			i++;
		}
		s[i] = '\0';
	return i;
}
//21"231"3
int outputOrNot(char s[], int i){
	int k = i;
	extern int comment_boundry;
	extern int quote_boundry;
	extern int in_comment;
		if(s[k] == '"')
			quote_boundry = k;
		else if(s[k] == '/' && s[k+1] == '*' )
			comment_boundry = k;
		else if(s[k] == '/' && s[k+1] == '/' )
			comment_boundry = k;
		else if(s[k-2] == '*' && s[k-1] == '/' )
			{
				if(comment_boundry < quote_boundry || quote_boundry == -1) 
					in_comment = 0;
				comment_boundry = k;
			}
		if(quote_boundry == -1 && comment_boundry > -1 )
			{
				in_comment = 1;
				return 0;
			}
		else if(in_comment == 1){
			return 0;
		}else
						return 1;
}

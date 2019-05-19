#include <stdio.h>
/* check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both and double, escape sequence, and comments*/
#define T 1
#define F 0
#define MAX_BUFFER 1024
#define parenthesis_l  '('
#define parentheis_r  ')'
#define bracket_l  '['
#define bracket_r  ']'
#define brace_l  '{'
#define brace_r  '}'
#define s_quote  '\''
#define b_quote  '"'

int column_location[MAX_BUFFER];
int row_location[MAX_BUFFER];
int level = 0;
int row = 1;
int in_quote = 0;
int state = 0;
int ToF = F;
void syn_chk(char left, char right, char l[], int length);
int comm_chk(char l[], int ix);
int getlines(char s[], int lim);

int main(void){
	int c;
	extern int level, state, row, ToF;
	char line[MAX_BUFFER];
	while( (c = getlines(line, MAX_BUFFER)) > 0 ){
		syn_chk(brace_l, brace_r, line, c);
		row++;
		if(ToF == T && state == T){
			state = F;
			ToF = F;
		}
	}
	while(level > 0 ){
	printf("line %d,column %d,unpaired %c\n",row_location[level], column_location[level], brace_l);
	level--;
	}
	return 0;
}
int getlines(char s[], int lim){
	int c,i;
	for(i = 0; i < lim -1 && (c= getchar()) != EOF && c != '\n'; i++)
					s[i] = c;
	if(c == '\n'){
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}
void syn_chk(char left, char right, char l[], int length){
	extern int column_location[];
	extern int row_location[];
	extern int level,in_quote,row;
	int index;	
	for( index = 0;index < length; index++){
		if(comm_chk(l, index) == F){	
			if(l[index] == left){
				level++;
				if(level > 0){
					row_location[level] = row;
					column_location[level] = index;
				}
			//	printf("row_location[%d]:%d,column_location[%d]:%d\n",level,row_location[level],level,column_location[level]);
			}
			else if(l[index] == right){
				level--;
			//	printf("row_location[%d]:%d,column_location[%d]:%d\n",level,row_location[level],level,column_location[level]);
			}
		}
	}
}
int comm_chk(char l[], int ix){
	extern int state, in_quote, ToF;
	if(in_quote == F && l[ix] == '/' && l[ix+1] == '/' && ToF == F ){
		state = T;
		ToF = T;
	}
	if(in_quote == F && state == F){	
		if (l[ix] == '/' && l[ix+1] == '*')
						ToF = T;
		else if(l[ix-2] == '*' && l[ix-1] == '/')
						ToF = F;
	}
	if( ToF == F ){
		if(l[ix] == b_quote){
				if(in_quote == F) 
								in_quote = T;
				else if(in_quote == T) 
								in_quote = F;
		}
	}
	return ToF;
}

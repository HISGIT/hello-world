#include <stdio.h>
#include <stdlib.h> 
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/*reverse polish calculator 
 add commands to print the top element of the stack without popping, to duplate 
 it, and swap the top two elements. Add a command to clear the stakc. */
int main(){
    int type;
    double op2, op1;
    char s[MAXOP];
    while((type = getop(s)) != EOF){
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '*':
                push(pop() * pop());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if(op2 != 0.0)
                    push(op1 - op2 * (long)(op1 / op2));
                else
                    printf("error: zero divisor\n");
                break;
            case 't':   /* print top element without popping*/
                op2 = pop();
                push(op2);
                printf("top element:%f\n%", op2);
                break;
            case 'c':
                while(pop() != 0.0)
                    ;
                break;
            case 's':
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }
    return 0;
}

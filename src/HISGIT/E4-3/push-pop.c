#include <stdio.h> 
#define MAXVAL 100 /* maxium depth of val stack */
int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f){
    if(sp < MAXVAL ){
        val[sp++] = f;
    }else
        printf("error: stack full, can't push %g\n", f);
}

double pop(){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

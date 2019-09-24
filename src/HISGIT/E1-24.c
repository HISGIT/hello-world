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
#define TT 2


int column_location[MAX_BUFFER];
int row_location[MAX_BUFFER];
int row = 1;
int QUOTED = F;
int COMMENT = F;
int CQ = F;
int syn_chk(char left, char right, char l[], int length,int column_location[], int row_location[], int level);
int comm_chk(char l[], int ix);
int getlines(char s[], int lim);

int main(){
    int lnth;
    extern int row;
    extern int column_location[], row_location[];
    int level , par_level , brkt_level , sq_level , dq_level;
    level = par_level = brkt_level = sq_level = dq_level = 0;
    char line[MAX_BUFFER];
    int par_col[MAX_BUFFER];
    int par_row[MAX_BUFFER];
    int brkt_col[MAX_BUFFER];
    int brkt_row[MAX_BUFFER];
    int sq_col[MAX_BUFFER];
    int sq_row[MAX_BUFFER];
    int dq_col[MAX_BUFFER];
    int dq_row[MAX_BUFFER];
    int ix;
    for(ix = 0; ix < MAX_BUFFER; ix++){
        column_location[ix] = 0;
        row_location[ix] = 0;
        par_col[ix] = 0;
        par_row[ix] = 0;
        brkt_col[ix] = 0;
        brkt_row[ix] = 0;
        sq_col[ix] = 0;
        sq_row[ix] = 0;
        dq_col[ix] = 0;
        dq_row[ix] = 0;
    }
    while( (lnth = getlines(line, MAX_BUFFER)) > 0 ){
        level = syn_chk(brace_l, brace_r, line, lnth, column_location, row_location, level);
        par_level = syn_chk(parenthesis_l, parentheis_r, line, lnth, par_col, par_row, par_level);
        brkt_level = syn_chk(bracket_l, bracket_r, line, lnth, brkt_col, brkt_row, brkt_level);
        sq_level = syn_chk(s_quote, s_quote, line, lnth, sq_col, sq_row, sq_level);
        dq_level = syn_chk(b_quote, b_quote, line, lnth, dq_col, dq_row, dq_level);
        row++;
    }
    while(level > 0|| par_level > 0|| brkt_level > 0|| sq_level > 0|| dq_level > 0){
        if(level > 0){
            printf("(end) line %d,column %d,unpaired %c\n",row_location[level], column_location[level], brace_l);
            level--;
        }
        if(par_level > 0){
            printf("level:%d, line %d,column %d,unpaired %c\n",par_level, par_row[par_level], par_col[par_level], parenthesis_l);
            par_level--;
        }
        if(brkt_level > 0 ){
            printf("level:%d, line %d,column %d,unpaired %c\n",brkt_level, brkt_row[brkt_level], brkt_col[brkt_level], bracket_l);
            brkt_level--;
        }
        if(sq_level > 0 ){
            printf("level:%d, line %d,column %d,unpaired %c\n",sq_level, sq_row[sq_level], sq_col[sq_level], s_quote);
            sq_level--;
        }
        if( dq_level > 0 ){
            printf("level:%d, line %d,column %d,unpaired %c\n", dq_level ,dq_row[dq_level], dq_col[dq_level], b_quote);
            dq_level--;
        }
    }
   // for(ix = 0; ix < 20; ix++){
   //     printf("level[%d]:(%d,%d),\n", ix, row_location[ix], column_location[ix]);
   // }
   // for(ix = 0; ix < par_level+1; ix++){
   //     printf("level[%d]:(%d,%d),\n", ix, par_row[ix], par_col[ix]);
   // }
 
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
int syn_chk(char left, char right, char l[], int length,int column_location[], int row_location[], int level){
    extern int row, QUOTED,CQ;
    int index; 
    for( index = 0;index < length + 1; index++){
        if(comm_chk(l, index) == F){
            if(left == s_quote || left == b_quote){
                if(l[index] == s_quote && QUOTED == T && CQ == T){
                    level++;
                    if(level > 0 ){
                        row_location[level] = row;
                        column_location[level] = index+1;
                        printf("(processing0-1)\n");
                    }
                    CQ = F;
                }else if(l[index] == s_quote && QUOTED == F && CQ == T){
                    level--;
                    if(level < 0)
                        printf("(processing0-2) line %d,column %d,unpaired %c\n",row, index+1, right);
                    CQ = F;
                }
                if(l[index] == b_quote && QUOTED == TT && CQ == TT){
                    level++;
                    if(level > 0 ){
                        row_location[level] = row;
                        column_location[level] = index+1;
                        printf("(processing1-1)\n");
                    }
                    CQ = F;
                }else if(l[index] == b_quote && QUOTED == F && CQ == TT){
                    level--;
                    if(level < 0)
                        printf("(processing1-2) line %d,column %d,unpaired %c\n",row, index+1, right);
                    CQ = F;
                }
            }else{
                if(l[index] == left && QUOTED == F){
                    level++;
                    if(level > 0 ){
                        row_location[level] = row;
                        column_location[level] = index+1;
                        printf("(processing4-1)\n");
                    }
                }else if(l[index] == right && QUOTED == F){
                    level--;
                    if(level < 0)
                        printf("(processing4-2) line %d,column %d,unpaired %c\n",row, index+1, right);
                }
            }
        }
    }
    return level;
}
int comm_chk(char line[], int k){
    extern int COMMENT, QUOTED, CQ;
    if(COMMENT > F){
        if(line[k] == '\n' && COMMENT == TT)
            COMMENT = F;
        if(line[k-2] == '*' && line[k-1] == '/' && COMMENT == T)
            COMMENT = F;
    }else {
       if(QUOTED == F){ 
            if(line[k] == '/' && line[k + 1] == '/')
                COMMENT = TT;
            if(line[k] == '/' && line[k + 1] == '*')
                COMMENT = T;
            if(line[k] == '"'){
                QUOTED = TT;
                CQ = TT;
            }
            if(line[k] == '\''){
                QUOTED = T;
                CQ = T;
            }
       }else{
           if(line[k] == '"' && QUOTED == TT){
               CQ = TT;
               QUOTED = F;
           }
           if(line[k] == '\'' && QUOTED == T){
               if(line[k-2] == '\\' && line[k-3] == '\''){
                   CQ = T;
                   QUOTED = F;
               }
               else if(line[k-2] == '\'' && line[k+1] != '\''){
                   CQ = T;
                   QUOTED = F;
               }
           }
       }
    }    
    return COMMENT;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_TOKENS 1000

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PARENTHESIS
} TokenType;

typedef struct {
    TokenType type;
    union {
        double num ;
        char op;
    } data;
}Token;


int tokenize(char * expr , Token tokens[] , int max){


    int count =0;
    int pos =0;
while (expr[pos] !='\0')
{
    if(expr[pos] == ' '){
        pos++;
        continue;
    }

    if(isdigit(expr[pos]) || expr[pos]=='.'){
        char *end;
        double val = strtod(&expr[pos] , &end);

        tokens[count].type = TOKEN_NUMBER;
        tokens[count].data.num = val;
        count++;
        pos = end-expr;
        continue;
    }

    if(strchr("/+-*^" , expr[pos])){
        tokens[count].type =TOKEN_OPERATOR;
        tokens[count].data.op= expr[pos];
        pos++;
        count++;
        continue;
    }

    if(expr[pos] =='(' || expr[pos]==')'){
        tokens[count].type = TOKEN_PARENTHESIS;
        tokens[count].data.op= expr[pos];
        pos++;
        count++;
        continue;
    }

        printf("invalid expression be carefull %c" , expr[pos]);
        return -1;
}
    return count;
}


int precendence(char operator){
    if(operator=='+' || operator == '-') return 1;
    if(operator=='*' || operator == '/') return 2;
    if(operator=='^') return 3;
}

int rightAssociative(char operator){
    if(operator=='^') return 1;
    else{
        return 0;
    }
}






int main() {
    char expr[256];
    Token tokens[MAX_TOKENS];

    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);   // read input from user
    expr[strcspn(expr, "\n")] = '\0';   // strip newline

    int count = tokenize(expr, tokens, MAX_TOKENS);

    if (count == -1) {
        printf("Error in tokenization.\n");
        return 1;
    }

    printf("Tokenized %d tokens:\n", count);
    for (int i = 0; i < count; i++) {
        if (tokens[i].type == TOKEN_NUMBER)
            printf("NUMBER: %f\n", tokens[i].data.num);
        else if (tokens[i].type == TOKEN_OPERATOR)
            printf("OPERATOR: %c\n", tokens[i].data.op);
        else if (tokens[i].type == TOKEN_PARENTHESIS)
            printf("PARENTHESIS: %c\n", tokens[i].data.op);
    }

    return 0;
}
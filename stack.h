#ifndef STAKC_H

#define Stack_H

typedef struct Node{
    char data;
    Node *next;
} Node;

typedef Node* Stack;

void initStack(Stack * s);
int isEmpty(Stack  *s);
char peek(Stack *s );
char pop(Stack *s);
void push(Stack*s , char element);



#endif
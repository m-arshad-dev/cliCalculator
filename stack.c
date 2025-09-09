#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


void initStack(Stack *s){
    return *s = NULL;
}

int isEmpty(Stack *s ){
    return *s ==NULL;
}
void push(Stack *s  , char val){
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(!newNode){
        printf("Memory allocation failed \n");
        return -1;
    }
    newNode->data = val;
    newNode->next = *s;
    *s = newNode;
}

char pop(Stack *s){
    if(isEmpty(s)){
        printf("The stack underflowed \n");
        return '\0';
    }
    Node* temp = *s;
    char val = temp->data;
     *s = temp->next;
     free(temp);
     return val;
}

char peek(Stack *s){
    if(isEmpty(s)){
        printf("The stack underflowed \n");
        return '\0';
    }
    return (*s)->data;
}
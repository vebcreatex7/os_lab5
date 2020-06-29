#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct stack_el stack_el;

struct stack_el {
    int val;
    stack_el* tail;
};

typedef struct {
    stack_el* top;
} stack;

stack* s_create();
bool s_push(stack* s, int val);
bool s_empty(stack* s);
int s_pop(stack* s);
void s_destroy(stack* s);
void s_print(stack* s);


#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


stack* s_create()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s -> top = NULL;
    return s;
}

bool s_push(stack* s, int val)
{
    stack_el* v = (stack_el*)malloc(sizeof(stack_el));
    if (v == NULL) {
        return false;
    }
    v -> val = val;
    v -> tail = s -> top;
    s -> top = v;
    return true;
}


bool s_empty(stack* s)
{
    return s -> top == NULL;
}


int s_pop(stack* s)
{
    stack_el* v = s -> top;
    int val = v -> val;
    s -> top = v -> tail;
    free(v);
    return val;
}


void s_destroy(stack* s)
{
    while (!s_empty(s)) {
        s_pop(s);
    }
    free(s);
}

void s_print(stack* s) {
    stack_el* tmp = s->top;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->tail;
    }
}


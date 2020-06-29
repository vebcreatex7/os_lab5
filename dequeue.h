#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAP 1000

typedef struct {
    int body[CAP];
    size_t size;
    int front;
} dequeue;

dequeue* d_create();
void d_destroy(dequeue* d);
bool d_push_back(dequeue* d, int val);
int d_pop_front(dequeue* d);
bool d_push_front(dequeue* d, int val);
int d_pop_back(dequeue* d);
bool d_empty(dequeue* d);
void d_print(dequeue* d);

#endif


#include "dequeue.h"

dequeue* d_create()
{
    dequeue* d = (dequeue*)malloc(sizeof(dequeue));
    d -> size = 0;
    d -> front = 0;
    return d;
}


void d_destroy(dequeue* d)
{
    d->size = 0;
    d->front = 0;
    free(d);
}
int d_size(dequeue* d)
{
    return d->size;
}


bool d_push_back(dequeue* d, int val)
{
    if (d -> size < CAP) {
        d -> body[(d -> front + d -> size) % CAP] = val;
        d -> size++;
        return true;
    }
    return false;
}


int d_pop_front(dequeue* d)
{
    int val = d -> body[d -> front];
    d -> size--;
    d -> front = (d -> front + 1) % CAP;
    return val;
}


bool d_push_front(dequeue* d, int val)
{
    if (d -> size == CAP) {
        return false;
    }
    d -> front = (d -> front - 1 + CAP) % CAP;
    d -> body[d -> front] = val;
    d -> size++;
    return true;
}


int d_pop_back(dequeue* d)
{
    int val = d -> body[(d -> front + d -> size - 1) % CAP];

    d -> size--;
    return val;
}

bool d_empty(dequeue* d)
{
    return d->size == 0;
}

void d_print(dequeue* d)
{
    
    int i = 0;
    int count = 0;
    if (d->front != 0) {
        count = d->front;
        for (count; count < CAP; count++) {
            printf("%d ", d->body[count]);
            i++;
        }
    }
    if (i < d->size) {
        count = 0;
        for (i; i < d->size; i++) {
            printf("%d ", d->body[count]);
            count++;
        }
    }


}

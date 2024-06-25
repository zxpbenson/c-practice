#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <pthread.h>

#define QUEUE_SIZE 10

typedef struct {
    int buffer[QUEUE_SIZE];
    int head;
    int tail;
    int size;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} queue;

queue* queue_init();
void queue_destroy(queue* q);
int queue_push(queue* q, int value);
int queue_pop(queue* q);

#endif

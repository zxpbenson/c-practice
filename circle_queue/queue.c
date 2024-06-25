#include "queue.h"
#include <stdlib.h>

queue* queue_init() {
    queue* q = malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->not_empty, NULL);
    pthread_cond_init(&q->not_full, NULL);
    return q;
}

void queue_destroy(queue* q) {
    pthread_mutex_destroy(&q->lock);
    pthread_cond_destroy(&q->not_empty);
    pthread_cond_destroy(&q->not_full);
    free(q);
}

int queue_push(queue* q, int value) {
    pthread_mutex_lock(&q->lock);

    while (q->size == QUEUE_SIZE) {
        pthread_cond_wait(&q->not_full, &q->lock);
    }

    q->buffer[q->tail] = value;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->size++;

    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->lock);

    return 0;
}

int queue_pop(queue* q) {
    pthread_mutex_lock(&q->lock);

    while (q->size == 0) {
        pthread_cond_wait(&q->not_empty, &q->lock);
    }

    int value = q->buffer[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->size--;

    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->lock);

    return value;
}


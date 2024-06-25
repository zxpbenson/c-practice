#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdatomic.h>

#define QUEUE_SIZE 1024

typedef struct {
    int buffer[QUEUE_SIZE];
    atomic_uint read_index;
    atomic_uint write_index;
} lockfree_queue;

void queue_init(lockfree_queue *q) {
    atomic_init(&q->read_index, 0);
    atomic_init(&q->write_index, 0);
}

bool queue_push(lockfree_queue *q, int value) {
    const uint32_t current_write = atomic_load_explicit(&q->write_index, memory_order_relaxed);
    const uint32_t next_write = (current_write + 1) % QUEUE_SIZE;
    if (next_write == atomic_load_explicit(&q->read_index, memory_order_acquire)) {
        // Queue is full
        return false;
    }
    q->buffer[current_write] = value;
    atomic_store_explicit(&q->write_index, next_write, memory_order_release);
    return true;
}

bool queue_pop(lockfree_queue *q, int *value) {
    const uint32_t current_read = atomic_load_explicit(&q->read_index, memory_order_relaxed);
    if (current_read == atomic_load_explicit(&q->write_index, memory_order_acquire)) {
        // Queue is empty
        return false;
    }
    *value = q->buffer[current_read];
    const uint32_t next_read = (current_read + 1) % QUEUE_SIZE;
    atomic_store_explicit(&q->read_index, next_read, memory_order_release);
    return true;
}

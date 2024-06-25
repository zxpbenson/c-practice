#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *buffer;    // 队列存储元素的数组
    int capacity;   // 队列容量
    int front;      // 队头指针
    int rear;       // 队尾指针
    pthread_mutex_t lock;   // 互斥锁
} queue;

// 创建队列
queue *queue_create(int capacity) {
    queue *q = malloc(sizeof(queue));
    q->buffer = malloc(capacity * sizeof(int));
    q->capacity = capacity;
    q->front = q->rear = 0;
    pthread_mutex_init(&q->lock, NULL);
    return q;
}

// 销毁队列
void queue_destroy(queue *q) {
    free(q->buffer);
    pthread_mutex_destroy(&q->lock);
    free(q);
}

// 入队操作
int queue_push(queue *q, int value) {
    pthread_mutex_lock(&q->lock);
    if ((q->rear + 1) % q->capacity == q->front) {
        pthread_mutex_unlock(&q->lock);
        return -1;  // 队列已满
    }
    q->buffer[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    pthread_mutex_unlock(&q->lock);
    return 0;
}

// 出队操作
int queue_pop(queue *q, int *value) {
    pthread_mutex_lock(&q->lock);
    if (q->front == q->rear) {
        pthread_mutex_unlock(&q->lock);
        return -1;  // 队列为空
    }
    *value = q->buffer[q->front];
    q->front = (q->front + 1) % q->capacity;
    pthread_mutex_unlock(&q->lock);
    return 0;
}

// 判断队列是否为空
int queue_empty(queue *q) {
    pthread_mutex_lock(&q->lock);
    int is_empty = (q->front == q->rear);
    pthread_mutex_unlock(&q->lock);
    return is_empty;
}

// 判断队列是否已满
int queue_full(queue *q) {
    pthread_mutex_lock(&q->lock);
    int is_full = ((q->rear + 1) % q->capacity == q->front);
    pthread_mutex_unlock(&q->lock);
    return is_full;
}



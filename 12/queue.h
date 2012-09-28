#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>

struct sNode{
    int data;            /* 值域 */
    struct sNode *next;        /* 链接指针 */
};

struct queueLK{
    struct sNode *front;    /* 队首指针 */
    struct sNode *rear;        /* 队尾指针 */
};

void initQueue(struct queueLK *hq);
void enQueue(struct queueLK *hq, int x);
int outQueue(struct queueLK *hq);
int peekQueue(struct queueLK *hq);
int emptyQueue(struct queueLK *hq);
void clearQueue(struct queueLK *hq);

#endif

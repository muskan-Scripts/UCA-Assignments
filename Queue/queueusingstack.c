#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int stk1[100];
    int top1;
    int stk2[100];
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stk1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 >= 0) {
            obj->stk2[++obj->top2] = obj->stk1[obj->top1--];
        }
    }
    return obj->stk2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 >= 0) {
            obj->stk2[++obj->top2] = obj->stk1[obj->top1--];
        }
    }                   
    return obj->stk2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* queue = myQueueCreate();

    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);

    printf("Front element of the queue: %d\n", myQueuePeek(queue));

    printf("Dequeued element is: %d\n", myQueuePop(queue));

    myQueueFree(queue);

    return 0;
}

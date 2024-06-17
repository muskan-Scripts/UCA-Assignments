#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);

bool myCircularQueueDeQueue(MyCircularQueue* obj);

int myCircularQueueFront(MyCircularQueue* obj);

int myCircularQueueRear(MyCircularQueue* obj);

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);

void myCircularQueueFree(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(k * sizeof(int));
    obj->front = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj) || (obj->front == -1 && (obj->front = 0) == 0)) return false;
    obj->rear = (obj->rear + 1) % obj->size;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;
    if (obj->front == obj->rear && ((obj->front = -1) == -1 && (obj->rear = -1) == -1)) return true;
    obj->front = (obj->front + 1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == (obj->rear + 1) % obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    int k = 5;
    MyCircularQueue* obj = myCircularQueueCreate(k);

    for (int i = 1; i <= 5; i++) myCircularQueueEnQueue(obj, i);

    printf("Front: %d\n", myCircularQueueFront(obj));  // Output: 1
    printf("Rear: %d\n", myCircularQueueRear(obj));    // Output: 5

    myCircularQueueDeQueue(obj);
    myCircularQueueEnQueue(obj, 6);

    printf("Front: %d\n", myCircularQueueFront(obj));  // Output: 2
    printf("Rear: %d\n", myCircularQueueRear(obj));    // Output: 6

    myCircularQueueFree(obj);

    return 0;
}

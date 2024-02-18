#include <stdio.h>
#define MaxQueueSize 5

typedef struct Queue {
    int CurrentSize;
    int Value[MaxQueueSize];
    int Front; // 头指针
    int Rear; // 尾指针
} Queue;

void InitializeQueue(Queue* queue) {
    queue->CurrentSize = 0;
    queue->Front = queue->Rear = 0;
    for (int i = 0; i < MaxQueueSize; i++) 
        queue->Value[i] = 0;
}

int IsFull(Queue* queue) {
    return (queue->Rear + 1) % MaxQueueSize == queue->Front;
}

int IsEmpty(Queue* queue) {
    return queue->Front == queue->Rear;
}

void Push(Queue* queue, int item) {
    // 入队一个元素，如果队列满了，则报错。
    if (IsFull(queue)) {
        printf("队列满咯~\n");
        return;
    }

    queue->Value[queue->Rear] = item;
    queue->Rear = (queue->Rear + 1) % MaxQueueSize; // 尾指针往后循环偏移一个单位
}

int Pop(Queue* queue) {
    // 出队一个元素，如果队列空，则报错。
    if (IsEmpty(queue)) {
        printf("队列空咯~\n");
        return 0;
    }

    int result = queue->Value[queue->Front];
    queue->Front = (queue->Front + 1) % MaxQueueSize;
    return result;
}

int GetFront(Queue* queue) {
    // 取队列的第一个元素，不出队，如果队列空，则报错。
    if (IsEmpty(queue)) {
        printf("队列空咯~\n");
        return 0;
    }

    return queue->Value[queue->Front];
}

void Traverse(Queue* queue) {
    if (IsEmpty(queue)) {
        printf("队列空咯~\n");
        return;
    }

    while (!IsEmpty(queue)) {
        printf("%d ", queue->Value[queue->Front]);
        queue->Front = (queue->Front + 1) % MaxQueueSize;
    }
}

int main() {
    Queue queue;
    InitializeQueue(&queue);

    // 按序列执行
    Push(&queue, 5);
    Push(&queue, 3);
    Push(&queue, 14);
    Push(&queue, 19);
    Pop(&queue);
    Pop(&queue);
    Push(&queue, 20);
    Pop(&queue);
    Pop(&queue);
    Push(&queue, 17);

    // 打印队列元素
    Traverse(&queue);
    return  0;
}
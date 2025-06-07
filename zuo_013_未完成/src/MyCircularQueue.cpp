#include "MyCircluarQueue.h"

// 测试链接https://leetcode.cn/problems/design-circular-queue/
MyCircularQueue::MyCircularQueue(int k) {
    myQueue = new int[k];
    capacity = k;
}

bool MyCircularQueue::isEmpty() {
    return  size == 0;                                                                                                                                                                                                             ;
}

bool MyCircularQueue::isFull() {
    return size >= capacity;
}

bool MyCircularQueue::enQueue(int value) {
    if (isFull) return false;

    if (rear == capacity ) {
        rear = 0;
        myQueue[0] = value;
    } else {
        myQueue[rear++] = value;
    }
    size++;
    return true;
}

bool MyCircularQueue::deQueue() {
    if (isEmpty()) return false;

    if (front == capacity ) {
        front = 0;
    }else front++;
    
    size--;
    return true;
}

int MyCircularQueue::Front() {
    return isEmpty() ? -1 : myQueue[front];
}

int MyCircularQueue::Rear() {
    return isEmpty() ? -1 : myQueue[rear];
}
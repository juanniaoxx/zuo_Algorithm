#include "main.h"
#include "queue.h"

Queue::Queue(int capacity) : queue(new int[capacity]), capacity(capacity) {}

Queue::~Queue() {
    delete[] queue;
}

void Queue::inqueue(int x) {
    if (isfull()) {
        throw std::overflow_error("Queue is full");
    }
    queue[rear++] = x;
}

int Queue::dequeue() {
    if (isempty()) {
        throw std::underflow_error("Queue is empty");
    }

    return queue[front++];
}
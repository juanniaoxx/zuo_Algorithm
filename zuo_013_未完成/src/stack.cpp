#include "stack.h"
#include "main.h"

Stack::Stack(int capacity) : stack(new int[capacity]), capacity(capacity) {}

Stack::~Stack() {
    delete[] stack;
}

void Stack::push(int x) {
    if (isFull()) {
        throw std::overflow_error("Stack overflow");
    } else stack[size++] = x;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow");
    }
    return stack[--size];
}

int Stack::peek() {
    if (isEmpty()) {
        throw std::underflow_error("stack is empty");
    }
    return stack[size - 1];
}
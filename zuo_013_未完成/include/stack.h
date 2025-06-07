#ifndef Stack_H
#define Stack_H

#include <stdexcept>
// 用数组实现栈
class Stack {
    public:
    // 构造函数
    Stack(int capacity);
    // 禁用拷贝
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    // 析构函数
    ~Stack();
    // 压入栈顶
    void push(int x);
    // 弹出栈顶
    int pop();
    // 查看栈顶元素
    int peek();
    // 返回栈的大小
    int getSize() { return size; }

    private:
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= capacity; }
    int *stack;
    int size = 0;
    int capacity;
};

#endif // Stack_H

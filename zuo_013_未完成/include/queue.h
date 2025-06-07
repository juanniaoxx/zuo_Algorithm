#ifndef QUEUE_H
#define QUEUE_H


// 简单的非循环队列 -- 数组实现
class Queue {
    public:
    // 构造函数
    Queue(int capacity);

    // 禁用copy
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // 析构函数
    ~Queue();

    // 入队操作
    void inqueue(int x);
    // 出队操作
    int dequeue();
    // 队的大小
    int getSize() { return (rear - front); }

    private:
    int front = 0, rear = 0;
    int *queue;
    int capacity;
    // 非循环队列需要考虑数组的物理边界
    bool isfull() { return (rear - front) >= capacity || rear >= capacity; }
    bool isempty() { return (rear - front) == 0; }
};
#endif 
class MyCircularQueue {
    public:
        MyCircularQueue(int k);        
        bool enQueue(int value);        
        bool deQueue();        
        int Front();        
        int Rear();        
        bool isEmpty();        
        bool isFull();
    private:
        int size = 0;
        int *myQueue;
        int rear = 0, front = 0;
        int capacity;
    };
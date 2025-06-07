#include "main.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main(void) {
    Stack stack(10);
    Queue queue(10);
    int testNumbers[10] = {1, 2, 3, 4, 5, 6};
    cout << "This testNumbers is : ";
    for (int i = 0; i < 10; i ++) cout << testNumbers[i] << " ";
    cout << endl;
    for (int i = 0; i < 10; i ++) stack.push(testNumbers[i]);
    cout << "The stack size is : " << stack.getSize() << " and they are :";
    for (int i = 0; i < 10; i ++) cout << stack.pop() << " ";
    cout << endl;

    for (int i = 0; i < 10; i ++) queue.inqueue(testNumbers[i]);
    cout << "The queue size is : " << queue.getSize() << " and they are :";
    for (int i = 0; i < 10; i ++) cout << queue.dequeue() << " ";
    cout << endl;

    cout << "the size of stack is " << stack.getSize();
    cout << " ,the size of queue is " << queue.getSize();
    cout << endl;
    return 0;
}
#include <iostream>

using namespace std;
const int N = 1e5 + 10;

// 对于大根堆向下调整(元素变小)
void heapfy(int *heap, int i, int size) {
    
    while (i < size) {
        // 左孩子
        int l = i * 2 + 1;
        if (l >= size) break; //没有左孩子直接break,基于完全二叉树的性质
        // 判断右孩子是否存在，且与左孩子的大小关系
        int best = (l + 1 < size && heap[l + 1] > heap[l]) ? l + 1 : l;
        // 判断选出来的孩子节点是否比父节点大
        best = heap[best] > heap[i] ? best : i;
        while (best == i) break;
        swap(heap[best], heap[i]);
        
        i = best;
    }
}

// 对于大根堆向上调整(插入元素或者元素变大)
void heapInsert(int *heap, int i) {
    while (heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


/*
    heapSort 堆排序
    时间复杂度O(nlogn)
        自定向上建堆O(n)
        自顶向下建堆O(nlogn)
    空间复杂度O(1)
    测试链接https://www.acwing.com/problem/content/789/
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int q[N];

void heapInsert(int *q, int i);
void heapfy(int *q, int i, int size);
void heapSort(int *q, int n);
int main() {
    int n = 0;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    heapSort(q, n);
    for (int i = 0; i < n; i++) printf("%d ",q[i]);
    cout << endl;
    return 0;
}

void heapSort(int *q, int n) {
    // 不优化-自顶向下建立堆
    // for (int i = 0; i < n; i++) heapInsert(q, i);
    // 优化-自底向上建立堆
    for (int i = n / 2 - 1; i >= 0; i--) heapfy(q, i, n);
    for (int i = n - 1; i; i--) {
        swap(q[0], q[i]);
        heapfy(q, 0, i);
    }

}

void heapInsert(int *q, int i) {
    while (q[i] > q[(i - 1) / 2]) {
        swap(q[i], q[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapfy(int *q, int i, int size) {
    while (i < size) {
        int l = i * 2 + 1;
        if (l >= size) break;
        int best = (l + 1 < size && q[l + 1] > q[l]) ? l + 1 : l;
        best = (q[best] > q[i]) ? best : i;
        if (best == i) break;
        swap(q[best], q[i]);
        i = best;
    }
}
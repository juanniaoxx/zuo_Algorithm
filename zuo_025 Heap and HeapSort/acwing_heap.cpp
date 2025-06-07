// TODO理解这个模板的意思
// h[N]存储堆的值， h[1]是堆顶, x的左儿子是2x, 右儿子是2x-1
// ph[k]存储地k个插入的点在堆中的位置
// hp[k]存储堆中下标k的点是第一个插入的
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int h[N], ph[N], hp[N], heap_size;

// 交换两个点，及其映射关系
void heap_swap(int a,int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= heap_size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= heap_size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main() {
    int n = 0;
    /* ..... */
    // O(n)建堆
    for (int i = n / 2; i; i--) down(i);
    return 0;
}
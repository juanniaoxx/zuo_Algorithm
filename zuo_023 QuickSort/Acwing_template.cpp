/*
    Acwing-Template
*/

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int q[N], n;

void quickSort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

int main() {
    scanf("%d", &n);
    // 处理输入
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quickSort(0, n - 1);
    // 处理输出
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}
/*
    iteration version
    step by step 
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int q[N], temp[N];

void merge_sort(int q[N], int size)  {
    int l = 0, r = 0, m = 0;
    
    // 每一步增长一倍容量
    // time complexity : O(log n)
    for (int step = 1; step < size; step <<= 1) {
        // 初始化左边界
        l = 0;
        while (l < size) {
            m = l + step - 1;
            // 判断是否有右侧
            if (m + 1 >= size) {
                break;
            }

            // 求右侧有边界
            r = min(l + (step << 1) - 1, size - 1);
            // 归并操作
            // O(n)
            merge(q, l, m, r);
            l = r + 1;
        }
    }
}

// 归并操作
void merge(int q[N], int l, int m, int r) {

}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    merge_sort(q, n);
    for (int i = 0; i < n; i++) printf("%d", q[i]);
    return 0;
}
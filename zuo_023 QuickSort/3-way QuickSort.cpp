/*
    基于荷兰国旗的优化版本
    时间复杂度: O(nlog n)
    空间复杂度: O(log n)
    测试链接https://www.acwing.com/problem/content/787/
*/

#include <iostream>
#include <random>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int q[N], n;

void quickSort(int, int);
PII partition(int, int, int);
int main() {
    srand(time(0));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}

void quickSort(int l, int r) {
    if (l >= r) return;

    // 从l...r中等概率选取一个数
    int x = q[l + (int)rand() % (r - l + 1)];
    // 划分选取值的范围 first,....,last 
    PII position = partition(l, r, x);
    quickSort(l, position.first - 1);
    quickSort(position.second + 1, r);
}

// 划分函数
PII partition(int l, int r, int x) {
    // 已知q[l....r]范围上一定有x这个值
	// 划分数组 <x放左边，==x放中间，>x放右边
    int first = l;
    int last = r;
    int i = l;
    while (i <= last) {
        if (q[i] == x) i++;
        else if (q[i] < x) swap(q[first++], q[i++]);
        else swap(q[i], q[last--]);
    }
    return {first, last};
}
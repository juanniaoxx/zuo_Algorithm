/*
    一般不考虑这个写法
    采用随机化处理的Lomuto分区快速排序
    时间复杂度: O(nlog n)
    空间复杂度: O(log n)
    测试链接https://www.acwing.com/problem/content/787/
*/

#include <iostream>
#include <random>
using namespace std;

const int N = 1e5+10;
int q[N];

// 划分函数
int partition(int l, int r, int x) {
    // 从左边开始遍历
    // xi记录的为x的位置
    // a记录的为小于等于x的边界
    int a = l, xi = 0;
    for (int i = l; i <= r; i++) {
        if (q[i] <= x) {
            swap(q[a], q[i]);
            if (q[a] == x) {
                xi = a;
            }
            a++;
        }
        // 如果q[i] > x什么都不需要做只需要移动i即可
    }
    // 将一个x移动到<=的右边界上
    swap(q[xi], q[a - 1]);
    return a - 1;
}

// 最重要的思想为通过一次划分使得数据变成 .....(<) x (>)......
// 然后从左右两边分别递归这个过程，最终数据就会变有序
void quickSort(int l, int r) {
    if (l >= r) return ;

    // 随机确定划分值
    // 从l...r中随机选择一个作为划分值
    int x = q[l + (int)rand() % (r - l + 1)];
    int mid = partition(l, r, x);
    quickSort(l, mid - 1);
    quickSort(mid + 1, r);
}

int main() {
    int n = 0;
    srand(time(0)); // 设置随机种子
    scanf("%d", &n);
    // 处理输入
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quickSort(0, n - 1);
    // 处理输出
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}
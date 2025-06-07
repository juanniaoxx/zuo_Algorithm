/*
    基数排序
    测试链接1 Acw风格：
    https://www.luogu.com.cn/problem/P1177 或者 https://www.acwing.com/problem/content/787/
    测试链接2 填函数风格:
    https://leetcode.cn/problems/sort-an-array/
    时间复杂度 O(N)
    空间复杂度 O(M)
*/

#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e5 + 10;
const int BASE = 10; // 10进制
int cnts[BASE], n;
int arr[N], help[N];

void sort();
void radixSort(int bits);
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort();
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    cout << endl;

    return 0;
}

void sort() {
    // 判断是否有负数
    int min = arr[0];
    for (int i = 1; i < n; i++) min = min < arr[i] ? min : arr[i];
    int max = 0;
    // 减去最小值，如果有负数则会被转换为正数 
    // 但这里是有可能溢出的
    for (int i = 0; i < n; i++) {
        arr[i] -= min;
        max = max > arr[i] ? max : arr[i];
    }

    int bits = 0;
    for (; max > 0; max /= BASE) bits++;
    radixSort(bits);

    // 还原数据
    for (int i = 0; i < n; i++) {
        arr[i] += min;
    }
}

// 基数排序的核心代码
// arr中保证不会有负数 由sort保证
void radixSort(int bits) {
    for (int offset = 1; bits > 0; offset *= BASE, bits--) {
        memset(cnts, 0, sizeof(cnts));
        for (int i = 0; i < n; i++) {
            // 一次提取一位
            cnts[(arr[i] / offset) % BASE]++;
        }
        for (int i = 1; i < n; i++) {
            // 计算前缀和
            cnts[i] = cnts[i] + cnts[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            // 前缀数量分区技巧
            help[--cnts[(arr[i] / offset) % BASE]] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            // 每次排序的结果拷贝回去
            arr[i] = help[i];
        }
    }
}
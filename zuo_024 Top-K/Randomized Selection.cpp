/*
    无序数组中第K大的元素(随机选择问题)
    测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/
    题目强调的必须使用O(n)的算法完成这道题
*/

#include <iostream>
#include <random>
using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int q[N], n, k;

int quickSelect(int);
PII partition(int, int, int);

int main(void) {
    scanf("%d %d",&n,&k);
    srand(time(0));
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    // 题目的k是1-base的而数组是0-base
    cout << quickSelect(k - 1) << endl;

    return 0;
}

int quickSelect(int k) {
    int ans = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        PII range = partition(l, r, q[l + (int) rand() % (r - l + 1)]);
        if (k < range.first) {
            r = range.first - 1;
        } else if (k > range.second) {
            l = range.second + 1;
        } else {
            return q[k];
        }
    }
    return -1;
}

PII partition(int l,int r, int x) {
    int first = l;
    int last = r;
    int i = l;
    while (i <= last) {
        if (q[i] == x) i++;
        else if(q[i] < x) swap(q[first++], q[i++]);
        else swap(q[i], q[last--]);
    }

    return {first, last};
}


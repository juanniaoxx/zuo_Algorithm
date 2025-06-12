/*
测试链接：https://www.luogu.com.cn/problem/P5026
*/
#include <iostream>
#include <array>

using namespace std;

// 定义常量
const int N = 1e6 + 10;        // 数组大小上限
const int OFFSET = 3e4 + 10;   // 偏移量，用于处理负数索引

int n = 0, m = 0;              // n: 操作次数, m: 查询范围

// 差分数组，使用足够大的空间来避免越界
array<int, OFFSET * 2 + N> diff;


void set(int l, int r, int s, int e, int d) {
    // 在差分数组中进行区间修改
    // 这里使用了4个点来记录区间修改的信息
    diff[l + OFFSET] += s;            // 区间起点加s
    diff[l + 1 + OFFSET] += d - s;    // 下一个点加(d-s)
    diff[r + 1 + OFFSET] -= d + e;    // 区间终点后减(d+e)
    diff[r + 2 + OFFSET] += e;        // 再下一个点加e
}


void fall(int v, int x) {
    // 将下落过程分解为4个区间进行修改
    // 这些区间和对应的修改值看起来是在模拟某种物理运动
    
    // 第一段区间: x-3v+1 到 x-2v
    set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
    
    // 第二段区间: x-2v+1 到 x
    set(x - 2 * v + 1, x, v - 1, -v, -1);
    
    // 第三段区间: x+1 到 x+2v
    set(x + 1, x + 2 * v, -v + 1, v, 1);
    
    // 第四段区间: x+2v+1 到 x+3v-1
    set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

/**
 * 构建前缀和数组，计算最终结果
 */
void build() {
    // 第一次前缀和
    for (int i = 1; i <= m + OFFSET; i++) diff[i] += diff[i - 1];
    // 第二次前缀和
    for (int i = 1; i <= m + OFFSET; i++) diff[i] += diff[i - 1];
}

int main() {
    // 读取输入
    scanf("%d %d", &n, &m);
    
    // 处理n次操作
    for (int i = 0, v, x; i < n; i++) {
        scanf("%d %d", &v, &x);
        fall(v, x);  // 模拟每次下落过程
    }
    
    // 构建最终结果
    build();
    
    // 输出结果
    int start = OFFSET + 1;  // 从偏移后的1开始输出
    printf("%d", diff[start++]);  // 输出第一个结果
    for (int i = 2; i <= m; i++) {  // 输出剩余结果
        printf(" %d", diff[start++]);
    }
    printf("\n");
    
    return 0;
}
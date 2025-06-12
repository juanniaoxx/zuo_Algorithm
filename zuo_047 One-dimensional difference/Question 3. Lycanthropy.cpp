/*
    测试链接：https://www.luogu.com.cn/problem/P5026
*/
#include <iostream>
#include <array>

using namespace std;

const int N = 1e6 + 10;
const int OFFSET = 3e4 + 10;
int n = 0, m = 0;
// 差分数组
array<int, OFFSET * 2 + N> diff;
// 构建差分数组
void set(int l, int r, int s, int e, int d) {
    diff[l + OFFSET] += s;
    diff[l + 1 + OFFSET] += d - s;
    diff[r + 1 + OFFSET] -= d + e;
    diff[r + 2 + OFFSET] += e;
}


void fall(int v, int x) {
    set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
	set(x - 2 * v + 1, x, v - 1, -v, -1);
	set(x + 1, x + 2 * v, -v + 1, v, 1);
	set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

void build() {
    for (int i = 1; i <= m + OFFSET; i++) diff[i] += diff[i - 1];
    for (int i = 1; i <= m + OFFSET; i++) diff[i] += diff[i - 1];
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, v, x; i < n; i++) {
        scanf("%d %d", &v, &x);
        fall(v, x);
    }
    build();
    int start = OFFSET + 1;
    printf("%d", diff[start++]);
    for (int i = 2; i <= m; i++) {
        printf(" %d", diff[start++]);
    }
    printf("\n");
    return 0;
}
/*
    测试链接：https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc
*/
#include <iostream>
#include <array>
using namespace std;

const int N = 1002;
array<array<long long, N>, N> diff;

void add(int a,int b, int c, int d, long long v) {
    diff[a][b] += v;
    diff[c + 1][d + 1] += v;
    diff[a][d + 1] -= v;
    diff[c + 1][b] -= v;
}
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            int x = 0;
            scanf("%d ", &x);
            add(i, j, i, j, x);
        }
    while (q--) {
        int a, b, c, d, v;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &v);
        add(a, b, c, d, v);
    }

    // 还原
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            printf("%lld ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}
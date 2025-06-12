/*
    测试链接：https://www.luogu.com.cn/problem/P3397
    二维差分模板题
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> diff;
    // diff要比原来的数组大一圈
    diff.resize(n + 2, vector<int>(n + 2));
    while (m--) {
        int a, b, c, d;
        // 读入数据
        scanf("%d %d %d %d", &a, &b, &c, &d);
        diff[a][b] += 1;
        diff[c + 1][d + 1] += 1;
        diff[c + 1][b] -= 1;
        diff[a][d + 1] -= 1;
    }

    // 用一次前缀和还原出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
    
    return 0;
} 

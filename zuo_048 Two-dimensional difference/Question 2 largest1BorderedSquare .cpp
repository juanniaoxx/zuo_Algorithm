/*
    测试链接：https://leetcode.cn/problems/largest-1-bordered-square/description/
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 构建前缀和数组
        // 自己+左+上-左上
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] += Get(grid, i, j - 1) + Get(grid, i - 1, j) - Get(grid, i - 1, j - 1);
        // 不含有1
        if (sum(grid, 0, 0, n - 1, m - 1) == 0) return 0;
        
        // 外圈全为1的边长
        int ans = 1;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                // 上面两个for循环为枚举左上角点的可能性
                for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; c++, d++, k++) {
                    // 上面这个循环为枚举可能满足更长答案的右下角点
                    // 通过直接+ans实现了减少枚举的个数
                    if (sum(grid, a, b, c, d) - sum(grid, a + 1, b + 1, c - 1, d - 1) == ((k - 1) << 2)) {
                        ans = k;
                    }
                }
            }
        }
        return ans * ans;
    }
private:
    // 边界判断
    int Get(vector<vector<int>> &grid, int a, int b) {
        return (a < 0 || b < 0) ? 0 : grid[a][b];
    }
    // 求给定正方形(a,b)-(c,d)的区间和
    int sum(vector<vector<int>> &g, int a, int b, int c, int d) {
        return a > c  ? 0 : (g[c][d] - Get(g, c, b - 1) - Get(g, a - 1, d) + Get(g, a - 1, b - 1));
    }
};
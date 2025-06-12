#include <vector>
using std::vector;

class Solution {
public:
    typedef vector<vector<int>> vvi;
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

        // 计算前缀和
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = grid[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        // 检查每个可能放置邮票的区域
        for (int a = 1; a + stampHeight <= n + 1; a++) {
            for (int b = 1; b + stampWidth<= m + 1; b++) {
                // 注意减1
                int c = a + stampHeight - 1;
                int d = b + stampWidth - 1;
                if (sumRegion(a, b, c, d, sum) == 0) {
                    // 更新差分数组
                    diff[a][b] += 1;
                    diff[a][d + 1] -= 1;
                    diff[c + 1][b] -= 1;
                    diff[c + 1][d + 1] += 1;
                }
            }
        }

        // 计算差分数组的前缀和
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                // 注意偏移量
                if (grid[i - 1][j - 1] == 0 && diff[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int sumRegion(int a,int b,int c,int d, vvi &g) {
        return g[c][d] - g[a - 1][d] - g[c][b - 1] + g[a - 1][b - 1];
    }
};
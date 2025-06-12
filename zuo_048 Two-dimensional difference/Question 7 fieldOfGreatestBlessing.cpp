/*
    测试链接：https://leetcode.cn/problems/xepqZ5/
*/
#include <vector>
#include <algorithm>
#include <cstring>
using std::vector, std::max;

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        // 避免出现0.5
        vector<long long> xs, ys;
        for (auto &f : forceField) {
            long long x = f[0], y = f[1], side = f[2];
            xs.push_back(2 * x - side); // 左边界
            xs.push_back(2 * x + side); // 右边界
            ys.push_back(2 * y - side); // 上边界
            ys.push_back(2 * y + side); // 下边界
        }
        // 排序数组并去重
        sort(xs.begin(), xs.end());
        // unique将相邻重复元素移动到末尾并返回新结尾的迭代器
        // erase(it, end)删除it->end的元素
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        // 离散化
        int n = xs.size(), m = ys.size(), diff[n + 2][m + 2];
        memset(diff, 0, sizeof diff);
        for (auto &f : forceField) {
            long long x = f[0], y = f[1], side = f[2];
            // +1别忘了，diff是从1开始的!
            int a = lower_bound(xs.begin(), xs.end(), 2 * x - side) - xs.begin() + 1; // 左边界的相对序号
            int c = lower_bound(xs.begin(), xs.end(), 2 * x + side) - xs.begin() + 1; // 右边界的相对序号
            int b = lower_bound(ys.begin(), ys.end(), 2 * y - side) - ys.begin() + 1; // 上边界的相对序号
            int d = lower_bound(ys.begin(), ys.end(), 2 * y + side) - ys.begin() + 1; // 下边界的相对序号
            // 二维差分
            diff[a][b] += 1;
            diff[c + 1][d + 1] += 1;
            diff[c + 1][b] -= 1;
            diff[a][d + 1] -= 1;
        }

        // 前缀和还原差分数组的结果，并计算最大值
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                ans = max(ans, diff[i][j]);
            }
        }

        return ans;
    }
};
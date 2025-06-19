/*
    测试链接:https://leetcode.cn/problems/max-value-of-equation/
    @time:4ms          95.33%
    @memory:91.24MB.   77.88%
*/
#include <vector>
#include <array>
#include <climits>
using std::vector; using std::array;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        for (int i = 0, x, y; i < points.size(); ++i) {
            x = points[i][0];
            y = points[i][1];
            // 判断当前对头的元素是否过期
            while (h < t && deque[h][0] + k < x) ++h;
            // 计算一次结果
            if (h < t) ans = std::max(ans, x + y + deque[h][1] - deque[h][0]);
            // 加入i号点的x与y
            // 是队列满足单调递减
            while (h < t && deque[t - 1][1] - deque[t - 1][0] <= y - x) --t;
            deque[t][0] = x;
            deque[t++][1] = y;
        }

        return ans;
    }
private:
    static constexpr int N = 1e5 + 10;
    array<array<int, 2>, N> deque;
    int h{0}, t{0};
};
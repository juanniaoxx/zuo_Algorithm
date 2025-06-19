/*
    测试链接:https://leetcode.cn/problems/count-submatrices-with-all-ones/description/
    统计全为1的矩形
*/
#include <vector>
#include <array>

class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            ans += countFroBottom(m);
        }
        return ans;
    }
private:
    static constexpr int N = 200;
    std::array<int, N> heights;
    std::array<int, N> st;
    int top = 0;

    int countFroBottom(int m) {
        top = 0;
        int ans = 0;
        for (int i = 0, left, len, bottom; i < m; ++i) {
            while (top > 0 && heights[st[top - 1]] > heights[i]) {
                int cur = st[--top];
                if (heights[cur] > heights[i]) {
                    left = top == 0 ? -1 : st[top - 1];
                    len = i - left - 1;
                    bottom = std::max(left == - 1 ? 0 : heights[left], heights[i]);
                    ans += (heights[cur] - bottom) * len * (len + 1) / 2;
                }
            }
            st[top++] = i;
        }

        while (top > 0) {
            int cur = st[--top];
            int left = top == 0 ? -1 : st[top - 1];
            int len = m - left - 1;
            int down = left == -1 ? 0 : heights[left];
            ans += (heights[cur] - down) * len * (len + 1) / 2;
        }

        return ans;
    }
};
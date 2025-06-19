/*
    测试链接:
*/
#include <vector>
#include <array>


using std::vector; using std::array;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 使用单调栈O(m * n)
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < m; j++) height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            ans = std::max(ans, largesRectangLeArea(height));
        }
        return ans;
    }
private:
    static const int MAX = 210;
    array<int, MAX> st;
    int top = 0;

    int largesRectangLeArea(vector<int> &height) {
        // Q3 solution
        int ans = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            while(top > 0 && height[i] <= height[st[top - 1]]) {
                int cur = st[--top];
                int left = top == 0 ? -1 : st[top - 1];
                int right = i;
                ans = std::max(ans, (right - left - 1) * height[cur]);
            }

            st[top++] = i;
        }

        while (top > 0) {
            int cur = st[--top];
            int left = top == 0 ? -1 : st[top - 1];
            int right = n;
            ans = std::max(ans, (right - left - 1) * height[cur]);
        }

        return ans;
    }
};
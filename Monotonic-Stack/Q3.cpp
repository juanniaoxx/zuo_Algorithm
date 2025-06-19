/*
    测试链接:https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
*/
#include <iostream>
#include <vector>
#include <array>
using std::vector; using std::array;
using std::cin; using std::cout; using std::endl;
// 一步转换，转换为(求左右离当前小的元素的位置的距离) * (nums[cur])
// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (top > 0 && heights[i] <= heights[st[top - 1]]) {
                int cur = st[--top];
                int right = i;
                int left = top == 0 ? -1 : st[top - 1];
                ans = std::max(ans, (right - left - 1 ) * heights[cur]);
            }
            st[top++] = i;
        }

        while (top > 0) {
            int cur = st[--top];
            int left = top == 0 ? -1 : st[top - 1];
            ans = std::max(ans, heights[cur] * (n - left - 1));
        }
        return ans;
    }
private:
    constexpr static int N = 1e5 + 10;
    array<int, N> st;
    int top = 0;
};
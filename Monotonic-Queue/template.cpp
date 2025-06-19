/*
    测试链接:https://leetcode.cn/problems/sliding-window-maximum/description/
*/
#include <vector>
#include <array>

using std::array; using std::vector;

class Solution {
public:
    // k is the size of sliding window
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // 预处理前 k - 1个元素
        for (int i = 0; i < k - 1; ++i) {
            while (h < t && nums[deque[t - 1]] <= nums[i]) --t;
            deque[t++] = i;
        }

        int m = n - k + 1;
        vector<int> ans(m, 0); // 一共有 n - k + 1个窗口

        // l 表示窗口左边界面，r表示窗口右边界
        // 每次向右滑动一次
        for (int l = 0, r = k - 1; l < m; ++l, ++r) {
            // 维护单调队列
            while (h < t && nums[deque[t - 1]] <= nums[r]) --t;
            deque[t++] = r;
            // 获取当前窗口的最大值
            ans[l] = nums[deque[h]];

            // 将过期元素删除
            if (deque[h] == l) ++h;
        }
        return ans;
    }
private:
    static const int N = 1e5 + 10;
    array<int, N> deque;
    int h = 0, t = 0;
};
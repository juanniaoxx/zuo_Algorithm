/*
    测试链接:https://leetcode.cn/problems/maximum-width-ramp/
*/
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        // 加入严格递增的序列 -- 左边界
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[st[top - 1]]) st[top++] = i;
            
        }
        // 逆序确定右边界
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (top > 0 && nums[i] >= nums[st[top - 1]]) {
                ans = std::max(ans, i - st[--top]);
            }
        }

        return ans;
    }

private:
    static const int N = 5e4 + 10;
    array<int, N> st;
    int top = 1; // 等价于 st[top++] = 0;
};
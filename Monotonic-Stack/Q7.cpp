/*
    测试链接:https://leetcode.cn/problems/steps-to-make-array-non-decreasing/description/
    删除所有前一个元素比当前元素大的元素 至数组为非递减数组
*/
#include <vector>
#include <array>

class Solution {
public:
    using PII = std::pair<int, int>;
    int totalSteps(std::vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int curTurns = 0;
            while (size > 0 && st[size - 1].first < nums[i]) {
                curTurns = std::max(curTurns + 1, st[--size].second);
            }
            st[size].first = nums[i];
            st[size++].second = curTurns;
            ans = std::max(ans, curTurns);
        }

        return ans;
    }
private:
    static constexpr int N = 1e5 + 10;
    std::array<PII, N> st;
    int size = 0;
};
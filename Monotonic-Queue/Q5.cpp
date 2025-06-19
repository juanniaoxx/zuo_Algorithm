/*
    测试链接:https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/description/
    @time: 22ms            87.32%
    @memory: 113.37MB      24.06%
*/
#include <vector>
#include <array>
#include <climits>
using std::vector; using std::array;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> sum{0};
        // 处理前缀和数组
        // sum[0] = 0
        // sum[1] = nums[0] + 0
        // sum[2] = nums[1] + nums[2] + 0
        for(int i = 0; i < nums.size(); ++i) sum.push_back(sum[i] + nums[i]);
        int ans = INT_MAX;
        for (int i = 0; i <= nums.size(); ++i) {
            // 如果当前[i...deque[h]]的和满足条件则弹出队头,并计算一次结果
            while (h != t && sum[i] - sum[deque[h]] >= k) ans = std::min(ans, i - deque[h++]);
            // 如果当前前缀和的结果小于队列尾的结果则弹出队尾
            while (h != t && sum[deque[t - 1]] >= sum[i]) --t;
            deque[t++] = i;
        }

        return ans == INT_MAX ? -1 : ans;

    }
private:
    static constexpr int N = 1e5 + 10;
    array<int, N> deque;
    int h{0}, t{0};
};
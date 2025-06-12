/*
    链接：https://leetcode.cn/problems/minimum-size-subarray-sum/description/
*/
#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, ans = 0x0fffff;
        for (; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i - j + 1);  // 记录当前窗口大小
                sum -= nums[j++];           
            }
        }
        return ans == 0x0fffff ? 0 : ans;
    }
};

// 前缀和与二分

class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        // O(N)
        for (int i = 0; i < nums.size(); i++)
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        // 使用二分查找对于每个i查找一个最小的j O(N log N)
        int min_len = 0x0fffff;
        for (int i = 0; i <= nums.size(); i++) {
            int find = prefix_sum[i] + target;
            auto j = lower_bound(prefix_sum.begin(), prefix_sum.end(), find);
            if (j != prefix_sum.end()) {
                int len = j - prefix_sum.begin() - i;
                min_len = min(len, min_len);
            }
        }

    return min_len != 0x0fffff ? min_len : 0;
    }
};

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
    }
};
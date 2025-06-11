/*
    测试链接：https://leetcode.cn/problems/make-sum-divisible-by-p/
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 计算整体余数
        int mod = 0;
        for (auto num : nums) {
            mod = (mod + num) % p;
        }

        if (mod == 0) return 0;

        unordered_map<int, int> map;
        map.insert({0, -1});
        int ans = -1;
        for (int i = 0, cur = 0, want = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % p;
            want = cur >= mod ? (cur - mod) : (cur + p - mod);
            if (map.find(want) != map.end()) ans = min(ans, i - map[want]);
            if (map.find(cur) == map.end()) map.insert({cur, i});
        }

        return ans == nums.size() ? -1 : ans;
    }
};
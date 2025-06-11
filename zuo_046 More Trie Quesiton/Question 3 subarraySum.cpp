/*
    测试链接
*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;  // 记录前缀和的出现次数
        prefixSumCount[0] = 1;  // 初始前缀和为0出现1次（方便计算）
        int sum = 0;
        int ans = 0;
        for (int num : nums) {
            sum += num;  // 计算当前前缀和
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - k];  // 统计满足条件的子数组数量
            }
            prefixSumCount[sum]++;  // 更新当前前缀和的出现次数
        }
        return ans;
    }
};
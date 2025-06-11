/*
    测试链接：https://leetcode.cn/problems/range-sum-query-immutable/description/
*/
#include <iostream>
#include <vector>

using std::vector;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] -sums[left];
    }
};

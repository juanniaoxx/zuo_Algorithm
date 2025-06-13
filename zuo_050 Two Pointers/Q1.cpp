/*
    测试链接：https://leetcode.cn/problems/sort-array-by-parity-ii/
*/
#include <vector>

using std::vector;

class Solution {
public:
    // O(N) O(N)简单遍历拷贝
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for (int i = 0, j = 0, k = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[j] = nums[i];
                j += 2;
            } else {
                ans[k] = nums[i];
                k += 2;
            }
        }

        return ans;
    }
};


class Solution {
public:
    // O(N) O(1) 双指针
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[j] % 2 == 1) j += 2;
                std::swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
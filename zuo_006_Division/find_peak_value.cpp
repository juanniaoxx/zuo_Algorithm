/*
    题目详情见 leetcode 162:https://leetcode.cn/problems/find-peak-element/description/
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) { 
            // nums.size() >=1 && nums.size() <= 1000
            int n = nums.size();
            if (nums.size() == 1) return 0;
            // 判断第一个数
            if (nums[0] > nums[1]) return 0;
            if (nums[n - 1] > nums[n - 2]) return n - 1;

            // 二分
            int l = 1, r = n - 2, m = 0, ans = -1;

            while (l <= r) {
                m = l + (r - l) / 2;
                // m左边的数大于m,则峰值必然位于[l, m - 1]中
                if (nums[m - 1] > nums[m]) r = m - 1;
                // m右边的数大于m,则峰值必然位于[m + 1, r]中
                else if (nums[m + 1] > nums[m]) l = m + 1;
                else {
                    ans = m;
                    break;
                }
            }
            return ans;
        }
    };
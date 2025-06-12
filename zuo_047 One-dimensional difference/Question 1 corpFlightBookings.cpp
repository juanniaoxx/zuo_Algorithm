/*
    测试链接：https://leetcode.cn/problems/corporate-flight-bookings/description/
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 1, 0);
        for (auto vi : bookings) {
            int left = vi[0] - 1;
            int right = vi[1];
            ans[left] += vi[2];
            ans[right] -= vi[2];
        }
        // 计算前缀和
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1]; 
        }
        ans.pop_back();
        return ans;
    }
    void print(vector<int> &nums) {
        for (auto num : nums) cout << num << " ";
        cout << endl;
    }
};
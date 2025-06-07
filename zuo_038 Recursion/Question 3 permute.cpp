#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;

    void dfs(vector<int> &nums, int i) {
        if (i == nums.size()) ans.push_back(nums);
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                dfs(nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
    }
};
/*
    测试链接：https://leetcode.cn/problems/subsets-ii/description/
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序以方便去重
        dfs(nums, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }

private:
    set<vector<int>> result; // 改用 set 自动去重
    vector<int> current;
    
    void dfs(vector<int>& nums, int start) {
        result.insert(current);
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // 跳过重复元素
            current.push_back(nums[i]);
            dfs(nums, i + 1);
            current.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序以方便去重
        path.resize(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }

private:
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i, int size) {
        if (i == nums.size()) {
            ans.push_back(vector<int>(path.begin(), path.begin() + size));
        } else {
            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j]) {
                // 记录与当前元素重复的元素有多少个
                j++;
            }

            // 去找一个不重复的元素
            dfs(nums, j, size);
            for (; i < j; i++) {
                path[size++] = nums[i]; 
                // 选择1个、2个、3个....个当前元素
                dfs(nums, j, size);
            }
        }
    }
};
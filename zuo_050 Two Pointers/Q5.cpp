/*
    测试链接：https://leetcode.cn/problems/container-with-most-water/
*/
#include <vector>

using std::vector;

class Solution {
public:
    // 总面积等于min(左边界、有边界)*(区间长度)
    int maxArea(vector<int>& height) {
        int ans = 0; int min = height[0];

        for (int r = 0, l = 0; r < height.size(); r++) {
            if (height[r] > min)
            ans = std::max(min * (r - l), ans);

        }
    }
};
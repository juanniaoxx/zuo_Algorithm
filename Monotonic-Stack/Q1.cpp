/*
    测试链接:https://leetcode.cn/problems/daily-temperatures/
*/
#include <vector>
#include <iostream>
#include <array>
using std::vector; using std::array;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (top > 0 && temperatures[i] > temperatures[st[top - 1]]) {
                int cur = st[--top];
                ans[cur] = i - cur;
            }
            // 相等也加入
            st[top++] = i;
        }

        return ans;
    }
private:
    static constexpr int N = 1e5 + 10;
    array<int, N> st;
    int top;
};
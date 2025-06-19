/*
    测试链接:https://leetcode.cn/problems/remove-duplicate-letters/description/
    // 要求去除全部重复重复数字
    // 返回字典序最小的结果
*/
#include <string>
#include <array>
#include <algorithm>
using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 统计频率
        string ans;
        for (char c : s) count[c - 'a']++;

        for (char c : s) {
            if (!enter[c - 'a']) {
                while(top > 0 && st[top - 1] > c && count[st[top - 1] - 'a'] > 0) {
                    enter[st[top - 1] - 'a'] = false;
                    top--;
                }
                st[top++] = c;
                enter[c - 'a'] = true;
            }
            count[c - 'a']--;
        }
        while (top > 0) ans += st[--top];
        std::reverse(ans.begin(), ans.end());
        return ;
    }
private:
    std::array<int, 26> count;
    std::array<char, 26> st;
    std::array<bool, 26> enter;
    int top = 0;
};
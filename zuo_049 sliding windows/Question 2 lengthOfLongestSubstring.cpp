/*
    测试链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (set.count(s[i]) != 0) {
                set.erase(s[j++]);
            }
            set.insert(s[i]);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
/*
    测试链接：https://leetcode.cn/problems/minimum-window-substring/description/
*/
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 负债与还债模型
        // 债务表
        vector<int> cnts(256, 0);
        for (auto c : t) cnts[c]--;

        int len = INT_MAX;
        int start = 0;
        int debt = t.size(); // 总债务
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnts[s[r]]++ < 0) debt--;
            if (debt == 0) {
                while(cnts[s[l]] > 0) cnts[s[l++]]--;
                if (r - l + 1 < len) {
                    len = r- l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
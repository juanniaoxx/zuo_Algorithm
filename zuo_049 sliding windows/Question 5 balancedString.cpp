/*
    测试链接：https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
*/
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        vector<int> cnts(4, 0);
        vector<int> str(s.size(), 0);
        // 统计`QWER`各自的词频
        for (int i = 0; i < s.size(); i++) {
            str[i] = s[i] == 'W' ? 1 : (s[i] == 'E' ? 2 : (s[i] == 'R' ? 3 : 0));
            cnts[str[i]]++;
        }

        // 将多出的`QWER`转换为债务
        int debt = 0;
        for (int i = 0; i < 4; i++) {
            if (cnts[i] < s.size() /4 ) cnts[i] = 0;
            else {
                cnts[i] = s.size() / 4 - cnts[i];
                debt -= cnts[i];
            }
        }
        if (debt == 0) return 0;
        // Q3的代码
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnts[str[r]]++ < 0) debt--;
            if (debt == 0) {
                while(cnts[str[l]] > 0) cnts[str[l++]]--;
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
};
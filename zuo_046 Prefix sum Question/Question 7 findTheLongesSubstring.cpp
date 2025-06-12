/*
    测试链接：
    https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
*/
#include <string>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> map(1 << 5, -2); // 使用 -2标记该状态暂未出现
        map[0] = -1;
        int ans = 0;
        for (int i = 0, m, status = 0; i < s.size(); i++) {
            m = move(s[i]);
            if (m != -1) status ^= 1 << m;
            if (map[status] != -2) ans = max(ans, i - map[status]);
            else map[status] = i;
        }

        return ans;
    }
    int move(char c) {
        switch (c)
            {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
            default:
                return -1;
            }
    }
};
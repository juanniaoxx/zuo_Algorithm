/*
    测试链接：https://leetcode.cn/problems/minimum-window-substring/description/
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++)
            map[t[i]]++;
        
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (map.empty()) {

            }
            
        }
    }
};
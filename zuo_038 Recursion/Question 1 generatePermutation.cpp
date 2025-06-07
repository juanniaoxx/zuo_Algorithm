/*
    测试链接：https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> generatePermutation(string s) {
        // write code here
        path.resize(s.size());
        dfs(s, 0, 0);
        return vector<string>(set.begin(), set.end());
    }
private:
    string path;
    unordered_set<string> set;
    void dfs(string& s, int i, int size) {
        if (i == s.size()) {
            set.insert(path.substr(0, size));
        } else {
            path[size] = s[i]; // 如果不初始化path长度这里就会越界
            dfs(s, i + 1, size + 1);
            dfs(s, i + 1, size);
        }
    }
};
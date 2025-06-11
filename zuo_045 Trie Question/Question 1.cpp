/*
    测试链接：https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int const MAX = 2e6 + 10;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param b int整型vector<vector<>> 
     * @param a int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
        // 将a数组的[i+1]-[i]加入前缀树
        for (auto vi : a) {
            string word;
            for (int i = 1; i < vi.size(); i++){
                word = word + to_string(vi[i + 1] - vi[i]) + "#";
            }
            insert(word);
        }
        // 计算b数组的[i+1]-[i]去前缀树里面查找前缀存在个数search_prefix()
        vector<int> ans;
        for (auto vi : b) {
            string word;
            for (int i = 1; i < vi.size() - 1; i++) {
                word = word + to_string(vi[i + 1] - vi[i]) + "#";
            }
            ans.push_back(search_prefix(word));
        }
        return ans;
    }
private:
    int trie[MAX][12];
    int Pass[MAX];
    int End[MAX];
    int cnt = 1;
    // 将`1`~`9`转换为下标1~9
    // 使用`#`表示一个数字结束
    // 使用`-`标记负数

    int Path(char c) {
        if (c == '#') return 11;
        else if (c =='-') return 12;
        else return c - '0';
    }
    void insert(const string &word) {
        int cur = 1;
        Pass[cur]++;
        for(int i = 0, path; i < word.size(); i++) {
            path = Path(word[i]);
            if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
            cur = cur[trie][path];
            Pass[cur]++;
        }
    }

    int search_prefix(const string &pre) {
        int cur = 1;
        for (int i = 0, path; i < pre.size(); i++) {
            path = Path(pre[i]);
            if (trie[cur][path] == 0) return 0;
            cur = trie[cur][path];
        }

        return Pass[cur];
    }
};
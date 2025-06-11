/*
    测试链接:https://leetcode.cn/problems/word-search-ii/
*/
#include <vector>
#include <string>
#include <cstring>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Build(words);
        vector<string> ans;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, 1, ans);

        return ans;
    }
private:
    static constexpr int MAX = 1e4 + 10;
    int trie[MAX][26];
    int Pass[MAX];
    string End[MAX];
    int cnt;
    // board : 二维网格
	// i,j : 此时来到的格子位置，i行、j列
	// t : 前缀树的编号
    int dfs(vector<vector<char>> &board, int i, int j, int t, vector<string> &ans) {
        // 前面是越界检测
        // 最后一个是走回头路检测
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] == '#') 
            return 0;
        // 记录当前格子上的字符
        char tmp = board[i][j];
        int road = tmp - 'a';
        t = trie[t][road];
        // 没有到对应元素的路
        if (Pass[t] == 0) return 0;

        int fix = 0;
        if (End[t] != "") {
            fix++;
            ans.push_back(End[t]);
            End[t] = "";
        }
        board[i][j] = '#';
        // 往四个方法分别查看
        fix += dfs(board, i - 1, j, t, ans);
        fix += dfs(board, i + 1, j, t, ans);
        fix += dfs(board, i, j - 1, t, ans);
        fix += dfs(board, i, j + 1, t, ans);
        // 避免重复查找
        Pass[t] -= fix;
        // 回溯复原格子上的内容
        board[i][j] = tmp;
        return fix;
    }
    // 构建字典树
    void Build(vector<string> &words) {
        cnt = 1;
        for (auto word : words) {
            int cur = 1;
            Pass[cur]++;
            for (int i = 0, path; i < word.size(); i++) {
                path = word[i] - 'a';
                if(trie[cur][path] == 0) trie[cur][path] = ++cnt;
                cur = trie[cur][path];
                Pass[cur]++;
            }
            End[cur] = word;
        }
    }
};
/*
    测试链接:https://leetcode.cn/problems/binary-tree-level-order-traversal/
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 静态数组模拟队列
        static const int N = 2010;
        TreeNode* q[N];
        int l, r;

        vector<vector<int>> ans;
        if (root != nullptr) {
            l = r = 0;
            q[r++] = root;
            while (l < r) {
                int size = r - l;
                vector<int> list;
                for (int i = 0; i < size; i++) {
                    TreeNode *cur = q[l++];
                    list.push_back(cur->val);
                    if (cur->left != nullptr) q[r++] = cur->left;
                    if (cur->right != nullptr) q[r++] = cur->right;
                }
                ans.push_back(list);
            }
        }
        return ans;
    }
};
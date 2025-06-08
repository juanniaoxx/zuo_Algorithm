/*
    测试链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/
#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root->val != p->val && root->val != q->val) {
            if (min(p->val, q->val) < root->val && root->val < max(p->val, q->val)) break;
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        }
        return root;
    }
};
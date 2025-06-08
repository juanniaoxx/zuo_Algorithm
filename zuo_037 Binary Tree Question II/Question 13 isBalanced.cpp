/*
    测试链接：https://leetcode.cn/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        hight(root);
        return balance;
    }
private:
    bool balance = true;
    int hight(TreeNode *root) {
        // 如果已经不平衡直接返回
        // 空节点返回0
        if (!balance || root == nullptr) return 0;

        // 递归计算左子树的高度
        int l_size = hight(root->left);
        // 递归计算右子树的高度
        int r_size = hight(root->right);

        // 判断左右子树的高度差
        if (abs(l_size - r_size) > 1) balance = false;
        // 返回树的高度
        return max(l_size, r_size) + 1;
    }
};
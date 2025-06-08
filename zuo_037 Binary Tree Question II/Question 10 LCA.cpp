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
        // 如果找到p、q或者节点为空则返回
        if (root == nullptr || root == p || root == q) return root;
        // 左树遍历结果
        TreeNode *l = lowestCommonAncestor(root->left, p, q); 
        // 右树遍历结果
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
		
        // 左右子树各有p或者q，则当前节点为公共祖先
        if (l != nullptr && r != nullptr) return root;
        // 左右子树都没找到，返回空
        if (l == nullptr && r == nullptr) return nullptr;
        // 否则，返回p或者q对应情况1
        return l != nullptr ? l : r;
    }
};
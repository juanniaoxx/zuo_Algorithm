/*
    测试链接：https://leetcode.cn/problems/count-complete-tree-nodes/description/
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

class Solution1 {
public:
    int countNodes(TreeNode* root) {
        // 简单版本
        if (root == nullptr) return 0;
        ans = countNodes(root->left) + countNodes(root->right) + 1;
        return ans;
    }
private:
    int ans = 0;
}; 

class Solution {
public:
    int countNodes(TreeNode* root) {
        // 优化版本 O((log(n)^2))
        if (root == nullptr) return 0;

        return f(root, 1, mostLeft(root, 1));
    }

private:
	// cur : 当前来到的节点
	// level :  当前来到的节点在第几层
	// h : 整棵树的高度，不是cur这棵子树的高度
	// 求 : cur这棵子树上有多少节点
    int f(TreeNode *cur, int level, int h) {
        if (level == h) return 1;
        if (mostLeft(cur->right, level + 1) == h)
            // cur右树上的最左节点，扎到了最深层
            return (1 << (h - level)) + f(cur->right, level + 1, h);
        else {
            // cur右子树的最左节点，没有扎到最深层
            return (1 << (h - level - 1)) + f(cur->left, level + 1, h);
        }
    }

    // 计算左子树的深度
    int mostLeft(TreeNode *cur, int level) {
        while (cur != nullptr) {
            level++;
            cur = cur->left;
        }
        
        return level - 1;
    }
};
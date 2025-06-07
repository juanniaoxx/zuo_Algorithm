/*
    测试链接：
    https://leetcode.cn/problems/check-completeness-of-a-binary-tree/description/
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
    bool isCompleteTree(TreeNode* root) {
        const int N = 110;
        TreeNode* q[N];
        int l = 0, r = 0;
        
        q[r++] = root;
        // 遍历过有左无右的节点
        // 或者遍历过叶节点
        bool flag = false;
        while (l < r) {
            TreeNode *cur = q[l++];
            // 有右无左比如不是
            if ((cur->left == nullptr && cur->right != nullptr)
                || 
            // flag改变后的所有节点必须全都是叶节点否则返回false
                (flag && (cur->left != nullptr || cur->right != nullptr)))
                return false;
            if (cur->left != nullptr) q[r++] = cur->left;
            if (cur->right != nullptr) q[r++] = cur->right;
            // 无左有右 31行就会返回所以这里只有在无左无右，或者有左无右的情况下修改flag
            if (cur->left == nullptr || cur->right == nullptr) flag = true; 
        }
        return true;
    }
};
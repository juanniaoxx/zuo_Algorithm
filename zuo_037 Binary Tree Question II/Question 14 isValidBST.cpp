/*
    测试链接：https://leetcode.cn/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        bool valid = true;
        for (int i = 0; i < list.size() - 1; i++) {
            if (list[i] >= list[i + 1]) {
                valid = false;
                break;
            } 
        }

        return valid;
    }
private:
    vector<int> list;
    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }
};
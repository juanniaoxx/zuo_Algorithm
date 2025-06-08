/*
    测试链接: https://leetcode.cn/problems/path-sum-ii/solutions/
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        target = targetSum;
        dfs(root, 0);
        return ans;
    }
private:
    vector<int> path;
    vector<vector<int>> ans;
    int target = 0;
    void dfs(TreeNode *root, int sum) {
        path.push_back(root->val); // 将当前节点加入路径
        if (root->left == nullptr && root->right == nullptr) {
            if ((sum + root->val) == target) {
                ans.push_back(path); // 找到一条路径，加入答案
            }
        }
        if (root->left != nullptr) {
            dfs(root->left, sum + root->val); // 递归左子树
            path.pop_back(); // 回溯：左子树递归完成后，弹出左子节点
        }
        if (root->right != nullptr) {
            dfs(root->right, sum + root->val); // 递归右子树
            path.pop_back(); // 回溯：右子树递归完成后，弹出右子节点
        }
    }
};
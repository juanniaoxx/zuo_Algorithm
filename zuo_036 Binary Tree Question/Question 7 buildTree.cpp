/*
    测试链接:https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include <iostream>
#include <vector>
#include <unordered_map>
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
    // 题目保证了必然有一个节点
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 建立中序遍历的节点和坐标的关系便于通过查找
        for (int i = 0; i < inorder.size(); i++) {
            map.insert({inorder[i], i});
        }

        return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    // 用一个hash表存前序节点到中序遍历的位置 
    unordered_map<int, int> map;
    // 关键函数
    TreeNode *f(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1) return nullptr;
        TreeNode *head = new TreeNode(preorder[l1]);
        if (l1 == r1) return head;
        int k = map[preorder[l1]];
        // 这几个边界自己手动模拟一下就能明白了
        // preorder: l1(.....)[......r1]
        // inorder:(l2.....)k[.......r2]
        // l1 + 1 表示preorder往下走一格, l1 + - l2表示左子树的长度
        head->left = f(preorder, l1 + 1, l1 + k - l2, inorder, l2, k - 1);
        // l1 + k -12 表示preorder中右子树的根节点的坐标(走完左子树)
        head->right = f(preorder, l1 + k - l2 + 1, r1, inorder, k + 1, r2);
    }
};
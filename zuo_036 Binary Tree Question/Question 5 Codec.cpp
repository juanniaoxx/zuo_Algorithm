/*
    测试链接：https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/
*/

#include <iostream>
#include <sstream>
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
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data); // 转化为流输出
        return buildTree(iss);
    }

private:
    TreeNode* buildTree(istringstream &iss) {
        string val;
        iss >> val; 
        if (val == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(val)); // 处理多位数
        node->left = buildTree(iss);
        node->right = buildTree(iss);
        return node;
    }
};
#include <iostream>
using namespace std;

struct treeNode {
    int val; // 存的值
    treeNode *right; // 指向右孩子
    treeNode *left; // 指向左孩子

    // 构造函数
    treeNode() : val(0), right(nullptr), left(nullptr) {}
    treeNode(int x) : val(x), right(nullptr), left(nullptr) {}
    treeNode(int x, treeNode *right) : val(x), right(right), left(nullptr) {}
    treeNode(int x, treeNode *right, treeNode *left) : val(x), right(right), left(left) {}
};


// 先序遍历
void preorder(treeNode *root) {
    // recursive
    if (!root) return;

    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(treeNode *root) {
    // recursive 
    if (!root) return;

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

// 后序遍历
void posorder(treeNode *root) {
    // recursive
    if (!root) return;

    posorder(root->left);
    posorder(root->right);
    cout << root->val << endl;
}

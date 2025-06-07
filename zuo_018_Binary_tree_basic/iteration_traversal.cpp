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

void preorder(treeNode *root) {
    // Iteration
}

void inorder(treeNode *root) {
    // Iteration
}

void posorder(treeNode *root) {
    // Iteration
}
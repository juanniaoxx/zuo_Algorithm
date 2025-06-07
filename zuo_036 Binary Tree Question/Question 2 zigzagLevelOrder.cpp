/*
    测试链接:
    https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 使用数组模拟队列
        const int N = 2010;
        TreeNode* q[N];
        int l = 0, r = 0;
        bool flag = false;

        // bfs
        decltype(zigzagLevelOrder(root)) ans;
        if (root != nullptr) {
            l = 0, r = 0;
            q[r++] = root;
            while (l < r) {
                int size = r - l;
                vector<int> list;
                for (int i = 0; i < size; i++) {
                    auto cur = q[l++];
                    list.push_back(cur->val);
                    if (cur->left != nullptr) q[r++] = cur->left;
                    if (cur->right != nullptr) q[r++] = cur->right;
                }
                if (flag) std::reverse(list.begin(), list.end());
                flag = !flag;
                ans.push_back(list);
            }
        }
    return ans;
    }
};

// 先收集答案再加入左右子树
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 使用数组模拟队列
        const int N = 2010;
        TreeNode* q[N];
        int l = 0, r = 0;
        bool flag = false;

        // bfs
        decltype(zigzagLevelOrder(root)) ans;
        if (root != nullptr) {
            l = 0, r = 0;
            q[r++] = root;
            while (l < r) {
                int size = r - l;
                vector<int> list;
                for (int i = flag ? r - 1: l, j = flag ? -1: 1, k = 0; k < size; i += j, k++) {
                    list.push_back(q[i]->val);
                }
                for (int i = 0; i < size; i++) {
                    auto cur = q[l++];
                    if (cur->left != nullptr) q[r++] = cur->left;
                    if (cur->right != nullptr) q[r++] = cur->right;
                }
                ans.push_back(list);
                flag = !flag;
            }
        }
    return ans;
    }
};
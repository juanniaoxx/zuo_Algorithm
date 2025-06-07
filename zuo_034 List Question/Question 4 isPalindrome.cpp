/*
    测试链接:https://leetcode.cn/problems/palindrome-linked-list/description/
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 只有一个元素比如是回文 题目保证了节点数目大于等于1
        if (head == nullptr || head->next == nullptr) return true;
        auto slow = head; // 慢指针
        auto fast = head; // 快指针
        bool ans = true; // 答案
        // 查找中点
        // 快指针一次走2步，慢指针一次走1步
        for (; fast && fast->next && fast->next->next; fast = fast->next->next, slow = slow->next);
        // 从slow往后开始逆序
        auto pre = slow;
        auto cur = pre->next;
        ListNode *next = nullptr;
        pre->next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // 判断左右两部分是否相等
        // head-> ....-> slow <- .... <- pre
        auto left = head;
        auto right = pre;
        while (left && right) {
            if (left->val != right->val) {
                ans = false;
                break; // 为了后续还原链表
            }
            left = left->next;
            right = right->next;
        }

        // 还原链表
        cur = pre->next;
        pre->next = nullptr;
        next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return ans;
    }
};
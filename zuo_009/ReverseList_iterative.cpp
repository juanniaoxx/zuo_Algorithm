/*
    https://leetcode.cn/problems/reverse-linked-list/description/
    Requirements: Implement using both recursive and iterative approaches.
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
        ListNode* reverseList(ListNode* head) {
            // Approach 1: iterative
            ListNode *curr = head, *next = nullptr, *prev = nullptr;
            // 记忆唤醒：->等效于先解引用在用点运算符访问成员
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    };
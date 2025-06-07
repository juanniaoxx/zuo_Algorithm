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
            // Approach 2: recursive
            // Base case
            if (head == nullptr || head->next == nullptr) return head;
            ListNode *new_head = reverseList(head->next);

            head->next->next = head;
            head->next = nullptr;
            
            
            return new_head;
        }
    };
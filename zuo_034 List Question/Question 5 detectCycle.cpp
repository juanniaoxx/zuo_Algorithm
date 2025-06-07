/*
    测试链接: https://leetcode.cn/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        // 零个节点 一个节点 两个节点 都不可能形成环
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) 
            return nullptr;
        
        auto slow = head->next;
        auto fast = head->next->next;

        while (slow != fast) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                // 无环
                return nullptr; 
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
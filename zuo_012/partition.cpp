/*
    https://leetcode.cn/problems/partition-list/description/
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode *lefthead = nullptr, *lefttail = nullptr; // < x
            ListNode *righthead = nullptr, *righttail = nullptr;// >= x
            while (head) {
                auto curr = head;
                head = head->next;
                curr->next = nullptr;

                // < x
                if (curr->val < x) {
                    if (lefthead == nullptr) {
                        lefthead = lefttail = curr;
                    } else {
                        lefttail->next = curr;
                        lefttail = curr;
                    }
                } else {
                    // >= x
                    if (righthead == nullptr) {
                        righthead = righttail = curr;
                    } else {
                        righttail->next = curr;
                        righttail = curr;
                    }
                }
            }

            // edge cases
            if (!lefthead || !righthead) return lefthead ? lefthead : righthead;
            // merge two lists
            lefttail->next = righthead;
            return lefthead;
        }
    };
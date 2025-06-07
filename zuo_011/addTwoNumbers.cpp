/*
    https://leetcode.cn/problems/add-two-numbers/
*/
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = nullptr, *curr = nullptr;
            int carry = 0;
            while (l1 || l2) {
                int n1 = l1 ? l1->val : 0;
                int n2 = l2 ? l2->val : 0;
                int sum = n1 + n2 + carry;

                if (!head) {
                    head = curr = new ListNode(sum % 10);
                } else {
                    curr->next = new ListNode(sum % 10);
                    curr = curr->next;
                }

                carry = sum / 10;
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;
            }
            if (carry > 0) curr->next = new ListNode(carry);

            return head;
        }
    };
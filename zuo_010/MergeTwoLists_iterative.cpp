struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Approach 1 : Iterative
        if (list1 == nullptr || list2 == nullptr) return list1 == nullptr ? list2 : list1;
        ListNode *head = list1->val <= list2->val ? list1 : list2;
        ListNode *cur1 = head->next;
        ListNode *cur2 = head == list1 ? list2 : list1;
        ListNode *prev = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                prev->next = cur1;
                cur1 = cur1->next;
            } else {
                prev->next = cur2;
                cur2 = cur2->next;
            }

            prev = prev->next;
        }

        prev->next = cur1 != nullptr ? cur1 : cur2;
        return head;
    }
};
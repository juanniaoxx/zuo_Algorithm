/*
    测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
    时间复杂度: O(N)
    空间复杂度: O(1)
*/
#include <iostream>
#include <cmath>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto start = head;
        auto end = teamEnd(head, k);
        if (!end) return head;
        // 换头
        head = end;
        // 反转
        reverse(start, end);
        ListNode *lastTeamEnd = start;
        while (lastTeamEnd->next) {
            start = lastTeamEnd->next;
            end = teamEnd(start, k);
            if (!end) return head;
            reverse(start, end);
            lastTeamEnd->next = end;
            lastTeamEnd = start;
        }

        return head;
    }
private:

    ListNode* teamEnd(ListNode *p, int k) {
        while (--k != 0 && p) {
            p = p->next;
        }

        return p;
    }
    // 原地反转链表
    // s -> a -> b -> c -> e -> 下一组的开始节点
	// 上面的链表通过如下的reverse方法调整成 : e -> c -> b -> a -> s -> 下一组的开始节点
    void reverse(ListNode *start, ListNode *end) {
        // 包含下一组的开始节点
        end = end->next;
        ListNode *pre = nullptr, *cur = start, *next = nullptr;
        while (cur != end) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 将悬空的start的next指针指向下一组的开始节点
        start->next = end;
    }
};
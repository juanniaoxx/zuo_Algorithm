/*
    测试链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = 0;
        auto a = headA, b = headB;
        for (; a; a = a->next, diff++);
        for (; b; b = b->next, diff--);

        if (a != b) return nullptr;
        
        // 让a指向长链表、b指向短链表
        if (diff >= 0) {
            a = headA;
            b = headB;
        } else {
            a = headB;
            b = headA;
        }

        diff = abs(diff);
        while (diff-- != 0) a = a->next; 
        for (; a != b; a = a->next, b = b->next);

        return a;
    }
};
/*
    测试链接：https://leetcode.cn/problems/copy-list-with-random-pointer/
*/
#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        auto cur = head;
        // 为每一个节点后添加一个拷贝节点
        while (cur != nullptr) {
            auto next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }

        cur = head;
        // 为拷贝节点配置random指针
        while (cur != nullptr) {
            auto copy = cur->next;
            copy->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        // 分离链表
        auto ans = cur->next;
        while (cur != nullptr) {
            auto copy = cur->next;
            auto next = cur->next->next;
            cur->next = next;
            copy->next = next != nullptr ? next->next : next;
            cur = next;
        }

        return ans;
    }
};
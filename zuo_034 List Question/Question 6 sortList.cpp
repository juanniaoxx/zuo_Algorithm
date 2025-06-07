/*
    测试链接:https://leetcode.cn/problems/sort-list/solutions/2993518/liang-chong-fang-fa-fen-zhi-die-dai-mo-k-caei/
    时间复杂度：O(nlogn)
    空间复杂度: O(1)
    这个代码的实现细节可真不容易......
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
    ListNode* sortList(ListNode* head) {
        // 计算链表长度n
        int n = 0;
        for (auto p = head; p; p = p->next, n++);
        
        // 定义用于分割和合并链表的指针
        ListNode *l1, *r1, *l2, *r2, *next, *lastTeamEnd;
        
        // 外层循环：step从1开始，每次翻倍，直到超过链表长度
        for (int step = 1; step < n; step <<= 1) {
            // 处理第一组（可能涉及头节点变更）
            l1 = head;                      // 第一组的头
            r1 = findEnd(l1, step);         // 第一组的尾
            l2 = r1->next;                  // 第二组的头
            r2 = findEnd(l2, step);         // 第二组的尾
            next = r2->next;                // 下一组的起始节点
            
            // 断开两组之间的连接
            r1->next = nullptr;
            r2->next = nullptr;
            
            // 合并这两个有序子链表
            merge(l1, r1, l2, r2);
            
            // 更新头指针和上一组的尾指针
            head = start;                   // start是merge后新链表的头
            lastTeamEnd = end;              // end是merge后新链表的尾
            
            // 处理剩余的所有组
            while (next != nullptr) {
                l1 = next;                  // 新组的头
                r1 = findEnd(l1, step);     // 新组的尾
                l2 = r1->next;              // 下一组的头
                
                // 如果第二组不存在，直接连接剩余部分
                if (l2 == nullptr) {
                    lastTeamEnd->next = l1;
                    break;
                }
                
                r2 = findEnd(l2, step);    // 下一组的尾
                next = r2->next;           // 下下组的起始
                
                // 断开连接
                r1->next = nullptr;
                r2->next = nullptr;
                
                // 合并这两个子链表
                merge(l1, r1, l2, r2);
                
                // 将合并后的链表连接到已排序部分
                lastTeamEnd->next = start;
                lastTeamEnd = end;          // 更新上一组的尾
            }
        }
        return head;
    }
    
private:
    ListNode *start, *end;  // 用于记录merge后的头尾节点
    
    // 从节点s开始，找到第k个节点（或链表末尾）
    ListNode *findEnd(ListNode *s, int k) {
        while (--k != 0 && s->next != nullptr) {
            s = s->next;
        }
        return s;
    }
    
    // 合并两个有序子链表
    // l1...r1 -> null : 有序的左部分
    // l2...r2 -> null : 有序的右部分
    void merge(ListNode *l1, ListNode *r1, ListNode *l2, ListNode *r2) {
        ListNode *pre = nullptr;  // 用于构建新链表的指针
        
        // 处理头节点 - 选择较小的作为新链表的头
        if (l1->val <= l2->val) {
            start = l1;         // 全局记录新链表头
            pre = l1;
            l1 = l1->next;
        } else {
            start = l2;
            pre = l2;
            l2 = l2->next;
        }

        // 归并过程 - 比较两个链表的当前节点
        while (l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        
        // 处理剩余节点 - 将剩余部分连接到新链表
        if (l1 != nullptr) {
            pre->next = l1;
            end = r1;           // 全局记录新链表尾
        } else {
            pre->next = l2;
            end = r2;
        }
    }
};
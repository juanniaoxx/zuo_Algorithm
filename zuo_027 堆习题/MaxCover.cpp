/*
    合并K个升序链表
    测试链接1 :https://leetcode.cn/problems/merge-k-sorted-lists/
    测试链接2 :https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6
    使用堆优化版本
    时间复杂度 O(nlog(k))
    空间复杂度 O(k)
    k表示一共有多少个链表、n表示链表的所有节点
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param lists ListNode类vector 
     * @return ListNode类
     */
    struct CompareListNode {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val; // 注意是 ">"，因为 C++ 默认是最大堆
    }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        // 创建小根堆
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareListNode> minHeap;
        for (auto h: lists) {
            if (h != nullptr) minHeap.push(h);
        }

        // 如果数据为空
        if (minHeap.empty()) return nullptr;

        // C++必须先取出堆顶元素，在移除堆顶元素
        auto h = minHeap.top();minHeap.pop();
        auto pre = h;
        if (pre->next != nullptr) {
            minHeap.push(pre->next);
        }
        while (!minHeap.empty()) {
            auto cur = minHeap.top();minHeap.pop();
            pre->next = cur;
            pre = cur;
            if (cur->next != nullptr) {
                minHeap.push(cur->next);
            }
        }
        return h;
    }
};
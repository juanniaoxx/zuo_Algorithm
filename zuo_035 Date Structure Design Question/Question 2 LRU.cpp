/*
    测试链接：https://leetcode.cn/problems/lru-cache/
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    // 构造函数
    LRUCache(int capacity) {
        // 初始化哈希表容量就可以
        max_size = capacity;
    }
    
    int get(int key) {
        // 从hash中读地址访问就可以
        // 如果存在需要更新节点至尾
        // cout << "get " << "key = " << key << endl;
        // print();
        if (map.find(key) != map.end()) {
            update(map[key]);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 容量未满
        if (map.size() < max_size || map.count(key)) {
            // 在哈希表中插入该 key - address
            // cout << "put " << " key = " << key << " value = " << value << endl;
            // cout << "size = " << map.size() << " capacity = " << max_size << endl;
            // print();
            if (map.count(key)) {
                // 不要忘记同key修改
                map[key]->val = value;
                update(map[key]);
            } else {
                // 不存在这创建一个新的节点
                Node *cur = new Node(key, value);
                // 将节点插入末尾去
                if (head == nullptr || tail == nullptr) {
                    head = cur;
                    tail = cur;
                } else {
                    cur->pre = tail;
                    tail->next = cur;
                    tail = tail->next;
                }
                // 将该 key - address加入到哈希表中
                map.insert({key, cur});
            }
        }
        else {
            // cout << "容量满了" << endl;
            // cout <<"put key = " << key << " value = " << value << endl;
            // print();
            // 容量已满要舍弃一些数据
            Node *cur = new Node(key, value);
            // 舍弃头节点的数据
            Node *temp = head;
            int x = head->key;
            head = head->next;
            delete(temp);
            map.erase(x); // 哈希表中也应该删除该条记录
            // 将当前节点插入到链表尾上
            if (head == nullptr || tail == nullptr) {
                head = cur;
                tail = cur;
            } else {
                cur->pre = tail;
                tail->next = cur;
                tail = tail->next;
            }
            // 将该 key - address加入到哈希表中
            map.insert({key, cur});
        }
    }
private:
    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *pre;
        // 构造函数
        Node(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}
    };

    // key - address
    unordered_map<int, Node*> map;
    // 全局的头尾指针
    Node *head = nullptr;
    Node *tail = nullptr;
    int max_size;

    void update(Node *cur) {
        // 将当前指针移动到尾巴上
        Node *next = cur->next;
        Node *pre = cur->pre;
        if (cur == tail) return ; // 如果以及是尾节点，什么都不需要干
        if (cur == head) {
            // 如果是头节点，移动头节点至下一个节点
            head = cur->next;
            next->pre = nullptr;
            cur->next = nullptr;
            tail->next = cur;
            cur->pre = tail;
            tail = tail->next;
            return ;
        }
        // 中间节点
        pre->next = next; 
        next->pre = pre;
        // 更改前后指针
        cur->next = nullptr;
        cur->pre = tail;
        tail->next = cur;
        tail = tail->next;
    }
    void print() {
        for (auto p = head; p; p = p->next) cout << "key = " << p->key << "value" << p->val<< " ";
        cout << endl;
    }
};

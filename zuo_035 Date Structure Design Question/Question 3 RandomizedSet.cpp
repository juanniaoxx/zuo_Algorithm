/*
    测试链接：https://leetcode.cn/problems/insert-delete-getrandom-o1/description/
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    // 构造函数
    RandomizedSet() {
        srand(time(0));
    }
    // 插入操作
    bool insert(int val) {
        // 如果已经存在则直接返回false
        if (map.count(val)) return false;
        else {
            // val - vector下标
            map.insert({val, map.size()});
            vi[map.size()] = val;
            return true;
        }
    }
    // 移除操作
    bool remove(int val) {
        // 如果不存在则返回false
        if (!map.count(val)) return false;
        // 如果存在则用最后一条数据覆盖
        if (map.size() == 1) {
            // 如果是最后一条数据则直接删除
            map.erase(val);
        } else {
            int address = map[val];
            vi[address] = vi[map.size() - 1];
            map[vi[map.size() - 1]] = address;
            map.erase(val);
        }
        return true;
    }
    // 获取随机值
    int getRandom() {
        if(map.size() == 1) return vi[0];
        else return vi[(int)rand()%(map.size() - 1)];
    }

private:
    unordered_map<int, int> map;
    vector<int> vi;
};
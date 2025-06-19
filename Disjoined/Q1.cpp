/*
 * 测试链接: 
 * @time: 0ms       100%
 * @memory:9.59MB   72.10% 
 */
#include <vector>
#include <array>
using std::vector;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        build(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2) Union(row[i] / 2, row[i + 1] / 2);
        return row.size() / 2 - sets;
    }
private:
    static const int N = 32;
    std::array<int, N> father;
    int sets = 0; // 统计集合数

    void build(int m) {
        for (int i = 0; i < m; ++i) father[i] = i;
        sets = m;
    }

    int find(int i) {
        if (i != father[i]) i = find(father[i]);
        return father[i];
    }

    void Union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            --sets;
        }
    }
};
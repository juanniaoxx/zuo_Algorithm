/*
    测试链接: https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
    要求O(1)的时间复杂度
*/
#include <iostream>
#include <unordered_map>

using namespace std;
using PII = pair<int, int>; // C++11
// setAllValue 记录修改的值
// setAllTime 记录要求修改的时间戳
// cnt 全局时间戳
int setAllValue, setAllTime = -1, cnt = 0;

int main() {
    int n = 0;
    scanf("%d", &n);
    unordered_map<int, PII> map;
    while (n--) {
        int op = -1;
        scanf("%d", &op);
        if (op == 1) {
            // 插入操作
            int k = 0, v = 0;
            scanf("%d %d", &k, &v);
            // 容易忘记，传入相同的键要修改其值，并更新时间戳
            // C++17以上可以使用：map.insert_or_assign(k, make_pair(v, cnt++));
            if (map.count(k)) {
                map[k].first = v;
                map[k].second = cnt++;
            } else {
                map.insert({k, {v, cnt++}});
            }
        } else if (op == 2) {
            // 查询操作
            int x = 0;
            scanf("%d", &x);
            if (map.find(x) == map.end()) {
                cout << -1 << endl;
            } else {
                auto& value = map[x];
                if (value.second > setAllTime) {
                    cout << value.first << endl;
                } else {
                    cout << setAllValue << endl;
            }
            }
        } else {
            // setAll操作
            int x = 0;
            scanf("%d", &x);
            setAllValue = x;
            setAllTime = cnt++;
        }
    }
}
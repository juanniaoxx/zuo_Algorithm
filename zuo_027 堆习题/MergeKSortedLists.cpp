/*
    线段重合问题 --- 堆解法
    测试链接 牛客(Acw模式):https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

vector<PII> lines;
const int N = 1e4 + 10;
int main() {
    int n = 0, ans = 0;
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> min_heap;
    scanf("%d", &n);
    // 读入数据
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        lines.push_back({a, b});
    }
    // 排序
    std::sort(lines.begin(), lines.end());
    for (auto p:lines) {
        while (!min_heap.empty() && min_heap.top() <= p.first) min_heap.pop();
        min_heap.push(p.second);
        ans = ans > min_heap.size() ? ans : min_heap.size();
    }

    cout << ans << endl;
    return 0;
}
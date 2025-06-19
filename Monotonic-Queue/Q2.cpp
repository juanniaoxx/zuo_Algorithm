/*
    测试链接:https://www.luogu.com.cn/problem/P2698
*/
#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>

using PII = std::pair<int, int>;

constexpr int N = 1e5 + 10;
std::vector<PII> arr;
std::array<int, N> deque_max;
std::array<int, N> deque_min;
int h_max, t_max, h_min, t_min;
int n, d;

// 判断当前元素加入窗口后是否满足条件
bool can_join() {
    int max = h_max < t_max ? arr[deque_max[h_max]].second : 0;
    int min = h_min < t_min ? arr[deque_min[h_min]].second : 0;
    return max - min >= d;
}

void join(int r) {
    while (h_max < t_max && arr[deque_max[t_max - 1]].second <= arr[r].second) --t_max;
    deque_max[t_max++] = r;
    while (h_min < t_min && arr[deque_min[t_min - 1]].second >= arr[r].second) --t_min;
    deque_min[t_min++] = r;
}

void remove(int l) {
    if (h_max < t_max && deque_max[h_max] == l) ++h_max;
    if (h_min < t_min && deque_min[h_min] == l) ++h_min;
}

int compute() {
    // 按x坐标排序
    std::sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    for (int l = 0, r = 0; l < n; ++l) {
        // [l, r) 水滴编号
        while (!can_join() && r < n) join(r++);
        if (can_join()) ans = std::min(ans, arr[r - 1].first - arr[l].first);
        remove(l);
    }

    return ans;
}
int main() {
    scanf("%d %d", &n, &d);

    // 读入x,y数据往arr
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr.push_back({x, y});
    }

    int ans = compute();
    printf("%d\n", ans == INT_MAX ? -1 : ans);

    return 0;
}
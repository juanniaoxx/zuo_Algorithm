/*
    测试链接:https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
*/
// 可重复元素的单调递增栈
#include <iostream>
#include <vector>

using std::vector;

constexpr int N = 1e6 + 10;

vector<int> arr(N, 0);
vector<int> stack(N, 0);

std::pair<int, int> ans[N];
int n, top;

void monotonicallyIncreasingStack() {
    top = 0;
    int cur;
    // 遍历
    for (int i = 0; i < n; i++) {
        while (top > 0 && arr[i] <= arr[stack[top - 1]]) {
            cur = stack[--top];
            ans[cur].first = top > 0 ? stack[top - 1] : -1;
            ans[cur].second = i;
        }
        stack[top++] = i;
    }

    // 清算
    while (top > 0) {
        cur = stack[--top];
        ans[cur].first = top > 0 ? stack[top - 1] : -1;
        ans[cur].second = -1;
    }

    // 修改 
    for (int i = n - 1; i > 0; i--) {
        if (ans[i].second != -1 && arr[ans[i].second] == arr[i]) {
            ans[i].second = ans[ans[i].second].second;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    // 模板
    monotonicallyIncreasingStack();
    for (int i = 0; i < n; i++) std::cout << ans[i].first << " " << ans[i].second << std::endl;

    return 0;
}
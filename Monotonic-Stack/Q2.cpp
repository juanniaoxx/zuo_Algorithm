/*
    测试链接:https://leetcode.cn/problems/sum-of-subarray-minimums/description/
*/
#include <vector>
#include <array>
using std::vector; using std::array;

class Solution {
public:
    typedef long long LL;
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1'000'000'000 + 7;
        LL ans = 0;
        
        for (int i = 0, cur; i < arr.size(); i++) {
            while (top > 0 && arr[st[top - 1]] >= arr[i]) {
                cur = st[--top];
                int left = top == 0 ? -1 : st[top - 1];
                ans = (ans + (LL) (cur - left) * (i - cur) * arr[cur]) % MOD;
            }
            st[top++] = i;
        }

        while (top > 0) {
            int cur = st[--top];
            int left = top == 0 ? -1 : st[top - 1];
            ans = (ans + (LL) (cur - left) * (arr.size() - cur) * arr[cur]) % MOD;
        }

        return (int)(ans % MOD);
    }
private:
    constexpr static int N = 3e4 + 10;
    array<int, N> st;
    int top = 0;
};

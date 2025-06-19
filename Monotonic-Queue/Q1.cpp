/*
    测试链接:https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
*/
#include <vector>
#include <array>
using std::vector; using std::array;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        arr = nums;
        int ans = 0;
        int n = nums.size();
        for (int l = 0, r = 0; l < n; ++l) {
            // sliding windows : [l, r)
            while (r < n && can_join(limit, nums[r])) {
                join(r++);
            }
            // 从while出来表明当前位置以及不可能在扩大了，结算答案并弹出窗口左边的元素
            ans = std::max(ans, r - l);
            remove(l);
        }

        return ans;
    }
private:
    static constexpr int N = 1e5 + 10;
    vector<int> arr;
    array<int, N> deque_max;
    array<int, N> deque_min;
    int h_min{0}, t_min{0}, h_max{0}, t_max{0};
    // 判断当前元素是否可以加入滑动窗口
    bool can_join(int limit, int num) {
        // 若队列为空则直接加入
        if (h_max == t_max) return true;
        // 否则判断加入后若能修改max、min，则修改后的差是否满足要求
        int max = std::max(arr[deque_max[h_max]], num);
        int min = std::min(arr[deque_min[h_min]], num);
        return max - min <= limit;
    }

    // 新元素加入时候不要忘记修改单调栈的结构
    void join(int r) {
        while(h_max < t_max && arr[deque_max[t_max - 1]] <= arr[r]) --t_max;
        deque_max[t_max++] = r;
        while(h_min < t_min && arr[deque_min[t_min - 1]] >= arr[r]) --t_min;
        deque_min[t_min++] = r;
    }

    // 删除元素也不要忘记修改单调栈的结构
    void remove(int l) {
        if (h_max < t_max && deque_max[h_max] == l) ++h_max;
        if (h_min < t_min && deque_min[h_min] == l) ++h_min;
    }

};
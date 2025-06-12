/*
    测试链接：https://leetcode.cn/problems/longest-well-performing-interval/
*/
#include <vector>
#include <unordered_map>
using namespace std;

// 哈希+前缀和
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int ,int> map;
        int ans = 0;

        for (int i = 0, sum = 0; i < hours.size(); i++) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else {
                // 隐藏的一个特性这里，由于sum只能+1或者-1
                // 比如当前sum = -3
                // 要找 0 - j 的累计和为 -4/-5/-6..,说明 j + 1 - i 为 1 > 0
                // 但由于sum每次只能+1/-1
                // 若存在累计0..j累计和为-5,则前面一定存在0..j'为-4,此时j'+1...i必然比j+1..i长
                // 所以只需要找sum-1的位置即可
                if (map.find(sum - 1) != map.end()) ans = max(ans, i - map[sum - 1]);
            }
            // 只需要存sum <= 0的前缀和即可
            if (sum <= 0 && map.find(sum) == map.end()) map.insert({sum, i});
        }
        return ans;
    }
};

// 单调栈

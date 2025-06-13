/*
    测试链接：https://leetcode.cn/problems/find-the-duplicate-number/solutions/261119/xun-zhao-zhong-fu-shu-by-leetcode-solution/
*/

#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        // 让fast和slow一直走，直到相遇
        while (slow != fast) {
            // slow走一次
            slow = nums[slow];
            // fast走两次
            fast = nums[nums[fast]];
        }
        // 将指针放回起点
        fast = 0;
        while (slow != fast) {
            // slow和fast都调整为一次走一步
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;  // n为数组长度，ans用于存储最终结果（重复的数字）

        // 确定最高有效位的位置（bit_max）
        // 例如，n=5时，数字范围是1~4（因为有一个重复），4的二进制是100，最高位是第2位
        int bit_max = 31;  // 初始设为31（假设是32位整数）
        while ((n - 1) >> bit_max == 0) bit_max--;  // 找到最高有效位的位置

        // 逐位检查（从最低位到bit_max位）
        for (int bit = 0; bit <= bit_max; bit++) {
            int x = 0, y = 0;  // x统计nums中该位为1的数的个数，y统计1~n-1中该位为1的数的个数

            // 计算x：nums数组中当前bit位为1的数的个数
            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bit)) x++;  // 检查nums[i]的第bit位是否为1
            }

            // 计算y：1~n-1的数字中当前bit位为1的数的个数
            // 注意：因为nums的长度是n，且包含1~n-1的数字和一个重复数字
            for (int i = 1; i < n; i++) {  // i从1到n-1
                if (i & (1 << bit)) y++;  // 检查i的第bit位是否为1
            }

            // 如果nums中该位为1的数的个数 > 1~n-1中该位为1的数的个数
            // 说明重复数字的该位为1，将其设置到ans中
            if (x > y) ans |= 1 << bit;
        }

        return ans;  // 返回找到的重复数字
    }
};
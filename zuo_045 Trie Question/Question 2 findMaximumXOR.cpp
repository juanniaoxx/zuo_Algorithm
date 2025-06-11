/*
    测试链接:https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
*/
/* 
    暴力解法 leetcode可以过41/45
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                ans = ans > (nums[i] ^ nums[j]) ? ans : (nums[i] ^ nums[j]);

        return ans;
    }
}; */

#include <iostream>
#include <vector>
using namespace std;

// 方法1使用trie解决这个问题
class Solution1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        Build(nums);          // 构建 Trie
        int ans = 0;
        for (int num : nums)   // 对每个数字计算最大异或值
            ans = max(ans, maxXor(num));
        return ans;
    }
    
private:
    static constexpr int MAX = 3000010;  // Trie 最大节点数
    int trie[MAX][2];         // Trie 结构，每个节点有 0/1 两个子节点
    int cnt;                  // Trie 节点计数器
    int high;                 // 最高有效位的位置

    // 计算前导零的数量
    int numberOfLeadingZeros(unsigned int x) {
        if (x == 0) return 32;
        int count = 0;
        for (int shift = 31; shift >= 0; --shift) {
            if ((x >> shift) == 0) count++;
            else break;
        }
        return count;
    }

    // 构建 Trie
    void Build(vector<int> &nums) {
        cnt = 1;  // 根节点编号为 1
        int max_value = 0;
        for (auto num : nums) max_value = max_value > num ? max_value : num;
        high = 31 - numberOfLeadingZeros(max_value);  // 计算最高有效位
        for (int num : nums) insert(num);  // 插入所有数字到 Trie
    }

    // 插入数字到 Trie
    void insert(int num) {
        int cur = 1;  // 从根节点开始
        for (int i = high; i >= 0; i--) {
            int path = (num >> i) & 1;  // 取出第 i 位
            if (trie[cur][path] == 0)   // 如果路径不存在，创建新节点
                trie[cur][path] = ++cnt;
            cur = trie[cur][path];     // 移动到子节点
        }
    }

    // 计算 num 与 Trie 中某数的最大异或值
    int maxXor(int num) {
        int ans = 0;
        int cur = 1;  // 从根节点开始
        for (int i = high; i >= 0; i--) {
            int status = (num >> i) & 1;  // num 的第 i 位
            int want = status ^ 1;       // 希望找到的相反位
            if (trie[cur][want] == 0)     // 如果没有相反位，只能走相同位
                want ^= 1;
            ans |= (status ^ want) << i;  // 更新异或结果的第 i 位
            
            cur = trie[cur][want];       // 移动到子节点
        }
        return ans;
    }
};

#include <unordered_set>
// 使用哈希表解决这个问题
class Solution2 {
public:
    int numberOfLeadingZeros(unsigned int x) {
        if (x == 0) return 32;
        int count = 0;
        for (int shift = 31; shift >= 0; --shift) {
            if ((x >> shift) == 0) count++;
            else break;
        }
        return count;
    }

    int findMaximumXOR(vector<int>& nums) {
        int max = 0;
        for (int num : nums) max = max > num ? max : num;
        int ans = 0;
        unordered_set<int> set;

        for (int i = 31 - numberOfLeadingZeros(max); i >= 0; i--) {
            int better = ans | (1 << i);
            set.clear();
            for (auto num : nums) {
                num = (num >> i) << i;
                set.insert(num);
                if (set.find(better ^ num) != set.end()) {
                    ans = better;
                    break;
                }
            }
        } 
        return ans;
    }
};
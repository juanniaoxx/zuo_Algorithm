/*
    测试链接 ： https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 使用系统堆
class Solution1 {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> max_heap;
        int ans = 0;
        double sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            max_heap.push((double)nums[i]);
            sum += (double) nums[i];
        }

        sum /= 2;
        while (sum > 0) {
            double delta = (max_heap.top()) / 2;
            max_heap.pop();
            max_heap.push(delta);
            sum -= delta;
            ans++;
        }

        return ans;
    }
};

class Solution {
public:
    int halveArray(vector<int>& nums) {
        const int N = 1e5 + 10;
        long heap[N];
        int n = nums.size();
        long sum = 0;
        
        // 构建最大堆
        for (int i = n - 1; i >= 0; i--) {
            heap[i] = (long)nums[i] << 20;
            sum += heap[i];
            heapify(heap, n, i);
        }
        
        sum /= 2;
        int ans = 0;
        
        for (long minus = 0; minus < sum; ans++) {
            heap[0] /= 2;
            minus += heap[0];
            heapify(heap, n, 0);
        }
        
        return ans;
    }
    
private:
    void heapify(long heap[], int size, int i) {
        while (true) {
            int l = i * 2 + 1;
            if (l >= size) break;
            
            int best = (l + 1 < size && heap[l + 1] > heap[l]) ? l + 1 : l;
            if (heap[best] <= heap[i]) break;
            
            swap(heap[best], heap[i]);
            i = best;
        }
    }
};
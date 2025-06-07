/*
    从升序数组中查找特定数字（严格要求 num == target)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

bool find(const vector<int>& arr, int target);
vector<int> randomArray(int n, int v);
bool right(const vector<int>& sortedArr, int target);
int main(void) {
    // 设置随机种子
    srand(time(0));

    int N = 100;
    int V = 1000;
    int testTime = 500000;
    cout << "测试开始" << endl;

    for (int i = 0; i < testTime; i ++) {
        int n = rand() % N;
        vector<int> arr = randomArray(n, V);
        sort(arr.begin(), arr.end());
        int target = rand() % V;

        if (right(arr, target) != find(arr, target)) {
            cout << "出错了!" << endl;
            for (int i = 0; i < arr.size(); i ++) cout << arr[i] << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "测试通过" << endl;
    return 0;
}

// 二分查找法
bool find(const vector<int>& arr, int target) {
    if (arr.empty()) return false;

    int l = 0, r = arr.size() - 1, m = 0;

    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] == target) return true;
        else if (arr[m] > target) r = m - 1;
        else l = m + 1;
    }

    return false;
}

// 生成随机数组
vector<int> randomArray(int n, int v) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % v + 1;
    }

    return arr;
}

// 验证方法 - 线性搜索
bool right(const vector<int>& sortedArr, int target) {
    for (int cur : sortedArr) {
        if (cur == target) {
            return true;
        }
    }
    
    return false;
}
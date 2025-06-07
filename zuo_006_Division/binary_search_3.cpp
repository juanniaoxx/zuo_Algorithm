/*
    从升序数组中查找小于target的最右数字，即不小于target的最大数。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int find(const vector<int>& arr, int target);
vector<int> randomArray(int n, int v);
int right(const vector<int>& sortedArr, int target);
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
            cout << "target = " << target << endl;
            cout << "array = ";
            for (int i = 0; i < arr.size(); i ++) cout << arr[i] << " ";
            cout << endl;
            cout << "right -> " << right(arr, target) << endl;
            cout << "find ->" << find(arr, target) << endl;
            return 0;
        }
    }

    cout << "测试通过" << endl;
    return 0;
}

// 二分查找法
int find(const vector<int>& arr, int target) {
    if (arr.empty()) return -1;

    int l = 0, r = arr.size() - 1, m = 0, ans = -1;

    while (l <= r) {
        // 小于等于target的最右边位置
        m = l + (r - l) / 2;
        if (arr[m] <= target) {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    return ans;
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
int right(const vector<int>& sortedArr, int target) {
    for (int i = sortedArr.size() - 1; i >= 0; i --) {
        if (sortedArr[i] <= target) return i;
    }

    return -1;
}
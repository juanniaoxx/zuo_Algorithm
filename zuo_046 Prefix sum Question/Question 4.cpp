#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;
constexpr int N = 1e5 + 10;

array<int, N> arr;
unordered_map<int, int> map;
int n, aim = 0;

int compute() {
    map.clear();
    map.insert({0, -1});
    int ans = 0;
    for (int i = 0, sum; i < n; i++) {
        sum += arr[i];
        if (map.find(sum - aim) != map.end()) ans = max(ans, i - map[sum - aim]);
        if (map.find(sum) == map.end()) map.insert({sum, i});
    }

    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d ", &x);
        if (x > 0) arr[i] = 1;
        else if (x < 0) arr[i] = -1;
        else arr[i] = 0;
    }

    cout << compute() << endl;
    return 0;
}
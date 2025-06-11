#include <iostream>
#include <unordered_map>
#include <array>
using namespace std;

const int N = 1e5 + 10;
array<int, N> q;
int n, aim;
unordered_map<int, int> map;

int compute() {
    map.clear();
    map.insert({0, -1});
    int ans = 0;
    for (int i = 0, sum = 0; i < n; i++) {
        sum += q[i];
        if (map.find(sum - aim) != map.end()) ans = max(ans, i - map[sum - aim]);
        if (map.find(sum) == map.end()) map.insert({sum, i});
    }

    return ans;
}
int main() {
    scanf("%d %d", &n, &aim);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    cout << compute() << endl;
    return 0;
}

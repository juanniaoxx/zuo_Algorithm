/*
 * 测试链接:https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372
 * @time: 431ms
 * @memory: 9776KB
 * 实现摊还复杂度O(1)完成如下三个操作,查找特殊元素是否在某个特定集合内(find)，
 * 判断集合是否是同一个集合(issameset)以及合并(union)两个集合 
 * 
 * 两大优化:按秩合并与路径压缩
 */
#include <array>

constexpr int MAX = 1e6 + 10;
std::array<int, MAX> father;
std::array<int, MAX> size;
std::array<int, MAX> stack;

int n;

// 初始化并查集
void build() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
        size[i] = 1;
    }
}

// find操作
int find(int i) {
    int top = 0;
    // 用栈模拟递归
    while (i != father[i]) {
        stack[top++] = i;
        i = father[i];
    }

    // 将沿途节点全部指向根节点
    // 路径压缩
    while (top > 0) father[stack[--top]] = i;
    return i;
}

/*
    递归版本，不含按秩合并
    int find(int i) {
        if (i != father[i]) i = find(father[i]);
        return father[i];
    }
*/
// 判断两个元素是否在一个集合中
bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

// 合并两个集合
void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        // 按秩合并
        if (size[fx] >= size[fy]) {
            size[fx] += size[fy];
            father[fy] = fx;
        } else {
            size[fy] += size[fx];
            father[fx] = fy;
        }
    }
}

int main() {
    int m = 0;
    scanf("%d %d", &n, &m);
    build();

    while (m--) {
        int op = 0;
        int x = 0, y = 0;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            if (isSameSet(x, y)) printf("Yes\n");
            else printf("No\n");
        } else {
            Union(x, y);
        }
    }
    return 0;
}

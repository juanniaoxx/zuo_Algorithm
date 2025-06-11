/*
    使用静态数组实现
    测试链接：https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX = 1e5+10;
int trie[MAX][26]; // 记录路径信息
int Pass[MAX], End[MAX]; // 记录pass数据和end数据
// 舍弃节点0不用
int cnt = 1; // 当前节点

// 函数声明
void insert(const string &word);
void erase(const string &word);
int search(const string &word);
int search_prefix(const string &pre);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op = 0;
        scanf("%d", &op);
        string word;
        cin >> word;
        switch (op)
        {
        case 1:
        // 插入操作
            insert(word);
            break;
        case 2:
        // 删除操作
            erase(word);
            break;
        case 3:
        // 查询操作
            if (search(word)) cout << "YES" << endl;
            else cout << "NO" << endl;
            break;
        case 4:
        // 查询前缀操作
            cout << search_prefix(word) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}

// 插入操作
void insert(const string &word) {
    int cur = 1;
    Pass[cur]++;
    for (int i = 0; i < word.size(); i++) {
        int path = word[i] - 'a';
        if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
        cur = trie[cur][path];
        Pass[cur]++;
    }
    End[cur]++;
}

// 查询操作
int search(const string &word) {
    int cur = 1;
    for (int i = 0; i < word.size(); i++) {
        int path = word[i] - 'a';
        if (trie[cur][path] == 0) return 0;
        cur = trie[cur][path];
    }
    return End[cur];
}

// 查询前缀操作
int search_prefix(const string &pre) {
    int cur = 1;
    for (int i = 0; i < pre.size(); i++) {
        int path = pre[i] - 'a';
        if (trie[cur][path] == 0) return 0;
        cur = trie[cur][path];
    }
    return Pass[cur];
}

// 删除操作
void erase(const string &word) {
    if (search(word)) {
        int cur = 1;
        Pass[cur]--;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if(--Pass[trie[cur][path]] == 0) {
                trie[cur][path] = 0;
                return;
            }
            cur = trie[cur][path];
        }
        End[cur]--;
    }
}

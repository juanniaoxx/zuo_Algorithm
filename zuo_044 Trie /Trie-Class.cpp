/*
    使用类实现Trie结构
    测试链接：https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
*/
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // 插入操作
    void insert(const string &word) {
        TrieNode *node = root;
        node->pass++;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if (node->next[path] == nullptr) node->next[path] = new TrieNode();
            node = node->next[path];
            node->pass++;
        }
        node->end++;
    }

    // 查询操作
    int search(const string &word) {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++) {
            int path = word[i] - 'a';
            if(node->next[path] == nullptr) return 0;
            node = node->next[path];
        }

        return node->end; // 返回以该节点结尾的字符串个数
    }

    // 查询有多少字符串以pre为前缀的字符串
    int search_prefix(const string &prev) {
        TrieNode *node = root;
        for (int i = 0; i < prev.size(); i++) {
            int path = prev[i] - 'a';
            if (node->next[path] == nullptr) return 0;
            node = node->next[path];
        }

        return node->pass; // 返回经过该节点的字符串个数
    }

    // 删除某一个字符串
    void erase(const string &word) {
        // 只有该字符串存在于Trie中才需要操作
        if (search(word) > 0) {
            TrieNode *node = root;
            node->pass--;
            for (int i = 0; i < word.size(); i++) {
                int path = word[i] - 'a';
                if(--node->next[path]->pass == 0) {
                    delete node->next[path];
                    node->next[path] = nullptr;
                    return ;
                }
                node = node->next[path];
            }
            node->end--;
        }
    }
private:
    struct TrieNode {
        int pass;
        int end;
        std::array<TrieNode*, 26> next = {}; // 使用 std::array
        TrieNode() : pass(0), end(0) {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
        ~TrieNode() {
            for (int i = 0; i < 26; ++i) {
                if (next[i] != nullptr) {
                    delete next[i];
                }
            }
        }
    };
    TrieNode *root;
};


int main() {
    int n = 0;
    Trie trie;

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
            trie.insert(word);
            break;
        case 2:
        // 删除操作
            trie.erase(word);
            break;
        case 3:
        // 查询操作
            if (trie.search(word)) cout << "YES" << endl;
            else cout << "NO" << endl;
            break;
        case 4:
        // 查询前缀操作
            cout << trie.search_prefix(word) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
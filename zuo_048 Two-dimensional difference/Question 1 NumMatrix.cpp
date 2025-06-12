/*
    测试链接：https://leetcode.cn/problems/range-sum-query-2d-immutable/
*/
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // 设置sum大小为(n + 1, m + 1)避免边界讨论
        sum.resize(n + 1, vector<int>(m + 1));

        for (int a = 1, c = 0; c < n; a++, c++) {
            for (int b = 1, d = 0; d < m; b++, d++) {
                // 将matrix的元素对应的拷贝进sum
                // a -> c + 1
                // b -> d + 1
                sum[a][b] = matrix[c][d];
            }
        }

        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                // 前缀和等于 上 + 左 + 自己 - 左上
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    }

    int sumRegion(int a, int b, int c, int d) {
        // a 子矩阵左上角行索引
        // b 子矩阵左上角列索引
        // c 子矩阵右下角行索引
        // d 子矩阵右下角列索引
        // [c + 1][d + 1]为大矩形
        // [c + 1][b]为上方小矩阵
        // [a][d + 1]为左侧小矩形
        // [a][b]为多减的小矩阵
        return sum[c + 1][d + 1] - sum[c + 1][b] - sum[a][d + 1] + sum[a][b];
    }
private:
    vector<vector<int>> sum;
};

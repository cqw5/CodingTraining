/*! Source: https://leetcode.com/problems/set-matrix-zeroes
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  矩阵清零
 */


/*
 * 思路：
 *   用一个函数组和一个列数组，分别记录0元素所在的行和列
 * 时间复杂度：O(m*n). 59 ms. beats 47.25 % of cpp submissions.
 * 空间复杂度：O(m+n)
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        vector<bool> rows(m, false);
        int n = matrix[0].size();
        if (n == 0) return;
        vector<bool> cols(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


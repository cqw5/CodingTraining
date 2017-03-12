/*! Source: https://leetcode.com/problems/rotate-image/?tab=Description
 *! Author: qwchen
 *! Date: 2017-03-12
 *  将矩阵选择90度
 */

/*
 * 思路：
 *   该题的难点在于如果表示矩阵中的元素
 *              A[i][j]
 *            ___________
 *           |           |
 *A[n-1-j][i]|           |A[j][n-1-i]
 *           |           |
 *           |___________|
 *              A[n-1-i][n-1-j]
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0;
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n-1-i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};


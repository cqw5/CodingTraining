/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 1.7
 *! 题目描述:
 *    请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
 *！测试样例：
 *    [[1,2,3],[0,1,2],[0,0,1]]
 *    返回：[[0,0,3],[0,0,0],[0,0,0]]
 */

/*
 * 思路：
 *   遍历两遍方阵：
 *   第一次遍历，用分别用两个数组记录0元素所在的行和列
 *   第二次变量，若所在行或列标记为0，则将元素清为0
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<vector<int> > clearZero(vector<vector<int>> mat, int n) {
        if (n <= 1) return mat;
        vector<bool> row(n, false);
        vector<bool> col(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }
};


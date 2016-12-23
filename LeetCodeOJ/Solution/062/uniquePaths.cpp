/*! Source: https://leetcode.com/problems/unique-paths/
 *! Author: qwchen
 *! Date  : 2016-12-23
 *  寻找从机器人产品呢矩阵a[0][0]走到a[m][n]的所有唯一的可能路径，无障碍
 * Solution 为该文件最优的方案
 */

/*
 * 思路：
 *   动态规划+滚动数组，状态转移函数如下：
 *    | f[i][j] = 1,                     0 <= i < m, j = 0
 *    | f[i][j] = 1,                     i = 0, 0 <= j < n
 *    | f[i][j] = f[i-1][j] + f[i][j-1], 0 < i < m, 0 < j < n
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(min(m, n)) 
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 || n == 1) return 1;
        if (m < n) return uniquePaths(n, m);
        vector<int> f(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[j] += f[j-1];
            }
        }
        return f[n-1];
    }
};


/*
 * 思路：
 *   动态规划，状态转移函数如下：
 *    | f[i][j] = 1,                     0 <= i < m, j = 0
 *    | f[i][j] = 1,                     i = 0, 0 <= j < n
 *    | f[i][j] = f[i-1][j] + f[i][j-1], 0 < i < m, 0 < j < n
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n) 
 */
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> f(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};


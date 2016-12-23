/*! Source: https://leetcode.com/problems/unique-paths-ii/
 *! Author: qwchen
 *! Date  : 2016-12-23
 *  寻找从机器人产品呢矩阵a[0][0]走到a[m][n]的所有唯一的可能路径，矩阵中的1表示障碍
 *  不能修改矩阵
 * Solution 为该文件最优的方案
 */

/*
 * 思路：
 *   动态规划+滚动数组，状态转移函数如下：
 *    | f[i][j] = 0,                     obstacleGrid[i][j] == 1
 *    | f[i][j] = f[i-1][j],             obstacleGrid[i][j] == 0 && 0 <= i < m, j = 0
 *    | f[i][j] = f[i][j-1],             obstacleGrid[i][j] == 0 && i = 0, 0 <= j < n
 *    | f[i][j] = f[i-1][j] + f[i][j-1], obstacleGrid[i][j] == 0 && 0 < i < m, 0 < j < n
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int> f(n, 0);
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 0) f[j] = 1;
            else                         break;
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) f[0] = 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) f[j] += f[j-1];
                else                         f[j] = 0;
            }
        }
        return f[n-1];
    }
};


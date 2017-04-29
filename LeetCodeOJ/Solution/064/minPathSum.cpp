/*! Source: https://leetcode.com/problems/set-matrix-zeroes
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  最短路径和
 *    给定一个矩阵，矩阵中每个元素都是一个非0整数，从从矩阵的左上方走到右下方，需要的最短长度
 */

/*
 * 动态规划+滚动数组
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m+n)
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};


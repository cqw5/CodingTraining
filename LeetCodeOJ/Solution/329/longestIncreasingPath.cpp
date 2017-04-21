/*! Source: https://leetcode.com/problems/longest-increasing-path-in-a-matrix
 *! Author: qwchen
 *! Date  : 2017-04-19
 */
/*
 * 思路：
 *   如果简单从每个结点开始，进行DFS，然后从中找出路径最长增长路径的，会有大量重复计算。
 *   使用另外一个矩阵，来保存从每个结点出发所能到达的最长路径，从而避免重复计算。
 * 时间复杂度：O(m*n). 32 ms. beats 93.50% of cpp submissions.
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<int> cols(n, 0);
        vector<vector<int>> lenMatrix(m, cols); //用来保存从当前结点出发的最长增长路径
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(dfs(matrix, lenMatrix, m, n, i, j, INT_MIN), maxLen);
            }
        }
        return maxLen;
    }
    
    int dfs(vector<vector<int>>& mat, vector<vector<int>>& lenMat, int m, int n, int i, int j, int lastElem) {
    	// 当前结点不满足要求
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] <= lastElem) return 0;
        // 重复子问题，直接返回
        if (lenMat[i][j] != 0) return lenMat[i][j];
        int left = dfs(mat, lenMat, m, n, i, j-1, mat[i][j]);
        int right = dfs(mat, lenMat, m, n, i, j+1, mat[i][j]);
        int up = dfs(mat, lenMat, m, n, i-1, j, mat[i][j]);
        int down = dfs(mat, lenMat, m, n, i+1, j, mat[i][j]);
        lenMat[i][j] = max(max(max(left, right), up), down) + 1;
        return lenMat[i][j];
    }
};


/*
 * 思路：
 *   从矩阵的每个结点开始，进行DFS
 * 时间复杂度：O(m*n*m*n). 超时. 这个方法存在大量重复计算
 * 空间复杂度；O(m*n)
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<bool> cols(n, false);
        vector<vector<bool>> boolMatrix(m, cols);
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, boolMatrix, m, n, i, j, INT_MIN, 1, maxLen);
            }
        }
        return maxLen;
    }
    
    void dfs(vector<vector<int>>& mat, vector<vector<bool>>& boolMat, int m, int n, int i, int j, int lastElem, int len, int& maxLen) {
        if (i >= 0 && i < m && j >= 0 && j < n && !boolMat[i][j] && mat[i][j] > lastElem) {
            boolMat[i][j] = true;
            if (len > maxLen) maxLen = len;
            dfs(mat, boolMat, m, n, i, j+1, mat[i][j], len+1, maxLen);
            dfs(mat, boolMat, m, n, i+1, j, mat[i][j], len+1, maxLen);
            dfs(mat, boolMat, m, n, i, j-1, mat[i][j], len+1, maxLen);
            dfs(mat, boolMat, m, n, i-1, j, mat[i][j], len+1, maxLen);
            boolMat[i][j] = false;
        }
    }
};



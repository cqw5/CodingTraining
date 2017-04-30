/*! Source: https://leetcode.com/problems/word-search
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  单词查找
 */

/*
 * 思路：
 *   深度优先搜索
 *   从矩阵每个元素开始，进行深度DFS，如果能找到字符串==word，返回true
 * 时间复杂度：O(m*n*s). 13 ms. beats 71.69 % of cpp submissions.
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m <= 0) return false;
        int n = board[0].size();
        if (n <= 0) return false;
        vector<bool> cols(n, false);
        vector<vector<bool>> boolMat(m, cols); // 一个辅助数组
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, boolMat, word, i, j, m, n, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& boolMat, string& word, int i, int j, int m, int n, int k) {
        if (k == word.size()) return true;
        if (i >= 0 && i < m && j >= 0 && j < n && boolMat[i][j] == false && board[i][j] == word[k]) {
            boolMat[i][j] = true;
            if (dfs(board, boolMat, word, i+1, j, m, n, k+1) 
                || dfs(board, boolMat, word, i-1, j, m, n, k+1)
                || dfs(board, boolMat, word, i, j+1, m, n, k+1)
                || dfs(board, boolMat, word, i, j-1, m, n, k+1)) {
                    return true;
                }
            boolMat[i][j] = false;
        }
        return false;
    }
};


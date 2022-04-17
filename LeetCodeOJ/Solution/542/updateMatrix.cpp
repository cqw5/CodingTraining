/*! Source: https://leetcode-cn.com/problems/01-matrix/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  01 矩阵
 */


/*
 * 思路：
 *   广度优先搜索：https://leetcode-cn.com/problems/01-matrix/solution/01ju-zhen-by-leetcode-solution/
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }          
            }
        }
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            for (int k = 0; k < 4; k++) {
                int i = cur.first + points[k][0];
                int j = cur.second + points[k][1];
                if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                    res[i][j] = res[cur.first][cur.second] + 1;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
            q.pop();
        }
        return res;
    }

private:
    int points[4][2] = {
        {-1, 0}, // up
        {0, 1},  // right
        {1, 0},  // down
        {0, -1}  // left
    };
};



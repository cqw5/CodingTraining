/*! Source: https://leetcode.com/problems/spiral-matrix-ii
 *! Author: qwchen
 *! Date  : 2017-04-11
 *  螺旋式填充矩阵
 *  给定一个数n将1~n^2的数螺旋式的填充到矩阵中
 */


/*
 * 思路：
 *   下面的方法不用考虑奇偶数
 *   按照顺时针方向遍历上行，删除上行；遍历右列，删除右列，遍历下行，删除下行，遍历左列，删除左列
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;;
        vector<int> line(n, 0);
        vector<vector<int>> mat(n, line);
        int left = 0, right = n-1, up = 0, down = n-1;
        while (true) {
            for (int i = left; i <= right; i++) mat[up][i] = count++;
            if (++up > down) break;
            for (int i = up; i <= down; i++) mat[i][right] = count++;
            if (--right < left) break;
            for (int i = right; i >= left; i--) mat[down][i] = count++;
            if (--down < up) break;
            for (int i = down; i >= up; i--) mat[i][left] = count++;
            if (++left > right) break;
        }
        return mat;
    }
};


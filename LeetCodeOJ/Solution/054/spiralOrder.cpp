/*! Source: https://leetcode.com/problems/spiral-matrix/?tab=Description
 *! Author: qwchen
 *! Date: 2017-03-12
 *  顺时针从外到内选择遍历矩阵（螺旋式打印矩阵）
 */

/*
 * 思路：
 *   下面的方法不用考虑m和n哪个大哪个小，也不用考虑奇偶数
 *   按照顺时针方向遍历上行，删除上行；遍历右列，删除右列，遍历下行，删除下行，遍历左列，删除左列
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        int up = 0,      // 最上面一行 
            down = m-1,  // 最下面一行
            left = 0,    // 最左边一行
            right = n-1; // 最右边一行
        while (true) {
            for (int col = left; col <= right; col++) res.push_back(matrix[up][col]);    // 遍历当前的最上面一行
            if (++up > down)    break;    // ++up删除最上面一行，如果没有行了，退出
            for (int row = up; row <= down; row++)    res.push_back(matrix[row][right]); // 遍历当前的最右边一列
            if (--right < left) break;    // --right删除最右边一列，如果没有列了，退出
            for (int col = right; col >= left; col--) res.push_back(matrix[down][col]);  // 遍历当前的最下面一行
            if (--down < up)    break;    // --down删除最下面一行，如果没有行了，退出
            for (int row = down; row >= up; row--)    res.push_back(matrix[row][left]);  // 遍历当前的最左边一列
            if (++left > right) break;    // ++left删除最左边一列，如果没有列了，退出
        }
        return res;
    }
};


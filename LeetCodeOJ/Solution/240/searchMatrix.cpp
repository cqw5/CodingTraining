/*! Source: https://leetcode.com/problems/search-a-2d-matrix-ii
 *! Author: qwchen
 *! Date  : 2017-04-14
 *  杨式矩阵中找元素
 */

/*
 * 思路：
 *   杨式矩阵找元素的标准解法
 * 时间复杂度：O(m+n). 62 ms. beats 87.25% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (target > matrix[i][j]) i++;
            else if (target < matrix[i][j]) j--;
            else return true;
        }
        return false;
    }
};


/*! Source: https://leetcode.com/problems/search-a-2d-matrix/
 *! Author: qwchen
 *! Date  : 2016-12-21
 *  从二维数组中查找元素
 *  - 数组每一行都是递增的
 *  - 数组每一行的第一个元素都大于前一个的最后一个元素 
 *  Solution为该文件下最佳的方案
 */

/*
 * 思路：
 *   考虑到矩阵的特性，只要把矩阵每一个都拼接到其前一行后面，就可以构成一个排序数组，就变成从排序数组中查找元素，二分查找即可
 *   对应矩阵的元素matrix[i][j]，转化为数组后，对应的下标为i * m + j
 *   对于转化后的数组的第k个元素，转化为原始解决，对应元素matrix[k / n][k % n]
 * 时间复杂度：O(log(m*n)) = O(logm + logn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m <= 0) return false;
        int n = matrix[0].size();
        if (n <= 0 || matrix[0][0] > target || matrix[m-1][n-1] < target) return false;
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midVal = matrix[mid/n][mid%n];
            if (midVal < target) {
                low = mid + 1;
            }
            else if (midVal > target) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

/* 
 * 思路：
 *   没有考虑到“数组每一行的第一个元素都大于前一个的最后一个元素 ”这个特性，误认为这是个杨氏矩阵，利用杨氏矩阵的解法
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)
 */
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m <= 0) return false;
        int n = matrix[0].size();
        if (n <= 0 || matrix[0][0] > target || matrix[m-1][n-1] < target) return false;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] < target)      i++;
            else if (matrix[i][j] > target) j--;
            else                            return true;
        }
        return false;
    }
};
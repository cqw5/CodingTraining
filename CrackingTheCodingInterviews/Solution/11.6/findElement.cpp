/*! Author: qwchen
 *! Date  : 2017-02-25
 *! 查找与排序：11.6 矩阵元素查找
 *! 题目描述：
 *    有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。请设计一个高效的查找算法，查找矩阵中元素x的位置。
 *    给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，请返回一个二元数组，代表该元素的行号和列号(均从零开始)。
 *    保证元素互异。
 */

/*
 * 思路：
 *   这是一个杨氏矩阵，使用二分查找，从右上角的元素开始查找（也可以从左下角）：
 *      如果x大于当前元素，下一步向下查找
 *      如果x小于当前元素，下一步向左查找
 * 时间复杂度：0(n+m)
 * 空间复杂度：O(1)
 */
class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
    	vector<int> res = {-1, -1};
        if (n <= 0 || m <= 0) return res;
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (x > mat[i][j]) {
                i++;
            }
            else if (x < mat[i][j]) {
                j--;
            } 
            else {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
        return res;
    }
};


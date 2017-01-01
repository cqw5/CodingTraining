/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 1.6
 *! 题目描述:
 *    有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
 *    给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
 *！测试样例：
 *    [[1,2,3],[4,5,6],[7,8,9]],3
 *    返回：[[7,4,1],[8,5,2],[9,6,3]]
 */

/*
 * 思路：
 *   将方阵旋转90度，只需要一层一层进行旋转。对每一层执行环状旋转，将上边移到右边、右边移到下边、下边移到左边、左边移到上边。
 *   从外面第一层开始逐渐向里，在每一层上执行上述交换。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    vector<vector<int>> transformImage(vector<vector<int>> mat, int n) {
        if (n <= 1) return mat;
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n-1-i; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n-1-j][i];
                mat[n-1-j][i] = mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j] = mat[j][n-1-i];
                mat[j][n-1-i] = temp;
            }
        }
        return mat;
    }
};



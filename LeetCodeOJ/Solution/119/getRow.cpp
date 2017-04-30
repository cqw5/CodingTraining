/*! Source: https://leetcode.com/problems/pascals-triangle-ii
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  Pascal三角II
 *    给定行索引i，返回Pascal三角中该行的内容
 *  如，k=3, return [1,3,3,1]
 */

/*
 * 思路：
 *   每一层，除了第一个后最后一个元素外，其他元素满足：
 *   A[j] = A[j-1] + A[j], 因为只使用一个滚动数组，因此需要一个来保存中间状态
 * 时间复杂度：O(n^2). 3ms. beats 2.06 % of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> layer(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            int last = 1;
            for (int j = 1; j < i; j++) {
                int cur = last + layer[j];
                last = layer[j];
                layer[j] = cur;
            }
        }
        return layer;
    }
};


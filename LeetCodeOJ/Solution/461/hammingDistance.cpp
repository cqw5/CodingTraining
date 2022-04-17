/*! Source: https://leetcode-cn.com/problems/hamming-distance/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  汉明距离
 */

/*
 * 思路：
 *   异或，然后进行1的计数
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xy = x ^ y;
        while (xy > 0) {
            count += xy & 1;
            xy = xy >> 1;
        }
        return count;
    }
};

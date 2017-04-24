/*! Source: https://leetcode.com/problems/power-of-two
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  2的指数
 */

/*
 * 思路：
 *   2的指数肯定是正整数，因此非正整数肯定不是
 *   2的指数还有一个特点，就是二进制表示时，一个1个位为1，其他位为0，那么n&(n-1)应该等于0
 * 时间复杂度：O(1). 6 ms. beats 4.30% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n&(n-1));
    }
};


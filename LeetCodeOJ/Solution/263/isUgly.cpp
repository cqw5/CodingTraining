/*! Source: https://leetcode.com/problems/ugly-number
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  丑数
 */

/*
 * 思路：
 *   根据定义<=0的数肯定不是丑数
 *   如果num能整数2/3/5，那么让num不断除去2/3/5，如果最后num=1，那么该数就是丑数。
 * 时间复杂度: O(n). 6 ms. beats 4.51% of cpp submissions.
 * 空间复杂度: O(1)
 */
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return ((num == 1) || (num == -1))? true: false ;
    }
};


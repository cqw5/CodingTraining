/*! Source: https://leetcode.com/problems/reverse-integer/
 *! Author: qwchen
 *! Date  : 2016-12-19
 * 数字翻转
 */

/*
 * 思路：
 *   两个注意点：1. 负数取模的结果仍然是负数，因此不用区分正数和负数
 *               2. 注意溢出的问题
 * 时间复杂度：O(x的位数)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while (x != 0) {
            int tail = x % 10;
            int newY = y * 10 + tail;
            if ((newY - tail) / 10 != y) return 0;  // 发生溢出，返回0
            y = newY;
            x /= 10;
        }
        return y;
    }
};


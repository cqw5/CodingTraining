/*! Source: https://leetcode.com/problems/palindrome-number/
 *! Author: qwchen
 *! Date  : 2016-12-20
 *  判断一个数是否是回文，即从左到右看和从右到左看是一样的
 *  Solution为该文件最佳解决方案
 */

/*
 * 思路：
 *   如果一个数是负数，或者数的个位数为0（除了0外），则该数肯定不是回文
 *   不断将x的尾部放到另一个数y中，当y大于等于x时退出
 *   如果这个数是奇数位，则最终y / 10 == x；如果这个数是偶数为，则最终y == x
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int y = 0;
        while(x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return (x == y) || (y / 10 == x);
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int x2 = x;
        int y = 0;
        while(x2 > 0) {
            y = y * 10 + x2 % 10;
            x2 /= 10;
        }
        return x == y;
    }
};


/*! Source: https://leetcode.com/problems/powx-n
 *! Author: qwchen
 *! Date  : 2017-04-15
 *  Pow(x, n)
 *  保证不会出现x=0 && n<0
 */

/*
 * 思路：
 *   使用类似于二分查找的方法来降低时间复杂度
 *   当n为偶数时，n个x相乘，等于n/2个x*x相乘
 *   当n为奇数时，n个x相乘，等于n * (n/2个x*x相乘)。 注意到n是int类型，n/2会把余数部分截断
 *   还有注意n是否小于0，如果小于n，就变成n个1/x相乘
 * 时间复杂度：O(logn)
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (equal(x, 0)) return 0.0;
        if (equal(x, 1)) return 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -1 * n;
        }
        return (n % 2 == 1)? (x * myPow(x*x, n/2)): myPow(x*x, n/2);
    }
    
    bool equal(double x, double y) {
        return (x - y < 1e-6) && (x - y > -1e-6);
    }
};


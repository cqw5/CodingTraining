/*! Source: https://leetcode.com/problems/climbing-stairs
 *! Author: qwchen
 *! Date  : 2017-04-03
 *  爬楼梯
 *  有n个台阶，每次可以爬1步或2步，求有多少中爬法
 */

/*
 * 思路：
 *   其实这是一个“斐波那契数列”问题
 * 时间复杂度：O(n) 0ms
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int f1 = 1;
        int f2 = 2;
        int fn;
        for (int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};


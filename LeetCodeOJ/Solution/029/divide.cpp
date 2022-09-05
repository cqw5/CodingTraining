/*! Source: https://leetcode.com/problems/remove-element/
 *! Author: qwchen
 *! Date  : 2016-12-07
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：https://leetcode.cn/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
 *   关于如何提高效率快速逼近结果
 *   举个例子：11 除以 3 。
 *   首先11比3大，结果至少是1，然后我让3翻倍，就是6，发现11比3翻倍后还要大，那么结果就至少是2了，那我让这个6再翻倍，得12，11不比12大，
 *   吓死我了，差点让就让刚才的最小解2也翻倍得到4了。但是我知道最终结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？
 *   我让11减去刚才最后一次的结果6，剩下5，我们计算5是3的几倍，也就是除法，看，递归出现了。说得很乱，不严谨，大家看个大概，然后自己在纸上画一画，或者直接看我代码就好啦！
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;  // int最小的数，除以-1会溢出
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
        // 都改为负号是因为int 的范围是[2^31, 2^31-1]，如果a是-2^32，转为正数时将会溢出
        dividend = dividend > 0? -dividend: dividend;
        divisor =  divisor > 0? -divisor: divisor;
        int count = div(dividend, divisor);
        if (sign == -1) count = -count;
        return count;
    }

    int div(int a, int b) {
        if (a > b) return 0;
        int count = 1;
        int tb = b;
        if (tb + tb > a && tb + tb < 0) {  // 溢出之后不再小于0
            tb += tb;
            count += count;
        }
        return count + div(a-tb, b);
    }
};
/*! Author: qwchen
 *! Date  : 2016-11-10
 * 9.1：跳台阶
 * 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 思路：假设有n个台阶，有f(n)中跳法；每次跳有两种选择，跳1级台阶或条两级台阶。
 *           如果第一次跳1个台阶，则剩下的有f(n-1)种跳法
 *           如果第一次跳2个台阶，则剩下的有f(n-2)种跳法
 *       因此可以得到递归表达：f(n) = f(n-1) + f(n-2)
 *       另外：f(0) = 0, f(1) = 1, f(2) = 2
 *       与斐波那契数列问题类似。不同之处在f(2) = 2， f(2) ≠ f(1) + f(0)
 */

#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度：O(n)，空间复杂度：O(1)
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int f1 = 1;
        int f2 = 2;
        int fn = 0;
        for (int i = 3; i <= number; i++){
            fn = f2 + f1;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};
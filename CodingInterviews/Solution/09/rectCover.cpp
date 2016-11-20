/*! Author: qwchen
 *! Date  : 2016-11-10
 * 9.2：矩形覆盖
 * 题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 思路：用f(n)表示2*n的大矩阵中的方法。每个小矩阵有2种方法：
 *           如果第一次矩阵树着放，则剩下的有f(n-1)种放法。
 *           如果第一次矩阵横着放，则剩下的有f(n-2)种跳法。
 *       因此可以得到递归表达：f(n) = f(n-1) + f(n-2)
 *       另外：f(0) = 0, f(1) = 1, f(2) = 2
 *       与斐波那契数列问题类似。不同之处在f(2) = 2， f(2) ≠ f(1) + f(0)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
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
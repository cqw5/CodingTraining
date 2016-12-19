/*! Source: https://leetcode.com/problems/reverse-integer/
 *! Author: qwchen
 *! Date  : 2016-12-19
 * 数字翻转
 */

#include <iostream>
#include <climits>

using namespace std;

/*
 * 思路：
 *   两个注意点：1. 负数取模的结果仍然是负数，因此不用区分正数和负数
 *               2. 注意溢出的问题
 *   此题如果想转化为正整数，那么遇到INT_MIN时，就会出错，因为INT_MIN变为正数就会溢出了，因此不能使用常用的先转化为正数的方法
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

/*
 * 错误的解法，遇到-2147483648（INT_MIN）时溢出出错
 */
class Solution2 {
public:
    int reverse(int x) {
        int y = 0;
        int flag = 1;
        if (x < 0) {
            cout << x << endl;
            x = -1 * x;
            cout << x << endl;
            flag = -1;
        }
        while (x != 0) {
            int tail = x % 10;
            cout << y << endl;
            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && tail > INT_MAX % 10)) {
                return 0;
            }
            y = y * 10 + tail;
            x /= 10;
        }
        return flag * y;
    }
};

void testSolution() {
    int x = -2147483648;
    Solution2 sol;
    cout << sol.reverse(x) << endl;
}

int main() {
    testSolution();
}


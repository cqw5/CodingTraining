/*! Source: http://www.lintcode.com/zh-cn/problem/print-numbers-by-recursion/
 *! Author: qwchen
 *! Date  : 2016-11-16
 *  用递归打印数字
 *  思路：打印n位数，按照1-9、10-99、100-999、1000-9999的顺序打印，有n位只需要递归n次，不会出现递归栈溢出
 */

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> num;
        recursion(num, n, 1);
        return num;
    }

private:
    void recursion(vector<int>& num, int n, int min_num) {
        if (n <= 0 ) return;
        int max_num = min_num * 10;
        for (int i = min_num; i < max_num; i++) {
            num.push_back(i);
        }
        recursion(num, n - 1, max_num);
    }
};
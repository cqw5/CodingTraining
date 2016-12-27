/*! Source: https://leetcode.com/problems/happy-number/
 *! Author: qwchen
 *! Date  : 2016-12-27
 *  判断一个数是不是一个happy数
 */

/*
 * 思路：
 *   构建一个hash表，存放曾经得到的sum
 *   对于每一个数n，计算其每一个位的平方的和sum：
 *       如果sum = 1，则该数是happy number，退出；
 *       否则，如果sum不在hash表中，将sum放入hash表，然后重复该过程；
 *             如果sum在hash表中，将则不断计算下去都不会变成1，而是不断循环，应该该数不可能是happy number
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
            if (set.find(n) == set.end()) set.insert(n);
            else                          return false;
        }
        return true;
    }
};


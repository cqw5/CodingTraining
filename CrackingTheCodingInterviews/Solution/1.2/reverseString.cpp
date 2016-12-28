/*! Author: qwchen
 *! Date  : 2016-12-28
 *! 字符串与数组: 1.2
 *! 题目描述:
 *    请实现一个算法，在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。
 *    给定一个string iniString，请返回一个string，为翻转后的字符串。保证字符串的长度小于等于5000。
 *  Solution为该文件下最优解决方案
 */

class Solution {
public:
    string reverseString(string iniString) {
        int low = 0, high = iniString.size() - 1;
        while (low <= high) {
            swap(iniString[low++], iniString[high--]);
        }
        return iniString;
    }
};


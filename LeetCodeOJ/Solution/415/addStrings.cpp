/*! Source: https://leetcode.com/problems/add-strings
 *! Author: qwchen
 *! Date  : 2017-03-28
 *  两个字符串相加
 *    假设字符串很长，不能直接转化为整数。保证字符串是正整数。
 */

/* 
 * 思路：
 *   从两个字符串的尾部开始按位相加，并用一个carry来保存进位
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string num3 = "";
        int i = num1.size()-1, j = num2.size()-1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) {
                carry += num1[i--] - '0';
            }
            if (j >= 0) {
                carry += num2[j--] - '0';
            }
            char str = '0' + (carry % 10);
            num3 = str + num3;
            carry /= 10;
        }
        return num3;
    }
};


/*! Source: https://leetcode.com/problems/reverse-string
 *! Author: qwchen
 *! Date  : 2017-04-02
 *  字符串翻转
 */

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};


/*! Source: https://leetcode.com/problems/add-binary/
 *! Author: qwchen
 *! Date  : 2016-12-23
 * Solution 为该文件最优的方案
 */

/*
 * 思路：
 *   两个数字相加，应该从最后一位加起
 *   注意到：c % 2是进位后剩余的；c / 2是进位。
 *   字符串有拼接功能，不需要用一个栈从后存到尾，再反向回来。
 * 时间复杂度：O(max(m,n))
 * 空间复杂度：O(max(m,n))
 */ 
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0? a[i--] - '0': 0;
            c += j >= 0? b[j--] - '0': 0;
            s = char('0' + c % 2) + s;
            c /= 2;                       // c保留了进位
        }
        return s;
    }
};

class Solution2 {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        if (lenA < lenB) return addBinary(b, a);
        stack<char> s;
        int tag = 0;
        int i = lenA - 1;
        int j = lenB - 1;
        while (j >= 0) {
            int temp = a[i--] - '0' + b[j--] - '0' + tag;
            if (temp > 1) {
                temp -= 2;
                s.push('0' + temp);
                tag = 1;
            }
            else {
                s.push('0' + temp);
                tag = 0;
            }
        }
        while (i >= 0) {
            int temp = a[i--] - '0' + tag;
            if (temp > 1) {
                temp -= 2;
                s.push('0' + temp);
                tag = 1;
            }
            else {
                s.push('0' + temp);
                tag = 0;
            }
        }
        if (tag == 1) {
            s.push('1');
        }
        string c = "";
        while(!s.empty()) {
            c.push_back(s.top());
            s.pop();
        }
        return c;
    }
};
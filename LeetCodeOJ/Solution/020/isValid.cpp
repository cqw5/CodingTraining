/*! Source: https://leetcode.com/problems/valid-parentheses/
 *! Author: qwchen
 *! Date  : 2016-12-22
 *  判断字符串是否合法
 */

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if (len == 0) return true;
        stack<char> stk;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else                return false;
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else                return false;
            }
            else if (s[i] == '}') {
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else                return false;
            }
        }
        if (stk.empty()) return true;
        else           return false;
    }
};


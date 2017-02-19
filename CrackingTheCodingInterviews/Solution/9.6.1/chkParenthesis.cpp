/*! Author: qwchen
 *! Date  : 2017-02-19
 *! 递归和动态规划: 9.6.1 合法括号序列判断
 *！题目描述：
 *    对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串(只包含括号，并且括号匹配)。
 */

/*
 * 思路：
 *   使用栈来实现，遇到非括号字符或左右括号不匹配时，返回false 
 */
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> s;
        for (int i = 0; i < n; i++) {
            if (A[i] == '(') s.push(A[i]);
            else if (A[i] == ')' && !s.empty()) s.pop();
            else return false;
        }
        if (s.empty()) return true;
        else           return false;
    }
};


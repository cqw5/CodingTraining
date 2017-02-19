/*! Author: qwchen
 *! Date  : 2017-02-19
 *! 递归和动态规划: 9.6.2 括号的所有可能组合
 *！题目描述：
 *      打印n对括号的所有有效组合
 */

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// 将括号插入到s[0, leftSize-1] 与 s[leftSize: s.size()-1]之间
string insertInside(string s, int leftSize) {
    return s.substr(0, leftSize) + "()" + s.substr(leftSize, s.size());
}

/*
 * 思路：
 *   通过递推发现规律：
 *   n = 2: (())  ()()
 *   n = 3: (()())  ((()))  ()(())  (())()  ()()()
 *   可以对于n，只需要在n-1的组合中每个字符串最前面和以及原有没对括号里面插入一对括号。
 *   至于插入其他任意位置，比如字符串的末尾，都会跟之前的情况重复。
 *   使用hash来避免重复
 */
unordered_set<string> generateParens(int count) {
    unordered_set<string> parens;
    if (count == 1) {
        parens.insert("()");
    }
    else {
        unordered_set<string> subParens = generateParens(count - 1);
        for (string s: subParens) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    string str = insertInside(s, i + 1);
                    parens.insert(str);
                }
            }
            parens.insert("()" + s);
        }
    }
    return parens;
}


int main() {
    unordered_set<string> parens = generateParens(2);
    for (auto it = parens.begin(); it != parens.end(); it++) {
        cout << *it << endl;
    }
    parens = generateParens(3);
    for (auto it = parens.begin(); it != parens.end(); it++) {
        cout << *it << endl;
    }
}


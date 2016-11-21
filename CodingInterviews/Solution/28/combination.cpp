/*! Author: qwchen
 *! Date  : 2016-11-21
 *  28.1. 字符串组合
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 思想：可以n个字符串组成长度为m的组合的问题分解成两个子问题，分布是：
 *           如果组合里包含第一个字符，则求n-1个字符中长度为m-1的组合
 *           如果组合里不包含第一个字符，则求n-1个字符中长度为m的组合
 *       可以通过递归的方式来解决
 *       递归方程为：C(n, m) = C(n-1, m) + C(n-1, m-1)
 *       当 m == 0 或者 n < m 时停止递归
 */
class Solution {
public:
    /*
     * 求字符串s中m个数的组合
     */
    vector<string> combination(string s, int m) {
        vector<string> result;
        string subStr = "";
        combination(result, s, subStr, 0, s.size(), m);
        return result;
    }

private:
    /*
     * result ：存放所有的组合结果
     * s      ：原始的字符串
     * subStr ：存放当前的组合结果
     * begin  ：剩余字符串的起始下标
     * end    ：剩余字符串的终止下标的下一个位置，end-start就是剩余字符串的长度
     * m      ：剩余字符串的m个数的组合
     */
    void combination(vector<string>& result, string s, string& subStr, int begin, int end, int m) {
        if (m == 0) {
            result.push_back(subStr);
        }
        else if (end - begin < m) {
            return;
        }
        else {
            subStr.push_back(s[begin]);
            combination(result, s, subStr, begin+1, end, m-1);
            subStr.pop_back();
            combination(result, s, subStr, begin+1, end, m);
        }
    }
};

void testSolution() {
    string s = "abcd";
    Solution sol;
    for (int i = 1; i <= s.size(); i++) {
        vector<string> result = sol.combination(s, i);
        for (string subStr: result) {
            cout << subStr << " ";
        }
        cout << endl;
    }
}

int main() {
    testSolution();
    return 0;
}


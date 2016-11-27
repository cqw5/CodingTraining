/*! Author: qwchen
 *! Date  : 2016-11-27
 *  49. 把字符串转换成整数
 *  题目描述:
 *      将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。数值为0或者字符串不是一个合法的数值则返回0 
 *  输入描述:
 *      输入一个字符串,包括数字字母符号,可以为空
 *  输出描述:
 *      如果是合法的数值表达则返回该数字，否则返回0
 *  不考虑溢出问题
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 思路：
 *   除了首位是+或-的非0-9字符合法，其他位置任何非0-9的字符都是不合法的。
 *   先判断字符串是否为空
 *   判断首位：
 *     是否为-，如果是说明是负数，后面将数转为负数；
 *     否则是否为0-9的字符，如果是，转化为0-9的数字
 *     否则是否为+，如果不是说明是非法字符
 *   判断其他位：
 *     如果是0-9的字符，合并到整数中
 *     如果不是，则为非法字符
 */
class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int num = 0;
        bool flag = false;
        if (str[0] == '-') {
            flag = true;
        }
        else if (str[0] >= '0' && str[0] <= '9') {
            num = str[0] - '0';
        }
        else if (str[0] != '+') {
            return 0;
        } 
        for (int i = 1; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            }
            else {
                return 0;
            }
        }
        if (flag) {
            num = -1 * num;
        }
        return num;
    }
};


void testSolution() {
    Solution sol;
    string s = "-2147483647";
    cout << sol.StrToInt(s) << endl;
}

int main() {
    testSolution();
    return 0;
}
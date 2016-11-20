/*! Author: qwchen
 *! Date  : 2016-11-11
 * 11：数值的整数次方
 * 思想：本题表面很容易，但需要注意几个问题
 *       1. 浮点数不能用==来判断是否相等
 *       2. 0的负数次幂没有意义
 *       3. 幂可以是整数、0、负数。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        // 0的负数次幂没有意义
        if (equal(base, 0.0) && exponent < 0) {
            throw new range_error("0 have not negative exponent");
        }
        // 求base的非负数次幂，如果exponent是负数，结果求倒数即可。
        int absExponent = exponent;
        if (exponent < 0) absExponent = -1 * absExponent;
        double result = PowerWithPositiveExponent(base, absExponent);
        if (exponent < 0) result = 1.0 / result;
        return result;
    }
private:
    // 求base的exponent次幂，其中exponent为非负数
    double PowerWithPositiveExponent(double base, int exponent){
        double result = 1.0;
        for (int i = 0; i < exponent; i++){
            result *= base;
        }
        return result;
    }

    // 判断两个浮点数是否相当
    bool equal(double num1, double num2){
        if ((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001)) return true;
        else                                                         return false;
    }
};

void testSolution(){
    vector<pair<int, int>> vec = {
        make_pair(0, 0),
        make_pair(2, 3),
        make_pair(2, -3),
        make_pair(-2, -2)
    };
    Solution sol;
    for(auto element: vec){
        cout << sol.Power(element.first, element.second) << endl;
    }
}

int main(){
    testSolution();
    return 0;
}
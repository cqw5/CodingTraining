/*! Author: qwchen
 *! Date  : 2017-09-03
 *  整数的翻转
 *  将一个整数翻转，如：-1000 => -1, 1234 => 4321
 */

#include <iostream>
#include <climits>

using namespace std;

int reverse(int num) {
    int res = 0;
    while(num != 0) {
        int carry = num % 10;
        if((num > 0) && (res > INT_MAX / 10 || (res == INT_MAX / 10 && carry > INT_MAX % 10))) {
            throw range_error("Out Of Range");
        }
        if((num < 0) && (res < INT_MIN / 10 || (res == INT_MIN / 10 && carry < INT_MIN % 10))) {
            throw range_error("Out of Range");
        }
        num /= 10;
        res = res * 10 + carry;
    }
    return res;
}

int main() {
    cout << reverse(-10010) << endl;
    cout << reverse(9876) << endl;
    cout << reverse(2147483647) << endl;
    cout << reverse(-2147483648) << endl;
    return 0;
}


/*! Source: https://leetcode.com/problems/add-digits
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  数根问题
 */

#include <iostream>

using namespace std;

/*
 * 有固定的数学公式
 * 时间复杂度: O(1). 3 ms. beats 70.13% of cpp submissions.
 * 空间复杂度: O(1)
 */
class Solution1 {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

/*
 * 时间复杂度: O(n). 6 ms. beats 18.13% of cpp submissions.
 * 空间复杂度: O(1)
 */
class Solution2 {
public:
    int addDigits(int num) {
        int newNum = num;
        while(newNum / 10 != 0) {
            num = newNum;
            newNum = 0;
            while (num) {
                newNum += num % 10;
                num /= 10;
            }
        }
        return newNum;
    }
};

int main() {
	Solution1 s1;
	Solution2 s2;
	cout << s1.addDigits(38) << endl;
	cout << s2.addDigits(38) << endl;
}


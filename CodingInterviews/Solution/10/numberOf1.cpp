/*! Author: qwchen
 *! Date  : 2016-11-11
 * 10：二进制中1的个数
 * 注意：
 * 1. c++中负数存储时，不是简单的将符号位置为1，而是采用补码的形式存储的：负数最高位为符号位，也就是1，其余全部取反，然后再加1。
 *    假如操作系统是32位，-1的二进制存储不是：1000 0000 0000 0001，而是：1111 1111 1111 1110+1即1111 1111 1111 1111
 * 2. 考虑正数和负数在右移时的不同：对于正数，右移是再数前面填充0；对于负数，右移时是在前面填充1。这些1会干扰到1个数的统计。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 适用于C++中负数的二进制表示
 */
class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        int flag = 1;
        while(flag){
            if (n & flag) count++;
            flag = flag << 1;      // 0000 0001, 0000 0010, 0000 0100, 0000 1000, ... , 左移到最终为0
        }
        return count;
    }
};

/*
 * 适用于正常的负数二进制表示
 * 先将负数取反，就变成正数，并给count+1，来保存负号的1，剩下的就转化成正数的问题了。
 */
class Solution1 {
public:
     int NumberOf1(int n) {
        int count = 0;
        int flag = 1;
        if (n < 0) {
            n = -1 * n;
            count++;
        }
        while(n > 0){
            if (n & flag) count++; // (n & 1) 比 (n %2 == 1) 快许多
            n = n >> 1;            // n >> 1 比 n / 2 快许多
        }
        return count;
     }
};


void testSolution(){
    vector<int> vec = {9, -9};
    Solution sol;
    Solution1 sol1;
    for (int num: vec){
        cout << sol.NumberOf1(num) << endl;
        cout << sol1.NumberOf1(num) << endl;
    }
}

int main(){
    testSolution();
    return 0;
}

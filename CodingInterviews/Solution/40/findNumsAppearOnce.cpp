/*! Author: qwchen
 *! Date  : 2016-11-24
 *  40. 数组中只出现一次的数字
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 思路：
 *     该题可以用一个hash表来存放每个元素，并判断是否重复，时间复杂度为：O(n)，但是空间复杂度也为O(1)
 *     借助位运算，可以把空间复杂度降到O(1)
 *     根据异或的性质：任何数与自己异或都等于0。那么如果我们从头到尾遍历一遍数组，所有成对的数字将会相互抵消，最后剩下的就是不成对的数字的异或。
 *     如果数组中只有一个只出现1次的数，其他都成对出现，那这样就直接可解了；但是该题有两个只出现一次的数字。
 *     我们一样对数组中所有元素求异或，结果所有成对出现的数都被抵消，最终剩下两个数的异或，而这两个数不同，异或的结果肯定不为0
 *     接着对异或结果进行从低位到高位查询，找到第一个位1的二进制位，记为第n位。
 *     然后在遍历一遍数组将第n位为1的数组分为一半，第n位为0的数组分为另一半，那么这两个只出现一次的数字会被分开，而相同的数字肯定被分在一块
 *     现在分别对两个子数组求异或，得到结果就是这个只出现一次的元素的值。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.size() <= 0) {
            return;
        }
        int exclusiveOR = 0;
        for (int i = 0; i < data.size(); i++) {
            exclusiveOR ^= data[i];
        }
        *num1 = 0;
        *num2 = 0;
        int indexBit = findFirstBitIs1(exclusiveOR);
        for (int i = 0; i < data.size(); i++) {
            if (isBit1(data[i], indexBit)) {
                *num1 ^= data[i];
            }   
            else {
                *num2 ^= data[i];
            }
        }
    }

private:
    /*
     * 查找数num的二进制位中从低到高第一个为1的位
     */
    int findFirstBitIs1(int num) {
        int indexBit = 1;
        while ((num & 1) == 0) {
            num = num >> 1;
            indexBit++;
        }
        return indexBit;
    }
    
    /*
     * 判断数num的二进制位中从低到高低indexBit位是否为1
     */
    bool isBit1(int num, int indexBit) {
        num = num >> (indexBit - 1);
        return num & 1;
    }
};

void testSolution(){
    vector<int> a = {2, 4, 3, 6, 3, 2, 5, 5};
    Solution sol;
    int num1 = 0;
    int num2 = 0;
    int* pnum1 = &num1;
    int* pnum2 = &num2;
    sol.FindNumsAppearOnce(a, pnum1, pnum2);
    cout << *pnum1 << " " << *pnum2 << endl;
}

int main() {
    testSolution();
    return 0;
}


/*! Author: qwchen
 *! Date  : 2017-02-12
 *! 位操作：5.4 整数转化
 *！题目描述：
 *      编写一个函数，确定需要改变几个位，才能将整数a转变成整数b。
 *      给定两个整数int a，int b。请返回需要改变的数位个数。
 */

/*
 * 思路：
 *   将a和b异或，异或的结果中1的个数就是a和b中不同位的数目。将这些1的个数统计出来，就得到结果
 */
class Transform {
public:
    int calcCost(int a, int b) {
        int count = 0;
        for (int c = a ^ b; c != 0; c = c >> 1)
            count += c & 1;
        return count;
    }
};


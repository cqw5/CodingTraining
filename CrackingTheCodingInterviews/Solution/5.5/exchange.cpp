/*! Author: qwchen
 *! Date  : 2017-02-12
 *! 位操作：5.5 奇偶位交换
 *！题目描述：
 *      请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
 *      给定一个int x，请返回交换后的数int。
 */

/*
 * 思路：
 *   用x & 1010取出偶数位，然后将偶数位右移一位，使其变成奇数位
 *   用x & 0101取出奇数位，然后将奇数位左移一位，使其变成偶数位
 *   再将奇数位和偶数位合并
 */
class Exchange {
public:
    int exchangeOddEven(int x) {
        return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);  // 32位机器
        // return ((x & 0xaaaaaaaaaaaaaaaa) >> 1) | ((x & 0x5555555555555555) << 1);  // 64位机器
    }
};


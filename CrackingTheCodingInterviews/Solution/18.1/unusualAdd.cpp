/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 数学思维：18.1 另类加法
 *! 题目描述：
 *    请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
 *    给定两个int A和B。请返回A＋B的值
 */

/*
 * 思路：
 *   如果基本的运算符都不能使用，那就只能使用位运算
 *   将A和B相加但不进位，即A^B
 *   将A和B进位但不相加，即(A&B)<<1
 *   递归将这两个结果相加
 * 时间复杂度：O(1)
 */
class UnusualAdd {
public:
    int addAB(int A, int B) {
        if (B == 0) return A;      // 直到进位B == 0
        int sum = A ^ B;           // 相加但不进位
        int carry = (A & B) << 1;  // 进位但不相加
        return addAB(sum, carry);  // 递归将 相加不进位结果 和 进位不相加结果 相加
    }
};


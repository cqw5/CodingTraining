/*! Author: qwchen
 *! Date  : 2017-02-12
 *! 位操作：5.1 二进制小数
 *！题目描述：
 *    有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
 *    给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
 */

/*
 * 将浮点数乘以2(相当于在二进制下移动小数点)：
 *     若结果大于0，表示小数的第一位为1；
 *     否则为0；
 * 保留新的浮点数的小数部分，不断重复这个过程。
 */
class BinDecimal {
public:
    string printBin(double num) {
        if (num >= 1 || num <= 0) return "Error";
        string binary = "0.";
        while (num > 0) {
            if (binary.size() >= 32) return "Error";
            num *= 2;
            if (num >= 1) {
                binary += "1";
                num -= 1;
            }
            else {
                binary += "0";
            }
        }
        return binary;
    }
};


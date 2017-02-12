/*! Author: qwchen
 *! Date  : 2017-02-12
 *! 位操作：5.1 二进制插入
 *！题目描述：
 *      有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j(高位)到第i位(低位),其中二进制的位数从低位数到高位且以0开始。
 *      给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数。保证j-1+1 > m的二进制位数
 */

/*
 * 思路：
 *   先要对n的j到i位进行清0，然后再替换为m
 */

class BinInsert {
public: 
    int binInsert(int n, int m, int i, int j) {
    	int mark = ~(((1 << (j - i + 1)) - 1) << i); // 构造清0的掩码
        n = n & mark;
        mark = m << i;  // 构造替换的掩码
        n = n | mark;
        return n;
    }
};


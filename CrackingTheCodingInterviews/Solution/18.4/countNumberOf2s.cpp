/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 数学思维：18.4 2的个数
 *! 题目描述：
 *    请编写一个方法，输出0到n(包括n)中数字2出现了几次。
 *    给定一个正整数n，请返回0到n的数字中2出现了几次。
 */

/*
 * 思路：
 *   暴力解法，变量2~n中的每一个数，计算其中2的个数。
 * 结果会超时
 */
class Count2 {
public:
    int countNumberOf2s(int n) {
        int numOf2 = 0;
        for (int i = 2; i <= n; i++) {
            numOf2 += count(i);
        }
        return numOf2;
    }
private:
    int count(int k) {
        int i = 0;
        while (k > 0) {
            if (k % 10 == 2) {
                i++;
            }
            k /= 10;
        }
        return i;
    }
};


/*
 * 思路：
 *   前面的暴力解法是从一个范围来看待这个问题，下面从数字的每个位来看待这个问题
 *   考虑到每10个数字中，最后一位为2的情况“大概”会出现1次，因为2在连续10个数中都会出现1次
 *   考虑n的每一个位，对于第d位：
 *       - 当num[d] < 2时，将原来的数往下降至最近的10^(d+1)，再除以10，就可以算出第d位数为2的数量
 *       - 当num[d] > 2时，将原来的数往上升至最近的10^(d+1)，再除以10，就可以算出第d位数为2的数量
 *       - 当num[d] = 2时，将原来的数往下降至最近的10^(d+1)，再除以10，
 *                         然后再加上第d位以下的值+1（所以+1是考虑0），就可以算出第d位数为2的数量
 * 时间复杂度：O(n的位数)
 * 空间复杂度：O(1)
 */
class Count2 {
public:
    int countNumberOf2s(int n) {
		int count = 0;
        int len = size(n);
        for (int d = 0; d < len; d++) {
            count += countNumberOf2AtDigit(n, d);
        }
        return count;
    }
private:
    int countNumberOf2AtDigit(int num, int d) {
        int powOf10 = pow(10, d);                // 10^d
        int nextPowOf10 = powOf10 * 10;          // 10^(d+1)
        int roundDown = num - num % nextPowOf10; // 原来的数往下降至最近的10^(d+1)
        int roundUp = roundDown + nextPowOf10;   // 将原来的数往上升至最近的10^(d+1)
        int digit = (num / powOf10) % 10;        // num[d]
        if (digit < 2) {
            return roundDown / 10;
        }
        else if (digit > 2) {
            return roundUp / 10;
        }
        else { // digit == 2
            int right = num % powOf10;
            return roundDown / 10 + right + 1;
        }
    }
    
    // 计算n的位数，如100的位数为3
    int size(int n) {
        int i = 0;
        while (n >= 1) {
            i++;
            n /= 10;
        }
        return i;
    }
    
    // C++内置的pow是针对浮点数的，(int)pow(10,2) == 99，异常，因此自己写pow
    int pow(int base, int exp) {
        int res = 1;
        for (int i = 0; i < exp; i++) {
            res *= base;
        }
        return res;
    }
};




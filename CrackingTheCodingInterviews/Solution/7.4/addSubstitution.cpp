/*! Author: qwchen
 *! Date  : 2017-02-15
 *! 数学基础: 7.4 加法运算替代
 *  题目描述
 *    请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
 *    给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，0为求a ／ b，-1为求a － b。
 *    请返回计算的结果，保证数据合法且结果一定在int范围内。
 */

class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        if (type == 1)      return multiply(a, b);
        else if (type == 0) return divide(a, b);
        else                return minus(a, b);
    }

private:
    int negate(int a) {
        int neg = 0;
        int d = a < 0? 1: -1;
        while (a != 0) {
            neg += d;
            a += d;
        }
        return neg;
    }
    
    int abs(int a) {
        if (a < 0) return negate(a);
        else       return a;
    }
    
    int minus(int a, int b) {
        return a + negate(b);
    }
    
    int multiply(int a, int b) {
        if (a < b) return multiply(b, a);
        int sum = 0;
        int positiveB = abs(b);
        for (int i = 0; i < positiveB; i++) {
            sum += a;
        }
        if (b < 0) return negate(sum);
        else       return sum;
    }
    
    int divide(int a, int b) {
        int positiveA = abs(a);
        int positiveB = abs(b);
        int fact = 0;
        int sum = 0;
        while (sum + positiveB < positiveA) {
            sum += positiveB;
            fact++;
        }
        if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
            return fact;
        }
        else {
            return negate(fact);
        }
    }
};


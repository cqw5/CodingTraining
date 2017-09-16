/*! Author: qwchen
 *! Date  : 2017-09-03
 * 浮点数开根号
 */

#include <iostream>
#include <math.h>

using namespace std;

/*
 * 思想：二分法，假定中位数为最终解
 *   假定下限为0，上限为该num，然后求中值；
 *   然后比较中值的平方和num的大小，并根据大小修改上限和下限；
 *   然后重新计算中值，直到两次中值得距离小于给定的精度。
 */
double sqrtByBisection(double num) {
    double low = 0, high = num < 1? 1: num;
    double eps = 1e-6;
    double mid = (low + high) / 2;
    double last;
    do {
        double midmid = mid * mid;
        if(midmid == num) {
            return mid;
        }
        if(midmid > num) {
            high = mid;
        }
        else {
            low = mid;
        }
        last = mid;
        mid = (low + high) / 2;
    }while(fabs(mid - last) > eps);
    return mid;
}

/* 参考：http://blog.csdn.net/yutianzuijin/article/details/40268445
 * 思想：牛顿法
 *   设y = x^2 - num，那么当y = 0时，正数的x就是num的开平方
 *   x_i+1 = (x_i + num/x_i) / 2
 */
double sqrtByNewton(double num) {
    double eps = 1e-6;
    double last;
    double val = num;
    do {
        last = val;
        val = (last + num / last) / 2;
    }while(fabs(val - last) < eps);
    return val;
}

int main() {
    cout << sqrtByBisection(4.0) << endl;
    cout << sqrtByNewton(4.0) << endl;
    return 0;
}


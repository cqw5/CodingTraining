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
		if(mid * mid > num) {
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

int main() {
	cout << sqrtByBisection(4.0) << endl;
	return 0;
}


/*! Author: qwchen
 *! Date  : 2017-09-06
 *  两个数的最小公约数（编程之美2.7）
 */
#include <iostream>

using namespace std;

/*
 * 思路：辗转相除法
 *   如果一个数能被x和y整除，那么这个数也能被x%y和y整除
 *   即通过f(x,y)=f(y,x%y)(x>=y>0)，不断把原问题转化为求两个更小的数的最大公约数，直到其中一个数为0
 */
int gcd1(int x, int y) {
    return y == 0? x: gcd1(y, x%y);
}

/*
 * 思路：
 *   同样是辗转相除法，但是考虑到上面的解法的%运算的代价太大，使用减法替代
 *   即通过f(x,y)=f(x-y,y)，不断把原问题转化为求两个更小的数的最大公约数，直到其中一个数为0
 *   为了避免x<y时，x-y<0；当x<y时，交换x和y，保证x>y
 */
int gcd2(int x, int y) {
    if(x < y) return gcd2(y, x);
    return y == 0? x: gcd2(x-y, y);
}

int main() {
    int x = 11231232, y = 231234;
    cout << gcd1(x, y) << endl;
    cout << gcd2(x, y) << endl;
    return 0;
}

/*! Author: qwchen
 *! Date  : 2017-05-24
 *  N!末尾有多少个0
 *  题目：
 *    给定一个整数N，那么N的阶乘N!末尾有多少个0呢？
 *    例如：N=10，N!=3628800，N!的末尾有两个0
 */
#include <iostream>

using namespace std;

int factorial(int N) {
    int res = 0;
    for (int i = 5; i <= N; i++) {
        int j = i;
        while (j % 5 == 0) {
            res++;
            j /= 5;
        }
    }
    return res;
}

int main() {
    int N = 10;
    int c = factorial(N);
    cout << c << endl;
}

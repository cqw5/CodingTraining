/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 数学思维：18.3 等概率采样
 *! 题目描述：
 *    编写一个方法，从大小为n的数组中随机选出m个整数。要求每个元素被选中的概率相同。
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * 思路：
 *   无放回采样就是一个等概率采样，每个样本被选中的概率相同
 *   第0轮，从数组A[0:n-1]中随机选择一个元素A[k]，将其和A[n-1]交换
 *   第1轮，从数组A[0:n-2]中随机选择一个元素A[k]，将其和A[n-2]交换
 *   ......
 *   第m-1轮，从数组A[0:n-m]中随机选择一个元素A[k]，将其和A[n-m]交换
 *   最后A[n-m, n-1]就是被选中的m个元素
 */
int randInt(int n) {
    srand((unsigned)time(0));
    return rand() % n; 
}

vector<int> pickM(vector<int> num, int n, int m) {
    if (n <= m) return num;
    vector<int> res;
    for (int i = 0; i < m; i++ ) {
        int k = randInt(n - i);
        res.push_back(num[k]);
        swap(num[k], num[n-1-i]);
    }
    return res;
}

int main() {
    vector<int> num;
    int n = 20;
    int m = 5;
    for (int i = 0; i < n; i++) {
        num.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    vector<int> res = pickM(num, n, m);
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}


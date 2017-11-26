/*! Author: qwchen
 *! Date  : 2017-11-26
 *  数据流中等概率采样k个（编程珠玑）
 *  思路：
 *    先把读到的前k个对象放入“水库”，对于第k+1个对象开始，以k/(k+1)的概率选择该对象，以k/(k+2)的概率选择第k+2个对象，以此类推，以k/m的概率选择第m个对象（m>k）。
 *    如果m被选中，则随机替换水库中的一个对象。最终每个对象被选中的概率均为k/n，
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 返回一个[k, m]之间的数
int randint(int k, int m) {
    return k + rand() % (m - k + 1);
}

// 从n个数中等概率采样1个数
bool sample(vector<int>& input, vector<int>& output, int k) {
    srand(time(nullptr));
    if(input.size() < k) return false;
    int i = 0;
    for(; i < k; i++) {
        output[i] = input[i];
    }
    for(; i < input.size(); i++){
        int m = randint(0, i);
        if(m < k) {
            output[m] = input[i];
        }
    }
    return true;
}

int main() {
    int n = 100;
    int k = 10;
    vector<int> input(n);
    vector<int> output(k);
    for(int i = 0; i < n; i++) {
        input[i] = i;
    }
    sample(input, output, k);
    for(int i = 0; i < k; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}


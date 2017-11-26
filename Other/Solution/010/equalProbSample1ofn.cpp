/*! Author: qwchen
 *! Date  : 2017-11-26
 *  数据流中等概率采样1个（编程珠玑）
 *  思路：
 *    我们总是选择第一个对象，以1/2的概率选择第二个，以1/3的概率选择第三个，以此类推，以1/m的概率选择第m个对象。
 *    当该过程结束时，每一个对象具有相同的选中概率，即1/n。
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 返回一个[k, m]之间的数
int randint(int k, int m){
    return k + rand() % (m - k + 1);
}

// 从n个数中等概率采样1个数
bool sample(vector<int>& input, int& res){
    srand(time(nullptr));
    if(input.size() <= 0) return false;
    res = input[0];
    for(int i = 1; i < input.size(); i++) {
        if(randint(0, i) == 0) {
            res = input[i];
        }
    }
    return true;
}

int main(){
    int n = 100;
    vector<int> input(n);
    int res;
    for(int i = 0; i < n; i++) {
        input[i] = i;
    }
    if(sample(input, res)) {
        cout << res << endl;
    }
    return 0;
}


/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 数学思维：18.2 完美洗牌
 *! 题目描述：
 *    编写一个方法，洗一副牌。要求做到完美洗牌，换而言之，这副牌52!种排列组合出现的概率相等。
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * 思路：
 *   我们假定前n-1张牌已经完美洗牌，现在加入第n张牌，只需要将它和数组中前n张牌中随机1张牌交换位置
 *   注意是前n张牌，自己当前的位置也可以。
 */

// 随机返回1个0~(n-1)之间的数
int randInt(int n) {
    srand((unsigned)time(0));
    return rand() % n; 
}

// 递归解法
// n表示cards有n个元素，最后一个元素为cards[n-1]
vector<int> shuffleArrayRecursively(vector<int> &cards, int n) {
    if (n == 1) return cards;
    shuffleArrayRecursively(cards, n-1);
    int k = randInt(n);
    swap(cards[k], cards[n-1]);
    return cards;
}

// 迭代解法
// n表示cards有n个元素，最后一个元素为cards[n-1]
vector<int> shuffleArrayInteratively(vector<int> &cards, int n) {
    for (int i = 0; i < n; i++) {
        int k = randInt(i+1);
        swap(cards[k], cards[i]);
    }
    return cards;
}

int main() {
    vector<int> cards;
    int n = 54;
    for (int i = 0; i < n; i++) {
        cards.push_back(i);
    }
    vector<int> shuffleArray1 = shuffleArrayRecursively(cards, n);
    for (int i = 0; i < n; i++) {
        cout << shuffleArray1[i] << " ";
    }
    cout << endl;
    vector<int> shuffleArray2 = shuffleArrayInteratively(cards, n);
    for (int i = 0; i < n; i++) {
        cout << shuffleArray2[i] << " ";
    }
    cout << endl;
}


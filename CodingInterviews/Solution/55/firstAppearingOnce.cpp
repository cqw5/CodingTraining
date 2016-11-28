/*! Author: qwchen
 *! Date  : 2016-11-28
 *  55. 字符流中第一个不重复的字符
 *  题目描述
 *    请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
 *  输出描述:
 *    如果当前字符流没有存在出现一次的字符，返回#字符。
 */

#include <iostream>
#include <string>
#include <climits>

using namespace std;

/*
 * 思路：
 *   因为字符只有256种，可以用一个hash表存放。
 *   用一个长整型的整数记录index的下标
 *   用一个长整形的数组记录每个字符首次出现的下标，初始化数组值为-1，表示该元素没出现过；第一次出现时，将该元素对应的值改为元素首次出现的下标；
 *   若一个元素第二次出现，将其值置为-2
 *   查找第一个不重复字符时，只需要遍历256个元素的数组，查找值大于等于0中值最小的元素
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution
{
public:
    Solution() {
        index = 0;
        for (int i = 0; i < 256; i++) {
            hashTable[i] = -1;
        }
    }
    
    // 插入流，构建hash表
    void Insert(char ch) {
        if (hashTable[ch] == -1) {
            hashTable[ch] = index;
        }
        else if (hashTable[ch] >= 0) {
            hashTable[ch] = -2;
        }
        index++;
    }
    // 查找第一个不重复的字符
    char FirstAppearingOnce() {
        int onceChar = '#';
        long long onceIndex = LLONG_MAX;
        for (int i = 0; i < 256; i++) {
            if (hashTable[i] >= 0 && hashTable[i] < onceIndex) {
                onceChar = i;
                onceIndex = hashTable[i];
            }
        }
        return onceChar;
    }

private:
    long long index;           // 标记流的下标
    long long hashTable[256];  // 哈希表
};


void testSolution() {
    Solution sol;
    string str = "google";
    for (auto s: str) {
        sol.Insert(s);
        cout << sol.FirstAppearingOnce() << " ";
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}

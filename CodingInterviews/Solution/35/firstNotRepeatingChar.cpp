/*! Author: qwchen
 *! Date  : 2016-11-22
 *  35. 第一个只出现一次的字符
 */

#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

/*
 * 遍历一遍字符串，用一个hash表记录每一个字符第一次出现的位置和出现的次数。
 * 然后遍历一次hash表，选择出出现次数为1并且最早出现的字符的位置。
 * 不存在这种元素时，返回-1
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)，hash只需要256个元素。
 */
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.size() == 0) {
            return -1;
        }
        unordered_map<char, pair<int, int>> dict;  // <字符, <字符第一次出现的下标, 字符出现的次数>>
        for (int i = 0; i < str.size(); i++) {
            if (dict.find(str[i]) != dict.end()) {
                dict[str[i]].second++;
            }
            else {
                dict[str[i]] = make_pair(i, 1);
            }
        }
        int index = INT_MAX;
        int count = 1;
        for (auto elem: dict) {
            if (elem.second.second == 1 && elem.second.first < index) { // 出现次数为1并且最早出现的字符
                index = elem.second.first;
            }
        }
        if (index != INT_MAX) {
            return index;
        }
        else return -1;
    }
};


void testSolution() {
    string s = "abaccdeff";
    Solution sol;
    cout << sol.FirstNotRepeatingChar(s) << endl;
}

int main() {
    testSolution();
    return 0;
}


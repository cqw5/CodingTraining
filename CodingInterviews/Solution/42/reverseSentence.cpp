/*! Author: qwchen
 *! Date  : 2016-11-27
 *  42.1 翻转单词顺序列
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 思路：
 *   先把整个矩阵逆序，然后再把每个单词逆序
 *   该方法会改变原始的单词，如果不想改变原始的单词，那就重新建一个字符串，那么空间复杂度肯定要O(n)
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.size() < 2) {
            return str;
        }
        reverseWord(str, 0, str.size()-1);
        for (int i = 0, j = 0; i < str.size() && j <= str.size(); j++) {
            if (j == str.size() || str[j] == ' ') {
                reverseWord(str, i, j-1);
                i = j + 1;
            }
        }
        return str;
    }

private:
    void reverseWord(string& str, int low, int high) {
        while (low < high) {
            swap(str[low++], str[high--]);
        }
    }
};


void testSolution() {
    Solution sol;
    string s = "student. a am I";
    cout << sol.ReverseSentence(s) << endl;
}

int main() {
    testSolution();
    return 0;
}


/*! Author: qwchen
 *! Date  : 2016-12-28
 *! 字符串与数组: 1.3
 *! 题目描述:
 *    给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
 *    给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
 *! 测试样例：
 *    "This is nowcoder","is This nowcoder"
 *    返回：true
 *    "Here you are","Are you here"
 *    返回：false
 *  Solution为该文件下最优解决方案
 */

/*
 * 思路：
 *   借助一个hashTable[256]来实现
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool checkSam(string stringA, string stringB) {
        if (stringA.size() != stringB.size()) return false;
        int hashTable[256] = {0};
        for (int i = 0; i < stringA.size(); i++) {
            hashTable[stringA[i]]++;
            hashTable[stringB[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (hashTable[i] != 0) return false;
        }
        return true;
    }
};


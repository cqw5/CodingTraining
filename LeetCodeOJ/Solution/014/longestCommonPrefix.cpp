/*! Source: https://leetcode.com/problems/longest-common-prefix/
 *! Author: qwchen
 *! Date  : 2016-12-20
 *  求一系列字符串的公共前缀
 *  Solution为该文件最佳解决方案
 */


/*
 * 思路：
 *   先将strs内的所有字符串排序，然后找到第一个字符串和最后一个字符串的公共前缀 
 * 时间复杂度：O(mlogm + n)，m为字符串的个数，n为最短的字符串的长度
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if (num < 1) return "";
        if (num == 1) return strs[0];
        string prefix = "";
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[0][i] != strs[num-1][i]) {
                return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};


/*
 * 思路：
 *   对于第一个字符串的每位个字符，判断后面每个字符串该为的字符是否与其相同，不同就返回前面收集到的前缀并返回
 * 时间复杂度：O(m*n)，m为字符串的个数，n为最短的字符串的长度
 */
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if (num < 1) return "";
        if (num == 1) return strs[0];
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < num; j++) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};


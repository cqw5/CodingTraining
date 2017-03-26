/*! Source: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  字典中最长的单词
 *  给定一个字符串s和一个字符串数组dict，从字符串数组中寻找满足一下条件的一个单词：
 *    - 其可以从s中删除元素得到（元素之间的顺序必须一致）
 *    - 其长度最长，若有多个长度最长，取其中字典顺序最小的。
 */

/*
 * 思路：
 *   遍历dict中每个元素，判断它是否可以用字符串s删除某些元素得到。
 *   使用两个指针移动可以判断当前原始是否可以由s删除某些元素得到。
 * 时间复杂度：O(mnk)，m是字符串的长度，n是字典的长度，k是字典中每个元素的平均长度
 * 空间复杂度：O(1)
 */
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        if (s.size() == 0 || d.size() == 0) return res;
        for (string subStr: d) {
            int i = 0; // 指向字典元素
            int j = 0; // 指向字符串s
            while (i < subStr.size() && j < s.size()) {
                if (subStr[i] == s[j]) {
                    i++, j++;
                }
                else {
                    j++;
                }
            }
            if (i >= subStr.size()) { // 说明当前原始可以由字符串删除得到
                if (subStr.size() > res.size()) {
                    res = subStr;   
                }
                else if (subStr.size() == res.size()) {
                    res = min(res, subStr);
                }
            }
        }
        return res;
    }
};

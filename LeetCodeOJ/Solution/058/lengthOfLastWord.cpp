/*! Source: https://leetcode.com/problems/length-of-last-word/#/description
 *! Author: qwchen
 *! Date: 2017-03-15
 *  字符串最后一个单词的长度
 */

/*
 * 思路：
 *   从字符串最后一个字母开始，先去除末尾的空格
 *   然后往前走，计数，指导遇到空格或者遍历完字符串
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }
        return len;
    }
};


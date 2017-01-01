/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 1.5
 *! 题目描述:
 *    利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
 *    比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
 *    给定一个string str为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
 *！测试样例
 *    "aabcccccaaa"
 *    返回："a2b1c5a3"
 *    "welcometonowcoderrrrr"
 *    返回："welcometonowcoderrrrr"
 */

/*
 * 思路：
 *   从头到尾遍历字符串str，用一个新的字符串newStr保存str中的字符和对应的频数。
 *   需要注意的是，count应该转化为string类型；若压缩后的字符串没有变短，返回原先的字符串。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */ 
class Solution {
public:
    string zipString(string str) {
        if (str.size() == 0) return str;
        string newStr;
        int i = 0, j = 1, count = 1;
        for (; j < str.size(); j++) {
            if (str[i] == str[j]) count++;
            else {
                newStr += str[i] + to_string(count);
                count = 1;
                i = j;
            }
        }
        newStr += str[i] + to_string(count);
        if (str.size() < newStr.size()) return str;
        else                            return newStr;
    }
};


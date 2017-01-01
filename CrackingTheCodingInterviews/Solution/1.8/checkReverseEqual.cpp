/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 1.8
 *! 题目描述:
 *    假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。
 *    请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
 *    给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
 *！测试样例：
 *    "Hello world","worldhello "
 *    返回：false
 *    "waterbottle","erbottlewat"
 *    返回：true
 */

/*
 * 思路：
 *   如果s2是由s1旋转而成，那么我们可以找到旋转点。根据旋转点将s1拆分为xy，那么s2则为yx. 即s1 = xy, s2 = yx
 *   同时我们发现yx是xyxy的子串，即s2是s1s1的子串。
 *   因此，要判断s2是否由s1旋转而成，只需要判断s2是否为s1s1的子串。
 */
class Solution {
public:
    bool checkReverseEqual(string s1, string s2) {
        if (s1.size() == s2.size() && s1.size() > 0) {
            string s1s1 = s1 + s1;
            return s1s1.find(s2) != string::npos;  // find函数中，如果s2是s1s1的子串，返回s2第一次出现的位置；否则返回string::npos
        }
        return false;
    }
};


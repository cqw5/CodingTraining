/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 字符串和递归：18.7 最长合成字符串
 *! 题目描述：
 *    有一组单词，请编写一个程序，在数组中找出由数组中字符串组成的最长的串A，即A是由其它单词组成的(可重复)最长的单词。
 *    给定一个string数组str，同时给定数组的大小n。请返回最长单词的长度，保证题意所述的最长单词存在。
 *  测试样例：["a","b","c","ab","bc","abc"],6
 *  返回：3
 */

/*
 * 思路：
 *   先对列表进行排序，按照字符串长度从长到短排序
 *   然后遍历列表，从最长单词到最短单词：
 *     递归的将单词分割成所有可能的两半，然后检查左右两半是否在列表中
 */
class LongestString {
public:
    int getLongest(vector<string> str, int n) {
        // 将列表元素存放到map，便于快速查找
        unordered_map<string, bool> mapping;  
        for (int i = 0; i < n; i++) {
            mapping[str[i]] = true;
        }
        // 按照字符串长度从长到短排序
        sort(str.begin(), str.end(), comp);
        // 从最长单词到最短单词，检查是否有其它字符串组成
        for (string s: str) {
            if (canBuildWord(s, true, mapping)) {
                return s.size();
            }
        }
        // 若都不是，返回0
        return 0;
    }
private:
    // isOriginalWord用于标记当前字符串是否为原始字符串，因为原始字符串肯定在mapping中，
    // 但我们要判断是的字符串是否能有其它两个或两个以上的字符串组成
    bool canBuildWord(string s, bool isOriginalWord, map<string, bool>& mapping) {
        if (mapping[s] && !isOriginalWord) {
            return true;
        }
        for (int i = 1; i < s.size(); i++) { // 递归进行每一种拆分，拆分的左右两个子串长度至少为1
            if (canBuildWord(s.substr(0, i), false, mapping) 
                && canBuildWord(s.substr(i, s.size() - i), false, mapping)) {
                return true;
            }
        }
        return false;
    }
    static bool comp(string str1, string str2) {
        return str1.size() > str2.size();
    }
};


/*! Author: qwchen
 *! Date  : 2017-03-11
 *! 字符串及数据结构：18.8 子串判断
 *! 题目描述：
 *    现有一个小写英文字母组成的字符串s和一个包含较短小写英文字符串的数组p，
 *    请设计一个高效算法，对于p中的每一个较短字符串，判断其是否为s的子串。
 *    给定一个string数组p和它的大小n，同时给定string s，为母串，请返回一个bool数组，每个元素代表p中的对应字符串是否为s的子串。
 *    保证p中的串长度小于等于8，且p中的串的个数小于等于500，同时保证s的长度小于等于1000。
 *  测试样例：["a","b","c","d"],4,"abc"
 *  返回：[true,true,true,false]
 */

/*
 * 思路：
 *   下面直接调用C++ STL的find函数解决了
 *   实际上本题可使用后缀树
 */
class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        vector<bool> res;
        for (int i = 0; i < n; i++) {
            if (s.find(p[i]) != string::npos) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};


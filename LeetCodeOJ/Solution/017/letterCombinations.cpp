/*! Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *! Author: qwchen
 *! Date  : 2016-12-20
 *  以手机按键作为对照，给定一个数字的字符串，返回这个字符串可能代表的字母序列
 */

/*
 * 思路：
 *   使用一个数组来表示手机号码数字对应的字符，数组下标是手机号码，对应的字符是该号码键上的值
 *   然后使用队列来保存当前长度为i的字符。新来一个数字，转化为所有可能的字符，并将队列中的元素都全连接加上新来的字符，用新的字符替换原始队列中的字符
 *   最后队列中存的就都是长度为digits的所有可能字符
 * 时间复杂度：最好：O(n)，最坏：O(4^n)
 * 空间复杂度：最好：O(n)，最坏：O(4^n)
 */ 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> result;
        if (len <= 0) return result;
        vector<string> mapping({"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        queue<string> q({""});
        for (int i = 0; i < len; i++) {
            while(true) {
                string prefix = q.front();
                if (prefix.size() == i+1) break; // 很关键，当原本长度为i的字符串都出队列了，跳出循环
                for (char e: mapping[digits[i] - '0']) {
                    q.push(prefix + e);
                }
                q.pop();
            }
        }
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};


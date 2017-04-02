/*! Source: https://leetcode.com/problems/generate-parentheses
 *! Author: qwchen
 *! Date  : 2017-04-02
 *  打印n对括号的所有有效组合
 */


/*
 * 思路：
 *   通过递推发现规律：
 *   n = 2: (())  ()()
 *   n = 3: (()())  ((()))  ()(())  (())()  ()()()
 *   可以对于n，只需要在n-1的组合中每个字符串最前面和以及原有没对括号里面插入一对括号。
 *   至于插入其他任意位置，比如字符串的末尾，都会跟之前的情况重复。
 *   使用hash来避免重复
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        unordered_set<string> pairs = generate(n);
        for (string pair: pairs) {
            res.push_back(pair);
        }
        return res;
    }
    
private:
    unordered_set<string> generate(int n) {
        unordered_set<string> pairs;
        if (n == 1) {
            pairs.insert("()");
        }
        else {
            unordered_set<string> subPairs = generate(n-1);
            for (string pair: subPairs) {
                for (int i = 0; i < pair.size(); i++) {
                    if (pair[i] == '(') {
                        pairs.insert(insertPair(pair, i+1));
                    }
                }
                pairs.insert("()" + pair);
            }
        }
        return pairs;
    }
    
    // 将括号插入到s[0, leftSize-1] 与 s[leftSize: s.size()-1]之间
    string insertPair(string s, int leftSize) {
        return s.substr(0, leftSize) + "()" + s.substr(leftSize, s.size());
    }
};


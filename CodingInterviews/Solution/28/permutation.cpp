/*! Author: qwchen
 *! Date  : 2016-11-20
 *  28. 字符串排列
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/** 
 * 回溯法：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/mian-shi-ti-38-zi-fu-chuan-de-pai-lie-hui-su-fa-by/
 */
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }

private:
    vector<string> res;
    void dfs(string s, int x) {
        if (x == s.size() - 1) {
            res.push_back(s);
            return;
        }
        set<char> st;
        for (int i = x; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            swap(s[x], s[i]);
            dfs(s, x+1);
            swap(s[x], s[i]);
        } 
    }
};

/* 
 * 就是一个全排列问题
 * 递归方程：A(n) = n * A(n-1)
 * 此题要求排列结果去重，在此调用了STL的unique算法进行去重
 */
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.size() == 0) {
            return result;
        }
        Permutation(str, 0, str.size() - 1, result);
        sort(result.begin(), result.end());
        auto new_end = unique(result.begin(), result.end());
        result.erase(new_end, result.end());
        return result;
    }

private:
    void Permutation(string& str, int k, int n, vector<string>& result) {
        if (k == n) {
            result.push_back(str);
            return;
        }
        for (int i = k; i <= n; i++) {
            swap(str[i], str[k]);
            Permutation(str, k + 1, n, result);
            swap(str[i], str[k]);
        }
    }
};

void testSolution() {
    string a = "abc";
    string b = "bb";
    Solution sol;
    vector<string> aPerm = sol.Permutation(a);
    for (string s: aPerm) {
        cout << s << " ";
    }
    cout << endl;
    vector<string> bPerm = sol.Permutation(b);
    for (string s: bPerm) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}


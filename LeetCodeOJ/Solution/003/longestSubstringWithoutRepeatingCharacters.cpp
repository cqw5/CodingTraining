/*! Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *! Author: qwchen
 *! Date  : 2016-10-31
 * Solution 为该文件最优的方案
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
 * 使用一个滑动窗口来保持没有重复字符的子串
 * 时间复杂度：O(n)
 * 空间复杂度：O(min(m, n))
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;  // 滑动窗口
        int maxLength = 0;
        int i = 0, j = 0; // i是滑动窗口的最后端，j是滑动窗口的最前端的前一位。
        int n = s.size();
        while(i < n && j < n){
            if (set.find(s[j]) == set.end()){ // 窗口中不存在s[j]
                set.insert(s[j++]);
                maxLength = max(maxLength, j - i);
            } else { // 窗口中存在s[j]
                set.erase(s[i++]);
            }
        }
        return maxLength;
    }
};

void testSolution(){
    string s = "abcabcbb";
    Solution solution;
    int length = solution.lengthOfLongestSubstring(s);
    cout << s << endl;
    cout << length << endl;
}

int main(){
    testSolution();
    return 0;
}

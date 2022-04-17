/*! Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *! Author: qwchen
 *! Date  : 2016-10-31
 * Solution 为该文件最优的方案
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#include <iostream>

using namespace std;

/*
 * 思路：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/mian-shi-ti-48-zui-chang-bu-han-zhong-fu-zi-fu-d-9/
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 0) return 0;
        vector<int> dp(s.size(), 0);
        unordered_map<int, int> map;
        dp[0] = 1;
        map[s[0]] = 0;
        for (int i = 1; i < s.size(); i++) {
            if(map.find(s[i]) == map.end()) {
                dp[i] = dp[i-1] + 1;
            } else {
                int j = map[s[i]];
                if (j > i-1 - dp[i-1]) {
                    dp[i] = i - j;
                } else {
                    dp[i] = dp[i-1] + 1;
                }
            }
            map[s[i]] = i;
        }
        int maxlen = 0;
        for (int x: dp) {
            if (x > maxlen) maxlen = x;
        }
        return maxlen;
    }
};
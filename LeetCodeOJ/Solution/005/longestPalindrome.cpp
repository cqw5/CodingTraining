/*! Source: https://leetcode.com/problems/longest-palindromic-substring
 *! Author: qwchen
 *! Date  : 2016-7-14
 *  最长回文子串
 *    寻找一串字符串的最长回文子串
 *    Input: "babad"  Output: "bab"
 *    Input: "cbbd"  Output: "bb"
 */

/*
 * 思路：
 *   对字符串的每一个元素，寻找其左右元素是否对称，从而确定以当前字符串为中点的字符串的回文长度。
 * 时间复杂度：O(N^2). beats 79.65 % of cpp submissions.
 * 空间复杂度：O(K). 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int i = 0, low = 0, high = 0;
        int maxLen = 0;
        while(i < s.size()) {
        	// 如果从当前元素起到字符串结束的长度都小于等于当前已获得的最长回文的一般，那么从以当前元素为中点的字符串肯定不是最长回文了
            if(s.size() - i <= maxLen / 2) break;  
            int left = i, right = i;
            // 如果存在一段连续的重复元素，那这段重复元素肯定是回文，那么把这段重复元素放到回文中间，然后从起左右两边开始寻找
            while(right < s.size() - 1 && s[right] == s[right+1]) right++;
            i = right + 1;
            while(left > 0 && right < s.size() - 1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if(right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                low = left;
                high = right;
            }
        }
        return s.substr(low, maxLen);
    }
};
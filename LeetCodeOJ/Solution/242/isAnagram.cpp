/*! Source: https://leetcode.com/problems/valid-anagram
 *! Author: qwchen
 *! Date  : 2017-04-14
 *  相同字母异序词
 *    给定两个字符串，判断这两个字符串是不是相同字母异序词
 */

/*
 * 思路：
 *   考虑到字符串中只有小写字母，可以用一个长度为26的数组表示字符串中的每一个数。
 *   遇到第一个字符串中的每一个字母，让数组中的该字母对应的元素值+1
 *   遇到第二个字符串中的每一个字母，让数组中的该字母对应的元素值-1
 *   最后判断该数组是否每个元素的值都为0，若是返回true；一个不是返回false
 * 时间复杂度：O(n). 9 ms. beats 77.17% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> hashTable(26, 0);
        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i] - 'a']++;
            hashTable[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hashTable[i]) return false;
        }
        return true;
    }
};

/*
 * 思路：
 *   同上，只是不用vector，而用传统的数组
 * 时间复杂度：O(n). 13 ms. beats 63.30% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hashTable[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i] - 'a']++;
            hashTable[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hashTable[i]) return false;
        }
        return true;
    }
};


/*
 * 思路：
 *   将两个字符串排序，在判断排序后的结果是否相同
 * 时间复杂度：O(nlogn). 26 ms. beats 13.40% of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


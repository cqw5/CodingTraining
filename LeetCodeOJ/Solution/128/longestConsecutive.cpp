/*! Source: https://leetcode-cn.com/problems/longest-consecutive-sequence/
 *! Author: qwchen
 *! Date  : 2022-04-18
 *  最长连续序列
 */

/*
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> set;
        for (auto num: nums) {
            set.insert(num);
        }
        for (auto num: nums) {
            if (!set.count(num-1)) {
                int curLen = 1;
                while (set.count(++num)) {
                    curLen += 1;
                }
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
            }
        }
        return maxLen;
    }
};
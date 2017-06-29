/*! Source: https://leetcode.com/problems/contains-duplicate
 *! Author: qwchen
 *! Date  : 2017-03-29
 *  判断数组中是否存在重复原始
 */

/* 
 * 思路：
 *   借助一个集合来保存数组中的原始
 * 时间复杂度：O(n). beats 43.85 % of cpp submissions
 * 空间复杂度：O(n)
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num: nums) {
            if (set.find(num) != set.end()) return true;
            set.insert(num);
        }
        return false;
    }
};

/*
 *
 * 时间复杂度：O(n). 32ms. beats 88.09 % of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};


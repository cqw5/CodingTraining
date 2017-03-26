/*! Source: https://leetcode.com/problems/intersection-of-two-arrays
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  两个集合的交集1
 *  要求结果去重
 */

/*
 * 思路：
 *   用一个set存放第一个集合。
 *   对于第二个集合的每一个元素：
 *     如果该元素在set中，说明这是两个集合都有的元素，保存下来，同时从set中删除该元素，防止后续被重复保存
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m)
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_set<int> set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (set.find(nums2[i]) != set.end()) {
                res.push_back(nums2[i]);
                set.erase(nums2[i]);
            }
        }
        return res;
    }
};
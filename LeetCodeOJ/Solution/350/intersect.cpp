/*! Source: https://leetcode.com/problems/intersection-of-two-arrays-ii
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  两个集合的交集2
 *  要求结果不去重
 *    Input : [1] [1,1]         Output: [1]
 *    Input : [1,1,1] [1,1]     Output: [1,1]
 */

/*
 * 思路：
 *   用一个hash表存放第一个集合，value为每个元素的计数。
 *   对于第二个集合的每一个元素：
 *     如果该元素在hash表中，并且元素的计算大于0，说明这是两个集合都有的元素，保存下来，同时让计数值减一
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m)
 */

Input : [1] [1,1]
Output: [1]


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums1.size(); i++) {
            mapping[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if ((mapping.find(nums2[i]) != mapping.end()) && mapping[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                mapping[nums2[i]]--;
            }
        }
        return res;
    }
};
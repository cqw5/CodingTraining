/*! Source: https://leetcode.com/problems/subsets-ii
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  集合的子集II
 *    与前面集合的子集的题目相比，该题的原始集合有重复元素
 */

/*
 * 思路：
 *   用n个数{a1,a2,...,ai,...,an-1,an}，每个数可以在或者不在子集中，总共有2^n中可能.
 *   但是在这种情况下，有了重复元素，因此需要考虑重复元素。
 *   先将数组排序，这样重复元素就被连在一块，为了防止重复元素被重复考虑，将重复元素一块处理。
 *   如：
 *   已有res = {{} {a1}},现在nums有3个重复元素a2 {a2, a2, a2}
 *   那么应该是res中每个元素加上{a2} {a2, a2} {a2, a2, a2}
 * 时间复杂度：O(2^m). m为不重复元素的个数. 9 ms. beats 28.97 % of cpp submissions.
 * 空间复杂度：O(2^m)
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int len = res.size();
            int count = 1; // 当前重复元素的个数
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
                count++;
            }
            for (int j = 0; j < len; j++) {
                vector<int> subSet(res[j]);
                // 加上重复元素的组合
                for (int k = 0; k < count; k++) {
                    subSet.push_back(nums[i]);
                    res.push_back(subSet);
                }
            }
        }
        return res;
    }
};


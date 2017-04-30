/*! Source: https://leetcode.com/problems/subsets
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  集合的子集
 */

/*
 * 思路：
 *   用n个数{a1,a2,...,ai,...,an-1,an}，每个数可以在或者不在子集中，总共有2^n中可能
 *   n-1个数的所有子集是n个数的所有子集中an没出现的情况的子集。即：P(n) = P(n-1) + P(n-1) * an
 *   如：
 *   n=0: {}
 *   n=1: {} {a1}
 *   n=2: {} {a1}  {a2} {a1 a2}
 *   n=3: {} {a1}  {a2} {a1 a2}    {a3} {a1 a3} {a2 a3} {a1 a2 a3}
 * 时间复杂度：O(2^n). 6 ms. beats 27.15 % of cpp submissions.
 * 空间复杂度：O(2^n)
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}}; // 初始化为空集
        for (int i = 0; i < nums.size(); i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                vector<int> subSet(res[j]);
                subSet.push_back(nums[i]);
                res.push_back(subSet);
            }
        }
        return res;
    }
};


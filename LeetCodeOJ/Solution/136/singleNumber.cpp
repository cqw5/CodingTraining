/*! Source: https://leetcode.com/problems/single-number/
 *! Author: qwchen
 *! Date  : 2016-12-08
 * Solution 为该文件最优的方案
 */

/*
 * 思路：
 *   由于任何数与自己异或结果为0，任何数与0异或结果不变。而数组中只有一个数出现1次，其他数都是成对出现。
 *   如果将数组所有元素异或的话，那么结果中所有成对出现的数都会抵消，剩下的结果刚好就是那个只出现一次的数。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
    }
};


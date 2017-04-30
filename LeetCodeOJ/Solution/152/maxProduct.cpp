/*! Source: https://leetcode.com/problems/maximum-product-subarray
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  最大连乘子数组
 *    给定一个数组，返回其最大连乘子数组的值。
 *    如：A = [2,3,-2,4], 最大连乘子数组为[2,3], 乘积为6
 */

/*
 * 思路：
 *   注意到，一串连乘中：有奇数个负数时，值最小；有偶数个负数时，值最大。
 *   对于每一个数，需要保存连乘到当前的最大值和最小值。
 *   当乘上一个负数时，最小值会变成最大值，最大值会变成最小值，因此在乘上一个负数前，要将最大值和最小值交换。
 * 时间复杂度：O(n). 6 ms. beats 15.55 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = nums[0];
        for (int i = 1, iMax = nums[0], iMin = nums[0]; i < nums.size(); i++) {
            if (nums[i] < 0) swap(iMax, iMin);
            iMax = max(nums[i], nums[i] * iMax);
            iMin = min(nums[i], nums[i] * iMin);
            res = max(res, iMax);
        }
        return res;
    }
};


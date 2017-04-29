/*! Source: https://leetcode.com/problems/next-permutation
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  下一个排序数组
 */

/*
 * 思路：
 *   1.从最后一个元素开始，反向搜索找到nums[i]<nums[i+1]的元素i，那么此时nums[i+1,n-1]就是非递增有序的。
 *   2.从最后一个元素开始，反向搜索找到第一个nums[k]>nums[i]，然后swap(nums[i],nums[k])。
 *   3.为了使结果最小，将非递增有序的数组nums[i+1,n-1]逆序，使得其变成非递减有序。
 * 时间复杂度：O(n). 9 ms. beats 88.78 % of cpp submissions
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i+1]) break;
            i--;
        }
        if (i < 0) {
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
        int k = nums.size() - 1;
        for (; k > i; k--) {
            if (nums[k] > nums[i]) break;
        }
        swap(nums[i], nums[k]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};


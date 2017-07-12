/*! Source: https://leetcode.com/problems/rotate-array
 *! Author: qwchen
 *! Date  : 2016-7-13
 *  旋转数组
 *  将数组向右旋转K位
 */

/*
 * 思路：
 *   见《剑指Offer》42题
 * 时间复杂度：O(N). beats 54.29 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        int mid = n - 1 - k;
        reverse(nums, 0, mid);
        reverse(nums, mid+1, n-1);
        reverse(nums, 0, n-1);
    }
    
    void reverse(vector<int>& nums, int low, int high) {
        while(low < high) {
            swap(nums[low++], nums[high--]);
        }
    }
};
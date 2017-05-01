/*! Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
 *! Author: qwchen
 *! Date  : 2017-04-13
 *  旋转数组中的最小元素
 *    假设数组中没有重复元素
 */

/*
 * 时间复杂度：O(logn)]. 3 ms. beats 37.40 % of cpp submissions.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid+1];
            else if (nums[mid] <= nums[high]) high = mid;
            else                              low = mid + 1; // nums[mid] >= nums[low]
        }
        return nums[low];
    }
};


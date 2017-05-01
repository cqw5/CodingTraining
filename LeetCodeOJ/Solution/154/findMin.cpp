/*! Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
 *! Author: qwchen
 *! Date  : 2017-04-13
 *  旋转数组中的最小元素
 *    假设数组中有重复元素
 */

/*
 * 时间复杂度：O(n), 6 ms. beats 37.40 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) return find(nums);
            else if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if (nums[mid] <= nums[high])   high = mid;
            else                                low = mid + 1; // nums[mid] >= nums[low]
        }
        return nums[low];
    }
    
    int find(vector<int>& nums) {
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[index]) {
                index = i;
            }
        }
        return nums[index];
    }
};


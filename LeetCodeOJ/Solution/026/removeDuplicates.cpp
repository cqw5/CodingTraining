/*! Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  删除数组的重复元素
 */

/*
 * 思路：
 *   用两个指针，i是慢指针，j是快指针(走在前面)
 *   如果nums[i] == nums[j]，则该nums[j]需要被删除，就只移动j++
 *   如果nums[i] != nums[j]，则该nums[j]需要被保留，另nums[++i] = nums[j]，然后再移动j++
 * 时间复杂度：O(n). 29 ms. beats 53.63 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int i = 0, j = 1;
        for (; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};


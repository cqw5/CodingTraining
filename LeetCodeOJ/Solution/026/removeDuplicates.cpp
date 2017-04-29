/*! Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *! Author: qwchen
 *! Date  : 2016-12-27
 *  删除数组的重复元素
 */

/*
 * 思路：
 *   如果元素重复，用后面的元素替换它
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
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};


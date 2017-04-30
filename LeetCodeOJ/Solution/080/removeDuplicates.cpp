/*! Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  删除排序数组的重复元素II
 */

/*
 * 思路：
 *   用两个指针，i是慢指针，j是快指针(走在前面)
 *   用flag来标记是否第一次重复：如果flag==false，表示第一次重复；如果flag==true，表示第二次重复
 *   如果nums[i] == nums[j] && flag == false ，第一次重复，则该nums[j]需要被删除，就只移动j++，
 *       但是flag标记为true，让后续再出现就表示第二次重复了。
 *   如果nums[i] != nums[j]，则该nums[j]需要被保留，另nums[++i] = nums[j]，然后再移动j++
 *       还有flag还原为false
 * 时间复杂度：O(n). 16 ms. beats 27.19 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int i = 0, j = 1;
        bool flag = false;
        for (; j < nums.size(); j++) {
            if (nums[i] == nums[j] && flag == false) {
                nums[++i] = nums[j];
                flag = true;
            }
            else if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
                flag = false;
            }
        }
        return i + 1;
    }
};


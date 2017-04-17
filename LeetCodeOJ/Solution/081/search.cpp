/*! Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii
 *! Author: qwchen
 *! Date  : 2017-04-17
 *  有重复的旋转数组的二分查找
 */

/*
 * 思路：
 *   不需要找到数组的最小元素，然后再分开查找。
 *   直接进行二分查找：
 *     如果nums[mid] == target, 那么当前的mid就是了。
 *     如果nums[mid] > nums[high]. 说明mid落到旋转数组整体比较大的那一边。
 *       如果nums[low] <= target < nums[mid], 那么target就应该在nums[low: mid)之间，另high=mid-1
 *       否则，target就应该在nums(mid, high], 另low=mid+1
 *     如果nums[mid] < nums[high]. 说明mid落到寻找数组整体比较小的那一边。
 *       如果nums[mid] < target <= nums[high], 那么target就应该在nums(mid, high]之间，另low=mid+1
 *       否则，target就应该在nums[low:mid), 另high=mid-1
 *     如果nums[mid] == high，没法直接判断，另high--，重新计算
 * 时间复杂度：O(logn)，最坏情况O(n). 9 ms. beats 13.05% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
            else {
                high--;
            }
        }
        return nums[low] == target;
    }
};


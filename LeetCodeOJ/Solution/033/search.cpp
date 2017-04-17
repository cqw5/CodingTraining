/*! Source: https://leetcode.com/problems/search-in-rotated-sorted-array
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  旋转数组的二分查找
 */

/*
 * 思路：
 *   先找到旋转数组的最小元素，以最小元素为界，旋转数组就可以分为两段，分别有序，并且左半段每个元素都大于右半段
 *   如果target >  旋转数组最后元素，那么target在左半段，对左半段进行二分查找
 *   如果target <= 旋转数组最后元素，那么target在右半段，对右半段进行二分查找
 * 时间复杂度：O(logn). 12 ms.  beats 5.44% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        int firstIndex = getFirstIndex(nums);
        if (target == nums[firstIndex])  return firstIndex;
        else if (target > nums.back())   return binarySearch(nums, 0, firstIndex-1, target);
        else                             return binarySearch(nums, firstIndex+1, nums.size() - 1, target);
    }
    
    int getFirstIndex(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid+1])    return mid + 1;
            if (nums[mid] < nums[high])     high = mid;
            else if (nums[mid] > nums[low]) low = mid + 1;
        }
        return low;
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid =  (low + high) / 2;
            if (target > nums[mid])      low = mid + 1;
            else if (target < nums[mid]) high = mid - 1;
            else                         return mid;
        }
        return -1;
    }
};

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
 *     不存在重复元素，不会出现nums[mid] == nums[high]的情况
 * 时间复杂度：O(logn). 16 ms. beats 1.06% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        if (nums[low] == target) {
            return low;
        }
        else {
            return -1;
        }
    }
};


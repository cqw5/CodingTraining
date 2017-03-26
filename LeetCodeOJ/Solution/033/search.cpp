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
 * 时间复杂度：O(logn)
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
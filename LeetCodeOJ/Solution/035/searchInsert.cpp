/*! Source: https://leetcode.com/problems/search-insert-position/
 *! Author: qwchen
 *! Date  : 2016-12-10
 * Solution 为该文件最优的方案
 */

/*
 * 思路：
 *   二叉查找，如果数组中存在元素target，会返回target的下标，不存在target，那么low指针指向的位置就是第一个大于targer的元素的位置
 * 时间复杂度：O(logn)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || target < nums[0]) {
            return 0;
        }
        if (target > nums.back()) {
            return nums.size();
        }
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            } 
            else {
                break;
            }
        }
        if (low <= high) {
            return mid;
        }
        else {
            return low;
        }
    }
};


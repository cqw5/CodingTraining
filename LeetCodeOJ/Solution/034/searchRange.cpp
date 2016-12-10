/*! Source: https://leetcode.com/problems/search-for-a-range/
 *! Author: qwchen
 *! Date  : 2016-12-10
 *  假设target有k个重复元素
 *  Solution1的时间复杂度为O(logn + k)
 *  Solution2的时间复杂度为O(2logn)
 */

/*
 * 思路：
 *   进行二分查找，找到一个等于target的元素，顺序遍历该元素左右的元素，寻找其左右与其相同的元素
 */
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.size() == 0 || target < nums[0] || target > nums.back()) {
            return result;
        }
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(low <= high) {
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
            int i = 0;
            for (i = 0; mid-i >= 0 && nums[mid-i] == target; i++);
            result[0] = mid-i+1;
            for (i = 0; mid+i < nums.size() && nums[mid+i] == target; i++);
            result[1] = mid+i-1;
        }
        return result;
    }
};


/*
 * 思路：
 *   进行两遍二分查找，第一步查找第一个等于target的元素，第二步查找第二个等于target的元素
 */
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.size() == 0 || target < nums[0] || target > nums.back()) {
            return result;
        }
        int low = 0;
        int high = nums.size() - 1;
        // 查找第一个等于target的元素的下标
        while (low < high) {
            int mid = (low + high) / 2;  // 当数组长度为偶数时，中位数为前半段的最后一个元素
            if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        if (nums[low] != target) {
            return result;
        }
        result[0] = low;
        high = nums.size() - 1;
        // 查找最后一个等于target的元素的下标
        while (low < high) {
            int mid = (low + high + 1) / 2;  // 当数组长度为偶数时，中位数为后半段的第一个元素
            if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid;
            }
        }
        result[1] = high;
        return result;
    }
};


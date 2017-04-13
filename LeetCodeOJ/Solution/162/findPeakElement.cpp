/*! Source: https://leetcode.com/problems/find-peak-element
 *! Author: qwchen
 *! Date  : 2017-04-13
 *  寻找峰值
 *    给定一个数组，寻找一个大于其左右邻居的数。假定第一个元素大于其前面的数，最后一个元素大于其后面的数。nums[i]!=nums[i+1]
 *    有多个峰值，随机返回一个即可。
 */

/*
 * 思路：
 *   使用二分查找
 *   如果nums[mid] < nums[mid+1]，则nums[mid+1: high]之间肯定有峰值。即使是递增的，那么也可以是nums[high]
 *   如果nums[mid] > nums[mid+1]，则nums[low: mid+1]之间肯定有峰值。即使是递减的，那么也可以是num[low]
 * 时间复杂度：O(n). 6 ms. beats 16.47% of cpp submissions.
 * 空间复杂度：O(1) 
 */
class Solution {
public:
    int findPeakElement(const vector<int> &nums) {
        if (nums.size() <= 1) return 0;
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) high = mid;
            else if (nums[mid] < nums[mid + 1]) low = mid + 1;
        }
        return low;
    }
};

/*
 *
 * 时间复杂度：O(n). 6 ms. beats 16.47% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return nums.size() - 1;
    }
};


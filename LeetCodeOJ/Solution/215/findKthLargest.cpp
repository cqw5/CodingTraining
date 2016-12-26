/*! Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
 *! Author: qwchen
 *! Date  : 2016-12-26
 *  数组中第k大的数
 */

/*
 * 思路：
 *   此题和寻找数组中第k小的元素的思路相同，同样借助快速排序的partition函数
 *   不过此题是寻找第k大的元素，因此partition中是对数组从大到小排序
 *   另外k的下标是从1开始，数组的下标是从0开始，这个需要注意
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = partition(nums, low, high);
            if (mid < k)      low = mid + 1;
            else if (mid > k) high = mid - 1;
            else              break;
        }
        return nums[k];
    }
    
private:
    int partition(vector<int>& nums, int low, int high) {
        int key = nums[low];
        while (low < high) {
            while (low < high && nums[high] <= key) high--;
            nums[low] = nums[high];
            while (low < high && nums[low] >= key) low++;
            nums[high] = nums[low];
        }
        nums[low] = key;
        return low;
    }
};


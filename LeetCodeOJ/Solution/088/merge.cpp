/*! Source: https://leetcode.com/problems/merge-sorted-array
 *! Author: qwchen
 *! Date  : 2017-04-13
 *  合并两个排序数组
 */

/*
 * 思路：
 *   用一个指针m指向nums1的最后一个元素；用一个指针n指向nums2的最后一个元素
 *   从后往前合并两个数组的元素到第一个数组
 *   如果m先<0，nums2中剩下元素小于m中最小元素，将nums2中剩下的元素放到nums1前面剩余的位置
 *   如果n先<0，nums1中剩下的元素直接放在原本的位置即可
 * 时间复杂度：O(n) 3 ms. beats 63.33% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[last--] = nums1[m--];
            }
            else {
                nums1[last--] = nums2[n--];
            }
        }
        while (n >= 0) {
            nums1[last--] = nums2[n--];
        }
    }
};


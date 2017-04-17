/*! Source: https://leetcode.com/problems/find-the-duplicate-number
 *! Author: qwchen
 *! Date  : 2017-04-17
 *  寻找数组中的重复元素
 *  给定一个长度为n+1的数组，其中元素的值在1~n之间，至少存在一个重复元素。
 *  要求：
 *    1.不能修改数组
 *    2.空间复杂度为O(1)
 *    3.时间复杂度必须小于O(n^2)
 *    4.数组中只有一个重复元素，重复的次数可能为1次，也可能为多次
 */

/*
 * 思路：
 *   数据的范围是1~n，数组的长度是n+1
 *   将数组划分为[low, mid][mid+1, high]两部分，然后统计<=mid的元素的个数count。
 *   如果count<=mid，说明<=mid的元素中没有重复；那么重复元素就落在[mid+1,high]之间了，另low=mid+1
 *   如果count>mid，说明<=mid的元素中有重复；即重复元素落在[low, mid]之间，另high=mid
 * 时间复杂度：O(nlogn). 12 ms. beats 58.17% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) count++;
            }
            if (count <= mid) low = mid + 1;
            else              high = mid;
        }
        return low;
    }
};


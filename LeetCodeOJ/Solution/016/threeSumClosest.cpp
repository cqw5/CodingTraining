/*! Source: https://leetcode.com/problems/3sum-closest
 *! Author: qwchen
 *! Date  : 2017-4-29
 *  最接近某个数的3数之和
 */

/*
 * 思路：
 *   类似与3Sum的解法
 *   先对数组排序
 *   然后从头到尾对于数组中的每一个元素，从其后用夹逼法找到两个元素，使得这3个数的和离target最近
 * 时间复杂度：O(n^2). 9 ms. beats 48.86 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int lastSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int curSum = nums[i] + nums[front] + nums[back];
                if (abs(curSum - target) < abs(lastSum - target)) {
                    lastSum = curSum;
                }
                if (curSum < target) front++;
                else if (curSum > target) back--;
                else return target;
            }
            if (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return lastSum;
    }
};


/*! Source: https://leetcode-cn.com/problems/move-zeroes/
 *! Author: qwchen
 *! Date  : 2017-04-19
 *  移动零
 */

/*
 * 思路：
 *   将0元素移到数组后面，反过来就是将非0元素移到数组前面
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

/*! Source: https://leetcode.com/problems/majority-element
 *! Author: qwchen
 *! Date  : 2017-04-01
 *  数组中出现次数超过一半的数
 */

/* 
 * 时间复杂度：O(m)
 * 空间复杂度：O(1)
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (major == nums[i]) count++;
            else                  count--;
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
        }
        return major;
    }
};
/*! Source: https://leetcode.com/problems/minimum-size-subarray-sum
 *! Author: qwchen
 *! Date  : 2017-04-26
 *  长度最短的子数组
 *    给定一个数组nums和一个数s，找到一个长度最短且值大于等于s的子数组，不存在这样的子数组时，返回0
 */

/*
 * 思路：
 *   滑动窗口法
 * 时间复杂度：O(n). 19 ms. beats 13.26 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums[0] >= s) return 1;
        int minLen = INT_MAX;
        int sum = nums[0];
        for(int p1 = 0, p2 = 0; p2 < nums.size();){
            if (sum >= s) {
                minLen = min(minLen, p2 - p1 + 1);
                sum -= nums[p1];
                p1++;
            }
            else {
                p2++;
                if (p2 < nums.size()) {
                    sum += nums[p2];
                }
            }
        }
        if (minLen == INT_MAX) return 0;
        else                   return minLen;
    }
};


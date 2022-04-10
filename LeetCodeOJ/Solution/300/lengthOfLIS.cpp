/*! Source: https://leetcode-cn.com/problems/longest-increasing-subsequence
 *! Author: qwchen
 *! Date  : 2022-03-09
 *  最长递增子序列
 *  给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *  子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 */

/*
 * 思路：
 *   https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};


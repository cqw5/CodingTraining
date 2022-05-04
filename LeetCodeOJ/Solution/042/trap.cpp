/*! Source: https://leetcode-cn.com/problems/trapping-rain-water/
 *! Author: qwchen
 *! Date  : 2022-05-04
 *  接雨水
 */

/*
 * 思路：动态规划
 *   对于下标 i，下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值，下标 i 处能接的雨水量等于下标 i 处的水能到达的最大高度减去 height[i]。
 *   创建两个长度为 n 的数组 leftMax 和 rightMax。
 *   对于 0≤i<n，leftMax[i] 表示下标 i及其左边的位置中，height 的最大高度；rightMax[i] 表示下标 i 及其右边的位置中，height 的最大高度。
 *   在得到数组 leftMax 和 rightMax 的每个元素值之后，对于 0≤i<n，下标 i 处能接的雨水量等于 min(leftMax[i],rightMax[i])−height[i]。遍历每个下标位置即可得到能接的雨水总量。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if (n <= 0) return ans;
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        for (int i = 0; i < n; i++) {
            ans += max(min(leftMax[i], rightMax[i]), height[i]) - height[i]; 
        }
        return ans;
    }
};


/*
 * 思路：双指针 https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};


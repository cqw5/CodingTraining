/*! Source: https://leetcode-cn.com/problems/sqrtx/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  x 的平方根 
 */


/*
 * 思路：
 *   二分查找
 * 时间复杂度：O(logx)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};


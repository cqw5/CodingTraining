/*! Source: https://leetcode-cn.com/problems/longest-turbulent-subarray/
 *! Author: qwchen
 *! Date  : 2022-04-25
 *  最长湍流子数组
 */

/**
 * 滑动窗口：https://leetcode-cn.com/problems/longest-turbulent-subarray/solution/zui-chang-tuan-liu-zi-shu-zu-by-leetcode-t4d8/
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ret = 1;
        int left = 0, right = 0;
        while (right < n-1) {
            if (left == right) {
                if (arr[left] == arr[left+1]) {
                    left++;
                }
                right++;
            } else {
                if (arr[right-1] < arr[right] && arr[right] > arr[right+1]) {
                    right++;
                } else if (arr[right-1] > arr[right] && arr[right] < arr[right+1]) {
                    right++;
                }
                else {
                    left = right;
                }
            }
            ret = max(ret, right-left+1);
        }
        return ret;
    }
};
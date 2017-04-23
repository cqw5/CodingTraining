/*! Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  排序数组的两数之和
 */

/*
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res = {0, 0};
        if (numbers.size() <= 0) return res;
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] < target) low++;
            else if (numbers[low] + numbers[high] > target) high--;
            else {
                res[0] = low + 1;
                res[1] = high + 1;
                return res;
            }
        }
        return res;
    }
};


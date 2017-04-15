/*! Source: https://leetcode.com/problems/plus-one
 *! Author: qwchen
 *! Date  : 2017-04-15
 *  Plus One
 *  加1
 *  将一个非负整数表示为一个数组，数组每个元素的值为0~9；让该数的值+1
 */

/*
 * 思路：
 *   从数组后往前，如果当前元素==9，则变为0，进位1；否则，当前元素+1，并返回。
 * 时间复杂度：O(n). 3 ms. beats 20.24% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


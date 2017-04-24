/*! Source: https://leetcode.com/problems/valid-perfect-square
 *! Author: qwchen
 *! Date  : 2017-04-23
 *  数能否开根号
 */

/*
 * 思路：
 *   使用二分查找，查找平方等于num的数
 *   要注意两个比较大的int类型的数相加或相乘会溢出，因此要使用long long类型
 * 时间复杂度：O(logn). 3 ms. beats 9.29% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        long long mid, midSquare;
        while (low <= high) {
            mid = (low + high) / 2;
            midSquare = mid * mid;
            if (midSquare == num)     return true;
            else if (midSquare > num) high = mid - 1;
            else                      low = mid + 1;
        }
        return false;
    }
};


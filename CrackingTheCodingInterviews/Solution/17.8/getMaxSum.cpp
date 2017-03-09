/*! Author: qwchen
 *! Date  : 2017-03-09
 *! 贪心/动态规划：17.8 最大连续数列和
 *! 题目描述：
 *    对于一个有正有负的整数数组，请找出总和最大的连续数列。
 * 给定一个int数组A和数组大小n，请返回最大的连续数列的和。保证n的大小小于等于3000。
 */

class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};


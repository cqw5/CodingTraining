/*! Source: https://leetcode.com/problems/maximum-subarray/
 *! Author: qwchen
 *! Date  : 2016-11-12
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * 用动态规划来求解
 * 对于每一个nums[i]，sum都表示到当前nums[i]的最大连续子数组大小
 * 此题如果需要求最长子数组的序列，还有用一个长度为n的数组保存下来每一个sum
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n;i++){
            sum += nums[i];
            if (sum > ans){
                ans = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};

void testSolution(){
    vector<int> array = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << sol.maxSubArray(array) << endl;
}

int main(){
    testSolution();
    return 0;
}
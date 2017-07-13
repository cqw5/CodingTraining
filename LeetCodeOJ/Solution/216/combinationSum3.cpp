/*! Source: https://leetcode.com/problems/combination-sum-iii
 *! Author: qwchen
 *! Date  : 2016-7-13
 *  k个数之和等于n的所有组合
 *  给定一个数组：[1,2,3,4,5,6,7,8,9],求所有k个数之和等于n的组合
 */

/*
 * 思路：
 *   这道题的解法类似于暴力解法，只是通过递归来实现。
 * 时间复杂度：O(9^k). beats 3.77 % of cpp submissions.
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sum;
        combination(res, sum, k, n);
        return res;
    }
    
    void combination(vector<vector<int>>& res, vector<int>& sum, int k, int n) {
        if(sum.size() == k && n == 0) {
            res.push_back(sum);
        }
        else if(sum.size() < k) {
            for(int i = sum.empty()? 1: sum.back() + 1; i <= 9; i++) {
                if (i > n) break;
                sum.push_back(i);
                combination(res, sum, k, n-i);
                sum.pop_back();
            }
        }
    }
};


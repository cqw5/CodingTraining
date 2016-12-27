/*! Source: https://leetcode.com/problems/combination-sum/
 *! Author: qwchen
 *! Date  : 2016-12-27
 *  给定一个不重复的数组C和一个数T，在C中寻找所有的唯一组合，使得其值为T，组合中可以选择重复元素
 */

/*
 * 思路：
 *   先将数组排序
 *   然后从头到尾遍历数组的每一个数，对于当前的数C[i]，从其后寻找k个数(可以包括当前数)，使其总和等于T。
 *   然而后面寻找k个数的问题又可以转化为从其后寻找k-1个数，使其和等于T-C[i]的问题，变成一个递归的问题。
 * 时间复杂度：O(n^n) n为C中小于k的元素的个数
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
    
private:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};


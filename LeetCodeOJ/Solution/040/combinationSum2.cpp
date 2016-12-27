/*! Source: https://leetcode.com/problems/combination-sum-ii/
 *! Author: qwchen
 *! Date  : 2016-12-27
 *  给定一个有重复的数组C和一个数T，在C中寻找所有的唯一组合，使得其值为T，一个组合中同一个元素只能被选中一次
 */

/*
 * 思路：
 *   先将数组排序
 *   然后从头到尾遍历数组的每一个数，对于当前的数C[i]，从其后寻找k个数，使其总和等于T。
 *   然而后面寻找k个数的问题又可以转化为从其后寻找k-1个数，使其和等于T-C[i]的问题，变成一个递归的问题。
 *   因为数组存在重复元素，而要求所有组合不重复，因此如果从一个组合中退出一个元素，如下一个要放入组合的元素刚好等于刚退出的元素，
 *   那下一个元素就不需要放入组合中，因为其放入后产生的组合和是前一个相同元素产生的组合的子集。
 * 时间复杂度：O(n^n) n为C中小于k的元素的个数
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
    
private:
    void combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
            combination.push_back(candidates[i]);
            // 相对于39题，只改进了下面两行
            combinationSum2(candidates, target - candidates[i], res, combination, i+1);
            while (i + 1 < candidates.size() && combination.back() == candidates[i+1]) i++;  // 去除重复的核心
            combination.pop_back();
        }
    }
};

